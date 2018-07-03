# Transfer [ ![Codeship Status for dev-harsh1998/Transfer](https://app.codeship.com/projects/6cfba370-60d1-0136-95b6-3296b091a39e/status?branch=master)](https://app.codeship.com/projects/296378)

Transfer is a command line utility built as a wrapper around cURL for one purpose - Uploading files to [transfer.sh](https://transfer.sh). It abstracts away all the manual cURL syntax to make usage effortless.

## How to use?

```
$ transfer myfile.file
https://transfer.sh/t9a5Q/myfile.file
```

## Installation 
You can simply install transfer by following these instructions, make sure you have `git` and `curl` installed.

```
# Clone the repository.
git clone https://github.com/dev-harsh1998/Transfer
# Navigate to cloned directory.
cd Transfer
# Compile latest binary on your own machine!!.
make transfer
# Install it for direct access.
sudo make install
```

Additionally you can supply parameters to change the compiler and optimisation level, like `CC=clang OPT_LEVEL=-O3 make transfer`


BOOM! Easy right? There you are done you have successfully built and installed transfer on your machine.

## Supported Platforms
- Linux x86
- Linux x86_64
- macOS

## Issue or feature request?

Please write about issues and feature request [here](https://github.com/dev-harsh1998/Transfer/issues).
