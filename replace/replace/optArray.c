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

int testOPT(int amountOfPages, int *refString, int refStrLen)
{
    // TODO: implement
    pageTable = malloc(sizeof(amountOfPages));
    refStringLength = refStrLen;
    referenceString = refString;
    numOfpages = amountOfPages;
    for(int i = 0; i < numOfpages; i++ )
    {
        pageTable[i] = FREE_SLOT;
        hitIndex = hitIndex+1;
        optNumOfFaults++;
    }

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

    for(int i = 0; i < pageNumber; i++)
    {
        if(pageTable[i] == FREE_SLOT )
        {
            return i;
        }
    }

    return findVictimPageOPT();
}

int findVictimPageOPT()
{
    // TODO: implement
    // Future
    int furthestAway = currentIndex;
    for(int i = 0; i < refStringLength; i++)
    {
        if(referenceString[victimIndex] < furthestAway )
            return i;
    }
    return 0;
}

void displayOPT()
{
    // TODO: implement
    FRAME frameTable;
    while(frameTable.pageNumber != NULL)
    {
        printf("********** %d ", frameTable);
    }

}

void freePageTableOPT()
{
    // TODO: implement

//    while(pageTable != NULL)
//    {
//
//    }

    free(pageTable);


}
