#include <stdio.h>

#include "vector.h"

int main()
{
    Vector* v = vector_create();
    vector_push_back(v,1);
    vector_push_back(v,2);
    vector_push_back(v,3);
    int lastItem = vector_pop_back(v);
    vector_set(v,1,18);
    int number = vector_get(v,1);
    vector_destroy(v);
    return 0;
}