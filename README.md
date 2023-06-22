# Example C++ License Validation

This is an example C++ program for validating a license key. It contains a
small command line program which prompts for a license key value and then
validates the key using Keygen's cloud software licensing API.

## Running the example

First up, add an environment variable containing your account ID:
```bash
# Your Keygen account ID (via https://app.keygen.sh/settings)
export KEYGEN_ACCOUNT_ID="YOUR_KEYGEN_ACCOUNT_ID"
```

You can either run each line above within your terminal session before
starting the app, or you can add the above contents to your `~/.bashrc`
file and then run `source ~/.bashrc` after saving the file.

First up, install [C++ REST SDK](https://github.com/Microsoft/cpprestsdk)
and Boost. Also, make sure OpenSSL is installed (it typically is).

Using Homebrew:

```bash
brew install cpprestsdk
brew install boost
```

Using Apt:

```bash
sudo apt-get install libcpprest-dev
sudo apt-get install libboost-all-dev
```

Next, compile the source using `g++`:

```bash
g++ main.cpp -o bin.out -std=c++17 \
  -lcpprest \
  -lboost_system \
  -lboost_thread \
  -lboost_chrono \
  -lssl \
  -lcrypto \
  -pthread
```

Then run the script, passing in a `key` as the first argument:

```bash
./bin.out '<key>'
```

Or run this demo script:

```bash
KEYGEN_ACCOUNT_ID=demo ./bin.out C1B6DE-39A6E3-DE1529-8559A0-4AF593-V3
```

## Running on other platforms

We are only including instructions on how to compile and run this example on
macOS and Linux. If you'd like to create a PR with instructions for another
platform, such as Windows, please feel free to open a PR.

## Questions?

Reach out at [support@keygen.sh](mailto:support@keygen.sh) if you have any
questions or concerns!
