#include <stdio.h>

#include "vector.h"

int main()
{
    printf("Hello World");
    Vector* v = vector_create();
    vector_destroy(v);
    return 0;
}