#
# SPDX-License-Identifier: GPL-3.0-or-later
#
# Copyright (C) 2018, Harshit Jain
#

# Issue 1 file size
CFLAGS="-DGET_FILE_SIZE -Wall"

CC ?= gcc
CLANG_FORMAT ?= clang-format
OPT_LEVEL ?= -O2

default: transfer

transfer.o: transfer.c
	$(CC) $(CFLAGS) $(OPT_LEVEL) -c transfer.c -o transfer.o

transfer: transfer.o
	$(CC) $(CFLAGS) transfer.o -o transfer
	-rm -f transfer.o

clean:
	-rm -f transfer.o
	-rm -f transfer

clang-format:
	@$(CLANG_FORMAT) -style='{IndentWidth: 4}' transfer.c > formatted.c
	@-mv formatted.c transfer.c

install: transfer
	sudo mv transfer /usr/local/bin/
	@echo "\033[01;33mNow you can use transfer binary with command line"
	@echo "Example: transfer myfile.txt\033[0m"
