#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <cpprest/http_client.h>
#include <cpprest/filestream.h>
#include <cpprest/base_uri.h>

using namespace std;
using namespace web;
using namespace web::http;
using namespace web::http::client;
using namespace web::json;
using namespace utility;

// Verify a license key using the validate-key action
pplx::task<http_response> validate_license_key(http_client client, const string license_key)
{
  http_request req;

  value meta;
  meta[utility::conversions::to_string_t("key")] = value::string(utility::conversions::to_string_t(license_key));

  value body;
  body[utility::conversions::to_string_t("meta")] = meta;

  req.headers().add(utility::conversions::to_string_t("Content-Type"), utility::conversions::to_string_t("application/vnd.api+json"));
  req.headers().add(utility::conversions::to_string_t("Accept"), utility::conversions::to_string_t("application/json"));

  req.set_request_uri(uri(utility::conversions::to_string_t("/licenses/actions/validate-key")));
  req.set_method(methods::POST);
  req.set_body(body.serialize());

  return client.request(req);
}

// Usage:
// 1. Change KEYGEN_ACCOUNT_ID to your personal value
// 2. Call the compiled file with a valid licence key
int main(int argc, char* argv[])
{
  if (argc == 1)
  {
    cerr << "[ERROR] "
         << "No license key argument specified"
         << endl;

    exit(1);
  }

  string account_id = getenv("KEYGEN_ACCOUNT_ID");
  string license_key = argv[1];
  http_client client(uri(utility::conversions::to_string_t("https://api.keygen.sh/v1/accounts/") + utility::conversions::to_string_t(account_id)));

  validate_license_key(client, license_key)
    .then([](http_response res)
    {
      auto json = res.extract_json().get();
      if (json.has_field(utility::conversions::to_string_t("errors")))
      {
        auto errors = json.at(utility::conversions::to_string_t("errors")).as_array();
        auto err = errors[0];

        cerr << "[ERROR] "
             << "API request failed: "
             << "status=" << res.status_code() << " "
             << "title='" << err.at(utility::conversions::to_string_t("title")).as_string().c_str() << "' "
             << "detail='" << err.at(utility::conversions::to_string_t("detail")).as_string().c_str() << "'"
             << endl;

        exit(1);
      }

      auto data = json.at(utility::conversions::to_string_t("data"));
      auto meta = json.at(utility::conversions::to_string_t("meta"));

      if (meta.at(utility::conversions::to_string_t("valid")).as_bool())
      {
        cout << "[OK] "
             << "License key is valid: "
             << "code=" << meta.at(utility::conversions::to_string_t("code")).as_string().c_str() << " "
             << "id=" << data.at(utility::conversions::to_string_t("id")).as_string().c_str()
             << endl;
      }
      else
      {
        cerr << "[ERROR] "
             << "License key is not valid: "
             << "code=" << meta.at(utility::conversions::to_string_t("code")).as_string().c_str()
             << endl;
      }
    })
    .wait();
}
