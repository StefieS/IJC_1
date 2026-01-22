# Makefile
# Řešení IJC-DU1, příklad a), 3.3.2024
# Autor: Mikuláš Lešiga, FIT
# Přeloženo: gcc 10.2
# ...popis příkladu - poznámky, omezení, atd

CC= gcc
CFLAGS= -O2 -g -std=c11 -pedantic -Wall -Wextra
LDLIBS= -lm

.PHONY : all run zip clean

all: primes primes-i no-comment

# Macros
eratosthenes.o: eratosthenes.c eratosthenes.h bitset.h error.h
error.o: error.c error.h
primes.o: primes.c bitset.h error.h eratosthenes.h
bitset.o: bitset.c bitset.h error.h


# Inline
primes-i.o: primes.c eratosthenes.h bitset.h error.h
	$(CC) $(CFLAGS) -DUSE_INLINE -c primes.c -o primes-i.o
eratosthenes-i.o: eratosthenes.c eratosthenes.h bitset.h error.h
	$(CC) $(CFLAGS) -DUSE_INLINE -c eratosthenes.c -o eratosthenes-i.o
bitset-i.o: bitset.c bitset.h error.h
	$(CC) $(CFLAGS) -DUSE_INLINE -c bitset.c -o bitset-i.o

# No-comment
no-comment.o: no-comment.c error.h

# Final executables
primes: primes.o eratosthenes.o error.o bitset.o
	$(CC) $(CFLAGS) $^ -o $@ $(LDLIBS)

primes-i: primes-i.o eratosthenes-i.o error.o bitset-i.o
	$(CC) -DUSE_INLINE $(CFLAGS) $^ -o $@ $(LDLIBS)

no-comment: no-comment.o error.o
	$(CC) $(CFLAGS) $^ -o $@ $(LDLIBS)

# run
run: primes primes-i
	ulimit -s 82000 && ./primes
	ulimit -s 82000 && ./primes-i

# zip
zip: 
	zip xlesigm00.zip *.c *.h Makefile 

# Clean
clean:
	rm -f *.o *.zip primes primes-i no-comment