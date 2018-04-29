/**
 * helpers.c
 *
 * Helper functions for Problem Set 3.
 */

#include <cs50.h>

#include "helpers.h"

/**
 * Returns true if value is in array of n values, else false.
 */
bool search(int value, int values[], int n)
{
    if(binary_search(0, n, value, values) == value){
        return 1;
    }
    else
        return 0;
}
/**
 * Binary search implementation
*/

int binary_search(int start, int end, int value, int values[]){
    static int middle = 1;

    if(end<start){
        return 0;
    }
    else{
        middle = (start+end)/2;
        if(value < values[middle]){
            binary_search(start, middle-1, value, values);
        }
        else if(value > values[middle]){
            binary_search(middle+1, end, value, values);
        }
        else
            return values[middle];
    }
    return values[middle];
}

/**
 * Sorts array of n values in bubble sort.
 */
void sort(int values[], int n)
{
    int k = 1;
    while(k != 0){
        k = 0;
        for(int i =0; i < n-1; i++){
            if(values[i]>values[i+1]){
                int temp = values[i];
                values[i] = values[i+1];
                values[i+1] = temp;
                k++;
            }
        }
    }
}
