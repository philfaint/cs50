#include <stdio.h>
#include <stdlib.h>

struct car{
    char brand[20];
    int year;
    int odometer;
    char color[20];
};

int main(void){

    int n;
    printf("How many cars do you want to record?");
    scanf("%i", &n);

    struct car *cars=malloc(n*sizeof(struct car));

    for(int i =0; i<n;i++){
        scanf("%s", cars[i].brand);
        scanf("%i", &(cars[i].year));
        scanf("%i", &(cars[i].odometer));
        scanf("%s", cars[i].color);
    }

    FILE *file = fopen("cars.csv", "w");
    if(file ==NULL){
        return 1;
    }

    for(int i = 0; i<2; i++){
        fprintf(file, "%s, %i, %i, %s\n", cars[i].brand, cars[i].year, cars[i].odometer, cars[i].color);
    }
    fclose(file);
    free(cars);
    return 0;
}