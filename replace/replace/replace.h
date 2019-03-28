/*
 *  replace.h
 */

#ifndef __REPLACE_H
#define __REPLACE_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>

#define FREE_SLOT -1

// the page frame list
typedef struct frame {
    int pageNumber;
    struct frame *over;
    struct frame *under;
} FRAME;

int testLRU(int, int[], int);
void insertLRU(int);
FRAME *searchLRU(int);
void displayLRU(void);
void freePageTableLRU(void);

int testOPT(int, int[], int);
int searchOPT(int);
void insertOPT(int);
int findVictimPageOPT();
void displayOPT();
void freePageTableOPT(void);

#endif // __REPLACE_H
