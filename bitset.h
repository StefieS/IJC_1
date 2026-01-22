// bitset.h
// Řešení IJC-DU1, příklad a), 3.3.2024
// Autor: Mikuláš Lešiga, FIT
// Přeloženo: gcc 10.2
// ...popis příkladu - poznámky, omezení, atd

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>
#include "error.h"

#ifndef BITSET_H
#define BITSET_H

typedef unsigned long *bitset_t;
typedef unsigned long bitset_index_t;
#define ULONG_BIT (sizeof(bitset_index_t) * CHAR_BIT)


#define bitset_create(jmeno_pole, velikost ) \
    static_assert( velikost > 0 && velikost <= ULONG_MAX, "bitset_create: Chybná velikosť. \n" ); \
    bitset_index_t jmeno_pole[(( velikost / ULONG_BIT ) + ((( velikost % ULONG_BIT ) != 0) ? 1:0 )) + 1]={ velikost };

#define bitset_alloc(jmeno_pole, velikost)\
    assert((velikost) > 0 && (velikost) <= ULONG_MAX);\
    bitset_t jmeno_pole =calloc(((velikost) / (ULONG_BIT)+ ((( velikost % ULONG_BIT ) != 0) ? 1:0 )), sizeof(bitset_index_t)+1);\
    if (jmeno_pole == NULL) { \
        fprintf(stderr, "bitset_alloc: Chyba alokace paměti"); \
    } \
    jmeno_pole[0] = velikost
        
#ifdef USE_INLINE

inline void bitset_free(bitset_t jmeno_pole) {
    free(jmeno_pole);
}

inline bitset_index_t bitset_size(bitset_t jmeno_pole) {
    return jmeno_pole[0];

}
inline void bitset_fill(bitset_t jmeno_pole, bool bool_vyraz) {
  bitset_index_t fill = bool_vyraz ? ULONG_MAX : 0;
    for (bitset_index_t i=1;i<(bitset_size(jmeno_pole) / (ULONG_BIT) + ((bitset_size(jmeno_pole) % (ULONG_BIT) !=0) ? 1 : 0 )+1);i++) {
        jmeno_pole[i]=fill;
    }
}

inline void bitset_setbit(bitset_t jmeno_pole, bitset_index_t index, bool bool_vyraz) {
    if ((index) >= bitset_size(jmeno_pole)) 
     error_exit("bitset_getbit: Index %lu out of range 0..%lu", index, (bitset_size(jmeno_pole))); 
    if (bool_vyraz) {
        jmeno_pole[((index / ULONG_BIT)+1)] |= (1UL << (index % ULONG_BIT));
        }
    else {
        jmeno_pole[((index / ULONG_BIT)+1)] &= ~(1UL << (index % ULONG_BIT));
    }
}

inline bitset_index_t bitset_getbit(bitset_t jmeno_pole, bitset_index_t index) {
    if ((index) >= bitset_size(jmeno_pole)) {
       error_exit("bitset_getbit: Index %lu out of range 0..%lu", index, (bitset_size(jmeno_pole)));
    }
    return ((jmeno_pole[((index / ULONG_BIT)+1)] >> ((index) % ULONG_BIT)) & 1UL);
}

#else

#define bitset_free(jmeno_pole)\
(free(jmeno_pole))

#define bitset_size(jmeno_pole)\
(jmeno_pole[0])

#define bitset_fill(jmeno_pole,bool_vyraz)\
do { \
    bitset_index_t fill = bool_vyraz ? ULONG_MAX : 0;\
    for (bitset_index_t i=1;i<(bitset_size(jmeno_pole) / (ULONG_BIT) + ((bitset_size(jmeno_pole) % (ULONG_BIT) !=0) ? 1 : 0 )+1);i++) {\
       jmeno_pole[i]=fill; \
    }\
    } while (0);

#define bitset_setbit(jmeno_pole, index, bool_vyraz) \
do { \
    ((index) >= bitset_size(jmeno_pole)) ? \
    (error_exit("bitset_getbit: Index %lu out of range 0..%lu", (bitset_index_t)(index), (bitset_index_t)(bitset_size(jmeno_pole))), 0) \
    : (bool_vyraz) ? jmeno_pole[((index / ULONG_BIT)+1)] |= (1UL << (index % ULONG_BIT))\
    : (jmeno_pole[((index / ULONG_BIT)+1)] &= ~(1UL << (index % ULONG_BIT)));\
    } while (0);

#define bitset_getbit(jmeno_pole, index) \
    (((index) >= bitset_size(jmeno_pole)) ? \
        (error_exit("bitset_getbit: Index %lu out of range 0..%lu", (bitset_index_t)(index), (bitset_index_t)(bitset_size(jmeno_pole))), 0) \
        : ((jmeno_pole[((index / ULONG_BIT)+1)] >> ((index) % ULONG_BIT)) & 1UL))
#endif /* USE_INLINE */
#endif /* BITSET_H */