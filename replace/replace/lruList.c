/**
 * This implements the LRU page-replacement algorithm.
 */

#include "replace.h"

FRAME *pageTableTop;
int pageTableSize = 0;
FRAME *leastRecentlyUsed;

int numOfFrames = 0;

// statistics
int numOfFaults = 0;

int hitIndex;

/*
 * insert pages from a reference string into a page table and measure
 * the page fault rate
 */
int testLRU(int numOfFrames, int *refString, int refStrLen)
{
    // TODO: implement

    return 0;
}

/*
 *	try to insert a page into the page table
 */
void insertLRU(int pageNumber)
{
    // TODO: implement
}

/**
 * Searches for page pageNumber in the page frame list
 * returns NULL if a frame with pageNumber was not found
 * otherwise, returns a reference to the frame with pageNumber
 */
FRAME *searchLRU(int pageNumber)
{
    // TODO: implement

    return NULL;
}

void displayLRU()
{
    // TODO: implement
}

void freePageTableLRU()
{
    // TODO: implement
}

