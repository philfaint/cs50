#define _XOPEN_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct{
    int a;
    int b;
    int c;
    double d;
    long long e;
    unsigned f;
}numbers_t;

int main(void){
    srand48((long) time(NULL));

    numbers_t one;
    numbers_t two = {.a=2, .b=3, .c=4, .d=5.424, .e=3132131232131, .f=12312};
    numbers_t three = {1,2,3,5.423,324,23432};

    one.a = (int) (drand48()*50);
    one.b = (int) (drand48()*50);
    one.c = (int) (drand48()*50);
    scanf("%lf", &(one.d));
    scanf("%lld", &(one.e));

    unsigned *pr = &(one.f);
    *pr = (int) (drand48()*50);

    printf("%i, %i, %i, %lf, %lld, %u\n", one.a, one.b, one.c, one.d, one.e, one.f);
    printf("%i, %i, %i, %lf, %lld, %u\n", two.a, two.b, two.c, two.d, two.e, two.f);
    printf("%i, %i, %i, %lf, %lld, %u\n", three.a, three.b, three.c, three.d, three.e, three.f);
    //free(pr);
}
