/**
 * helpers.c
 *
 * Computer Science 50
 * Problem Set 3
 *
 * Helper functions for Problem Set 3.
 *
 * Uses binary sort and a sorting method with O(n) 
 */
       
#include <cs50.h>
#include <stdio.h>

#include "helpers.h"

bool searchBin(int value, int values[], int min, int max);

/**
 * Returns true if value is in array of n values, else false.
 */
bool searchBin(int value, int values[], int min, int max)
{
    int divider = (max-min)/2 + min;
    
    if(values[divider] == value)
    {
        return true;
    }
    else if(min == max)
    {
        return false;
    }
    else if(values[divider] < value)
    {
        min = divider + 1;
        return searchBin(value, values, min, max);
    }
    else
    {
        max = divider - 1;
        return searchBin(value, values, min, max);
    }
}

bool search(int value, int values[], int n)
{
    return searchBin(value, values, 0, n-1);
}


/**
 * Sorts array of n values.
 */

// O(n) Sorting Method

void sort(int values[], int n)
{
    // find min and max number within the list of numbers
    int min = 65536;
    int max = 0;
    for(int i = 0; i <= (n-1); i++)
    {
        if(values[i] < min)
        {
            min = values[i];
        }
        
        if(values[i] > max)
        {
            max = values[i];
        }
    }
    
    // use new array "count" to keep track of the number of times each number 
    // shows up in the list
    int count[max];   
    for(int i = 0; i <= max; i++)
    {   
        count[i] = 0; 
    }  
    
    for(int i = 0; i <= (n-1); i++)
    {
        ++count[values[i]];
    }
    
    // recreate list in sorted order
    int t = 0;
    for(int i = min; i <= max; i++)
    {
        if(count[i] > 0)
        {
            for(int j = 0; j < count[i]; j++)
            {
                values[t] = i;
                t++;
            }
        }
    }
              
    return;
}
