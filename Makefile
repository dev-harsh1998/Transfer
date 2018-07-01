default: transfer

transfer.o: transfer.c
	gcc -c transfer.c -o transfer.o

transfer: transfer.o
	gcc transfer.o -o transfer
	-rm -f transfer.o

clean:
	-rm -f transfer.o
	-rm -f transfer
