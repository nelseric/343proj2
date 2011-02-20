all:
	gcc *.c -Wall -ggdb -lreadline -o infix
debug:
	gcc *.c -Wall -ggdb -lreadline -o infix
clean:
	rm infix
