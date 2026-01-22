// eratosthenes.c
// Řešení IJC-DU1, příklad a), 3.3.2024
// Autor: Mikuláš Lešiga, FIT
// Přeloženo: gcc 10.2
// ...popis příkladu - poznámky, omezení, atd

#include <math.h>
#include <stdio.h>
#include "bitset.h"

// Calculate prime numbers
void Eratosthenes(bitset_t bitset) {
    bitset_index_t size=bitset_size(bitset);
    bitset_index_t length=sqrt(size);
    // Fill everything with 1
    bitset_fill(bitset,true);
    // 0 and 1 are not primes
    bitset_setbit(bitset, 0, false);
    bitset_setbit(bitset, 1, false);

        for (bitset_index_t i = 2; i < length; i++) {
        if (bitset_getbit(bitset, i) == 1 ) {
            for (bitset_index_t n = i * i; n < size; n += i) {
                bitset_setbit(bitset, n, false);
            }
        }
    }
}