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

static int resize(Vector* v);

Vector* vector_create(){
    Vector* newVector = (Vector*)malloc(sizeof(Vector));
    if(newVector != NULL){    
        newVector->elements = (VECTOR_ELEMENT*)calloc(DEFAULT_MAX_SIZE, sizeof(VECTOR_ELEMENT));
        if(newVector->elements != NULL){
            newVector->size = 0;
            newVector->maxSize = 10;
        }
    }
    return newVector;
}

void vector_destroy(Vector* v){
    free(v->elements);
    free(v);
}

int vector_get(Vector* v, int index){
    VECTOR_ELEMENT value = VECTOR_ELEMENT_DEFAULT;
    if(index < v->size && index >= 0){
        value = v->elements[index];
    }
    return value;
}

void vector_set(Vector* v, int index, int value){
    if(index < v->size && index >= 0){
        v->elements[index] = value;
    }
}

static int resize(Vector* v){
    int done = 0;
    v->elements = (VECTOR_ELEMENT*)realloc(v->elements, sizeof(VECTOR_ELEMENT)*v->size*2);
    if(v->elements != NULL){
        done = 1;
    }
    return done;
}
void vector_push_back(Vector* v, int value){
    if(v != NULL){
        if(v->size >= v->maxSize){ //aumentar capacidad del vector al doble de su capacidad
            if(resize(v) == 0){
                return; 
            }
        }
        v->elements[v->size] = value;
        v->size++;
    }
}
int vector_pop_back(Vector* v){
    VECTOR_ELEMENT value = VECTOR_ELEMENT_DEFAULT;
    if(v != NULL){
        if(v->size != 0){
            v->size--;
            value = v->elements[v->size];
            v->elements[v->size] = VECTOR_ELEMENT_DEFAULT;
        }
    }
    return value;
}

int vector_size(Vector* v){
    return v->size;
}
int vector_capacity(Vector* v){
    return v->maxSize;
}
