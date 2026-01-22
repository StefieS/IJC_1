// bitset.c
// Řešení IJC-DU1, příklad a), 3.3.2024
// Autor: Mikuláš Lešiga, FIT
// Přeloženo: gcc 10.2
// ...popis příkladu - poznámky, omezení, atd

#include "bitset.h"
#ifdef USE_INLINE
extern inline void bitset_free(bitset_t jmeno_pole);
extern inline bitset_index_t bitset_size(bitset_t jmeno_pole);
extern inline void bitset_fill(bitset_t jmeno_pole, bool bool_vyraz);
extern inline void bitset_setbit (bitset_t jmeno_pole, bitset_index_t index, bool bool_vyraz);
extern inline bitset_index_t bitset_getbit (bitset_t jmeno_pole, bitset_index_t index);
#endif