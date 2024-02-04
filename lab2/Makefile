# comments in a Makefile start with sharp 

# all is a required target in every makefile
# target all means all targets currently defined in this file
all: lab2.zip bit_encode1 bit_encode2 

# this target is the .zip file that must be submitted to Carmen
# dependents are any file that you want to go in to the .zip
# so you pretty much duplicate the files on both lines
lab2.zip: Makefile bit_encode.c LAB2README
	zip lab2.zip Makefile bit_encode.c LAB2README

# this target is the bit cipher executable that does not prompt for data
bit_encode1: bit_encode1.o
	gcc bit_encode1.o -o bit_encode1

# this target is the dependency for bit_encode1
bit_encode1.o: bit_encode.c
	gcc -std=c99 -pedantic -D PROMPT -g -c -o bit_encode1.o bit_encode.c

# this target is the bit cipher executable that prompts for input from the keyboard
bit_encode2: bit_encode2.o
	gcc bit_encode2.o -o bit_encode2

# this target is the dependency for bit_encode2
# notice that this target's command uses -D PROMPT on the command line so that
# lines of code that prompt for keyboard data and print data out compile
bit_encode2.o: bit_encode.c
	gcc -std=c99 -pedantic -g -c -o bit_encode2.o bit_encode.c

# this target deletes all files produced from the Makefile
# so that a completely new compile of all items is required
clean:
	rm -rf *.o bit_encode1 bit_encode2 lab2.zip
