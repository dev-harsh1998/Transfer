# Transfer [![Codacy Badge](https://api.codacy.com/project/badge/Grade/edcd58027a3e412d90ce3cd98917d547)](https://app.codacy.com/app/dev-harsh1998/Transfer?utm_source=github.com&utm_medium=referral&utm_content=dev-harsh1998/Transfer&utm_campaign=Badge_Grade_Dashboard) [ ![Codeship Status for dev-harsh1998/Transfer](https://app.codeship.com/projects/6cfba370-60d1-0136-95b6-3296b091a39e/status?branch=master)](https://app.codeship.com/projects/296378)



Transfer is a command line utility built as a wrapper around cURL for one purpose - Uploading files to [transfer.sh](https://transfer.sh). It abstracts away all the manual cURL syntax to make usage effortless.
This utility even has the ability to upload multiple files with a single command or you can just use it to
upload one, Transfer can adapt to your fingers.

## How to use?

```
$ transfer myfile.file myflile2.flie ...
https://transfer.sh/t9a5Q/myfile.file
https://transfer.sh/ab069/myfile2.file
..
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
