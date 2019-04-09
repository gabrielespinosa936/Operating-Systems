/*
 * Gabriel Espinosa
 * Lab/Task: Lab 09
 * April 1, 2019
 */

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
    numOfpages = amountOfPages;

    refStringLength = refStrLen;
    referenceString = refString;
    pageTable = (int* )malloc(numOfpages * sizeof(int));
    for(int i = 0; i < numOfpages; i++ )
    {
        pageTable[i] = FREE_SLOT;
    }//printf("HEYYY");

    for(int i = 0; i < refStringLength;i++)
    {
        currentIndex = i;
        insertOPT(referenceString[currentIndex]);
        hitIndex = -1;
        displayOPT();
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
    for(int i = 0; i < numOfpages; i++)
    {
        for(int j = 0; j < refStringLength; j++)
        {
            if(pageTable[i] == referenceString[j]) {
                victimIndex = i;
                //optNumOfFaults++;
            }
        }
    }optNumOfFaults++;
    return victimIndex;
}

void displayOPT()
{
    // TODO: implement

    printf("%d ->\t", referenceString[currentIndex]);
    for(int i = 0; i < numOfpages; i++)
    {
        printf("%d ", pageTable[i]);
        if(i==hitIndex)
            printf("<");
        if(i!=hitIndex &&  pageTable[i]== referenceString[currentIndex])
            printf("*");
        printf("\t");

    }printf("\n");


}

void freePageTableOPT()
{
    // TODO: implement


    free(pageTable);


}
