# Example C++ License Validation
This is an example C++ program for validating a license key. It contains a
small command line program which prompts for a license key value and then
validates the key using Keygen's cloud software licensing API.

## Running the example on MacOS

First up, add an environment variable containing your account ID:
```bash
# Your Keygen account ID
export KEYGEN_ACCOUNT_ID="YOUR_KEYGEN_ACCOUNT_ID"
```

You can either run each line above within your terminal session before
starting the app, or you can add the above contents to your `~/.bashrc`
file and then run `source ~/.bashrc` after saving the file.

First up, install [`cpprestsdk`](https://github.com/Microsoft/cpprestsdk) using `homebrew`.
```bash
brew install cpprestsdk
```

Next, install OpenSSL v1.0.2p using `homebrew`.
```bash
brew install openssl@1.0.2
```

Next, compile the source using `g++`:
```bash
g++ main.cpp -o bin.out \
  -std=c++17 \
  -stdlib=libc++ \
  -lcpprest \
  -lboost_system \
  -lboost_thread-mt \
  -lboost_chrono-mt \
  -lssl \
  -lcrypto \
  -I/usr/local/opt/openssl/include \
  -L/usr/local/opt/openssl/lib \
  -I/usr/local/opt/cpprestsdk/include \
  -L/usr/local/opt/cpprestsdk/lib
```

Then run the script, passing in a `key` as the first argument:
```bash
./bin.out "{KEYGEN_LICENSE_KEY}"
```

## Running on Ubuntu

First up, add an environment variable containing your account ID:
```bash
# Your Keygen account ID
export KEYGEN_ACCOUNT_ID="YOUR_KEYGEN_ACCOUNT_ID"
```

First up, install [`cpprestsdk`](https://github.com/Microsoft/cpprestsdk) using `apt`.
```bash
sudo apt install libcpprest-dev
```

Next, install OpenSSL using `apt`.
```bash
sudo apt install libssl-dev
```

Next, compile the source using `cmake`:
```bash
cmake -B build . && cmake --build build
```

Then run the script, passing in a `key` as the first argument:
```bash
./build/main "{KEYGEN_LICENSE_KEY}"
```

## Running on other platforms

We are only including instructions on how to compile and run this example on
macOS. If you'd like to create a PR with instructions for another platform,
such as Windows or Linux, please feel free to open a PR.

## Questions?

Reach out at [support@keygen.sh](mailto:support@keygen.sh) if you have any
questions or concerns!
