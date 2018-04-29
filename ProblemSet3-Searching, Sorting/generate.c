/**
 * generate.c
 *
 * Generates pseudorandom numbers in [0,MAX), one per line.
 *
 * Usage: generate n [s]
 *
 * where n is number of pseudorandom numbers to print
 * and s is an optional seed
 */

#define _XOPEN_SOURCE

#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// upper limit on range of integers that can be generated
#define LIMIT 65536

int main(int argc, string argv[])
{
    // check if user entered at least two or three command-line arguments
    if (argc != 2 && argc != 3)
    {
        printf("Usage: ./generate n [s]\n");
        return 1;
    }

    // initialize a variable n and set a value of command line argument turned into an int
    int n = atoi(argv[1]);

    // initialize internal buffer of drand48 with function srand48, with seed(if argc==3) or without it (using time(NULL))
    if (argc == 3)
    {
        srand48((long) atoi(argv[2]));
    }
    else
    {
        srand48((long) time(NULL));
    }

    // print pseudo-random number (n amount) using drand48 (returns double) multiplied by LIMIT
    for (int i = 0; i < n; i++)
    {
        printf("%i\n",  (int) (drand48()* LIMIT));
    }

    // success
    return 0;
}
