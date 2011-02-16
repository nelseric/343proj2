all:
	gcc *.c -o infix
debug:
	gcc *.c -ggdb -o infix
clean:
	rm infix
