/*
 * Gabriel Espinosa
 * Lab/Task: Lab 8
 * 03/25/2019
 */

#include "inverted.h"

// "hidden" symbols (i.e., not included in the .h file)

int tableSize;
int frameSize;

int lookUp(PROC *, int, int);
int findOldest(PROC *table);

/*
 * initializes the table for the given sizes of the memory and frame
 * all entries should be zeroed (e.g., calloc())
 */
void initInverted(PROC **table, int msize, int fsize)
{
    // TODO: implement
//    this.tableSize = msize;
//    this.frameSize = fsize;
    tableSize = msize;
    frameSize = fsize;
    *table = calloc((size_t)tableSize, sizeof(PROC));
}


/*
 * translate a logical address <pid, page, offset> into a physical address
 * if there is no entry for the pid and the page number in the table, it has to be added
 * if there is no room in the table for the new entry, then the oldest entry has to be removed
 */
long translate(PROC *table, int pid, int page, int offset)
{
    // TODO: implement

    long entryLocation = lookUp(table,pid,page);
    if(entryLocation != -1)
    {
        table[entryLocation].timeStamp = time(NULL);
    }else {
        entryLocation = findOldest(table);
        table[entryLocation].pid = pid;
        table[entryLocation].page = page;
    }
    return entryLocation+offset;
}

//
// find the entry for a given pid and page
//
int lookUp(PROC *table, int pid, int page)
{
    // TODO: implement
    for(int i = 0; i < tableSize; i++)
    {
        if(table[i].pid == pid && table[i].page == page)
        {
            return i;
        }
    }
}

//
// find the oldest entry (or not used that has the timestamp == 0)
//
int findOldest(PROC *table)
{
    // TODO: implement

    int oldestEntry = 0;
    for(int i = 0; i < tableSize;i++ )
    {
        if(table[i].timeStamp < table[oldestEntry].timeStamp)
            oldestEntry = i;
    }
    return oldestEntry;
}
