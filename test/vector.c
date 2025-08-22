#include <stdio.h>
#include <stdlib.h>
#include "vector.h"

#define VECTOR_ELEMENT int
#define VECTOR_ELEMENT_DEFAULT 0
#define DEFAULT_MAX_SIZE 10

// Funciones del vector
struct Vector{
    VECTOR_ELEMENT* elements;
    int size; 
    int maxSize;
};

Vector* vector_create(){
    Vector* newVector = (Vector*)malloc(sizeof(Vector));
    newVector->elements = (VECTOR_ELEMENT*)calloc(DEFAULT_MAX_SIZE, sizeof(VECTOR_ELEMENT));
    newVector->size = 0;
    newVector->maxSize = 10;
    return newVector;
}

void vector_destroy(Vector* v){
    free(v->elements);
    free(v);
}

int vector_get(Vector* v, int index){
    VECTOR_ELEMENT value = v->elements[index];
    (v->elements)[index] = VECTOR_ELEMENT_DEFAULT;
    return value;
}

void vector_set(Vector* v, int index, int value){
    v->elements[index] = value;
}

void vector_push_back(Vector* v, int value){
    if(v->size >= v->maxSize){ //aumentar capacidad del vector al doble de su capacidad
        v->elements = (VECTOR_ELEMENT*)realloc(v->elements, sizeof(VECTOR_ELEMENT)*v->size*2);
    }
    v->elements[v->size] = value;
    v->size++;
}
int vector_pop_back(Vector* v){
    VECTOR_ELEMENT value = VECTOR_ELEMENT_DEFAULT;
    if(v->size != 0){
        v->size--;
        value = v->elements[v->size];
        v->elements[v->size] = VECTOR_ELEMENT_DEFAULT;
    }
    return value;
}

int vector_size(Vector* v){
    return v->size;
}
int vector_capacity(Vector* v){
    return v->maxSize;
}
