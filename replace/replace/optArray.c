/**
 * This implements the LRU page-replacement algorithm.
 */

#include "replace.h"

int *referenceString;
int refStringLength;

// the page frame list
int *pageTable;
int numOfpages;

int victimIndex;
int hitIndex;

// statistics
int optNumOfFaults = 0;

// this is the sequence of pages to serve
int currentIndex;

int testOPT(int numOfpages, int *refString, int refStrLen)
{
    // TODO: implement

    return optNumOfFaults;
}

/*
 *	try to insert a page into the page table
 */
void insertOPT(int pageNumber)
{
    int searchVal = searchOPT(pageNumber);

    pageTable[searchVal] = pageNumber;
}

/*
 *  find either an empty slot, or the page, or a vitim to evict
 */
int searchOPT(int pageNumber)
{
    // TODO: implement

    return findVictimPageOPT();
}

int findVictimPageOPT()
{
    // TODO: implement
    return 0;
}

void displayOPT()
{
    // todo: implement
}

void freePageTableOPT()
{
    // TODO: implement
}
