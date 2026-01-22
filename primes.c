// primes.c
// Řešení IJC-DU1, příklad a), 3.3.2024
// Autor: Mikuláš Lešiga, FIT
// Přeloženo: gcc 10.2
// ...popis příkladu - poznámky, omezení, atd

#include <stdio.h>
#include "bitset.h"
#include "eratosthenes.h"
#include "time.h"

#define size 666000000
#define VYPIS 10

int main() {
    //Start the time
    clock_t start = clock();
    // Make bitset
    bitset_create(bitset, size);
    // Mark primes
    Eratosthenes(bitset);
    // Prepare the last 10 prime numbers
    bitset_index_t primes[VYPIS];
    bitset_index_t count = 0;
    for (bitset_index_t  i = size-1; count < VYPIS; i--) {
        if (bitset_getbit(bitset, i) == 1) {
            primes[count++] = i;
        }
    }
    // Print the last 10 prime numbers
    for (int i = VYPIS-1; i >= 0; i--) {
        printf("%ld\n", primes[i]);
    }
    // Print time
    fprintf(stderr, "Time=%.3g\n", (double)(clock() - start) / CLOCKS_PER_SEC);
    return 0;
}