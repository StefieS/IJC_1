// no-comment.c
// Řešení IJC-DU1, příklad a), 3.3.2024
// Autor: Mikuláš Lešiga, FIT
// Přeloženo: gcc 10.2
// ...popis příkladu - poznámky, omezení, atd

#include <stdio.h>
#include <stdlib.h>
#include "error.h"

#define MAX 2

int main (int argc, char *argv[]){

    if (argc > MAX){
        return 1;
    }
    FILE *fp;
    if (argc == 1){
        fp = stdin;
    }
    else{
        fp = fopen(argv[1], "r");
        if (fp == NULL) {
            error_exit("Cannot read the file");
        }
    }
    int stav = 0;
    int c;
    while ((c=fgetc(fp)) != EOF) {
        switch(stav) {
            case 0: 
                if(c=='/'){
                    stav=1;
                }
                else if (c=='"'){ 
                    stav=6;
                    putchar(c); 
                }
                else if (c =='\''){
                    stav=8;
                    putchar(c);
                }
                else{
                    putchar(c);
                }
                break;
            case 1: 
                if(c=='*'){
                    stav=2;
                }
                else if(c=='/'){
                    stav=4;
                }
                else { 
                    stav=0; 
                    putchar('/'); 
                    putchar(c); 
                }
                break;
            case 2: 
                if(c=='*'){
                    stav=3;
                }
                break;
            case 3: 
                if(c=='/'){ 
                    stav=0; 
                    putchar(' '); 
                }
                else if(c!='*'){
                    stav=2;
                }
                break;
            case 4: 
                if(c=='\\'){
                    stav=5;
                    }
                else if(c=='\n'){
                    stav=0;
                    putchar('\n');
                }
                break;
            case 5:
                if (c != '\\'){
                stav = 4;
                }
            break;
            case 6:
                if(c == '\\'){
                    stav=7;
                    putchar('\\');
                }
                else if (c == '"') {
                    stav=0;
                    putchar('"');
                }
                else {
                    putchar(c);
                }
                break;
            case 7:
                stav=6;
                putchar(c);
                break; 
            case 8:
                if (c =='\\'){
                    stav=9;
                    putchar('\\');
                }
                else if (c == '\'') {
                    stav=0;
                    putchar('\'');
                }
                else {
                    putchar(c);
                }
                break;
            case 9:
                stav=8;
                putchar(c);
                break;
            
        } // end switch
    } // end while
    if(stav !=0) {
        error_exit("Invalid input");
    }
    putchar('\n');
    fclose(fp);
}