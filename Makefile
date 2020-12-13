GCC = gcc              			                     # C compiler
CFLAGS = -g -Wall -Wextra -Wpedantic -Wshadow -O2    # Flags to test for errors.

all: dog

dog: dog.o
	$(GCC) dog.o -o dog $(CFLAGS) 

dog.o: dog.c
	$(GCC) -c dog.c $(CFLAGS)

clean:
	rm -f all

# Got most of this from Michael's Wednesday section
# and Clark's first section.

