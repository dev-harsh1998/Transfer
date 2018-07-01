#
# SPDX-License-Identifier: GPL-3.0-or-later
#
# Copyright (C) 2018, Harshit Jain
#

default: transfer

transfer.o: transfer.c
	gcc -c transfer.c -o transfer.o

transfer: transfer.o
	gcc transfer.o -o transfer
	-rm -f transfer.o

clean:
	-rm -f transfer.o
	-rm -f transfer

install:
	mv transfer /usr/bin/
	echo "Now you can use transfer binary with command line"
	echo "Example"
	echo "transfer myfile.txt"
