/*
 * Gabriel Espinosa
 * Lab/Task: Lab 09
 * April 1, 2019
 */


/**
 * This implements the LRU page-replacement algorithm.
 */

#include "replace.h"

FRAME *pageTableTop;
int pageTableSize = 0;
FRAME *leastRecentlyUsed;

int *referenceString;
int referenceStringLength;

int numberOfFrames = 0;

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
    pageTableTop = malloc(sizeof(numOfFrames));
    referenceString = refString;
    referenceStringLength = refStrLen;
    numberOfFrames = numOfFrames;
    for(int i = 0; i < numOfFrames;i++)
    {

    }

    return 0;
}

/*
 *	try to insert a page into the page table
 */
void insertLRU(int pageNumber)
{
    // TODO: implement.

   FRAME *searchVal = searchLRU(pageNumber);
   pageTableTop = searchVal->pageNumber;
   

}

/**
 * Searches for page pageNumber in the page frame list
 * returns NULL if a frame with pageNumber was not found
 * otherwise, returns a reference to the frame with pageNumber
 */
FRAME *searchLRU(int pageNumber)
{
    // TODO: implement

    FRAME *frameLists;
    while(frameLists!=NULL)
    {
        if(frameLists->pageNumber == pageNumber)
            return frameLists;
    }

    return NULL;
}

void displayLRU()
{
    // TODO: implement
}

void freePageTableLRU()
{
    // TODO: implement
    free(pageTableTop);
}

