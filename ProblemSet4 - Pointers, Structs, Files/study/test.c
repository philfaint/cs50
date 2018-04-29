#include <stdio.h>

typedef struct{
    char name[50];
    char surname[50];
    int campus;
} students_t;

int main(int argc, char* argv[]){

    if(argc != 2){
        return 1;
    }

    char *file = argv[1];

    FILE *file_p = fopen(file, "w");
    students_t students[2];


    for(int i =0; i <= 1; i++){
        scanf("%s %s %i", students[i].name, students[i].surname, &students[i].campus);
    }

    for(int i =0; i <= 1; i++){
        fprintf(file_p, "%s, ", students[i].name);
        fprintf(file_p, "%s, ", students[i].surname);
        fprintf(file_p, "%i, ", students[i].campus);
        fprintf(file_p, "\n");
    }

    fclose(file_p);
    return 0;
}