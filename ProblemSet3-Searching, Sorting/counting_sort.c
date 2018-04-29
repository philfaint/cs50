#define _XOPEN_SOURCE

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define LIMIT 30

void sort(int values[], int n);
_Bool search(int value, int values[], int n);
int binary_search(int start, int end, int value, int values[]);

int main(int argc, char* argv[]){

    if(argc != 2 && argc != 3){
        printf("Wrong usage!\n");
        return 1;
    }

    int size = atoi(argv[1]);
    int arr[size];
    int search_value;
    scanf("%i", &search_value);

    if(argc == 3){
        srand48((long) argv[2]);
    }
    else{
        srand48((long) time(NULL));
    }

    for(int i =0; i<size; i++){
       arr[i] = (int) (drand48() * LIMIT);
    }

    printf("Initial: ");
    for (int i =0; i<size; i++){
        printf("%i ", arr[i]);
    }

    printf("\n");

    sort(arr, size);

    printf("Sorted: ");
    for (int i =0; i<size; i++){
        printf("%i ", arr[i]);
    }

    printf("\n");
    printf("%i\n", search(search_value, arr, size-1));

    return 0;
}

void sort(int values[], int n){

    int arr[LIMIT] = {0};

    for(int i =0; i< n; i++){
        arr[values[i]]++;
    }

    int b = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j<arr[i]; j++){
            values[b] = i;
            b++;
        }
    }
}

_Bool search(int value, int values[], int n){
    if(binary_search(0, n, value, values) == value){
        return 1;
    }
    else
        return 0;
}

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