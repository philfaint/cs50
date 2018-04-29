/**
 * helpers.h
 *
 * Helper functions for Problem Set 3.
 */

#include <cs50.h>

/**
 * Returns true if value is in array of n values, else false.
 */
bool search(int value, int values[], int n);

/**
 * Sorts array of n values.
 */
void sort(int values[], int n);

/**
 * Helping binary search function, that contains
 * the algorithm
*/
int binary_search(int start, int end, int value, int values[]);