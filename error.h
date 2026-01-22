// error.h
// Řešení IJC-DU1, příklad a), 3.3.2024
// Autor: Mikuláš Lešiga, FIT
// Přeloženo: gcc 10.2
// ...popis příkladu - poznámky, omezení, atd

#ifndef ERROR_H
#define ERROR_H


void warning(const char *fmt, ...);
void error_exit(const char *fmt, ...);

#endif /* ERROR_H */