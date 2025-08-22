#ifndef VECTOR_H
#define VECTOR_H

typedef struct Vector Vector;  //  Definición opaca

Vector* vector_create(void);
void vector_destroy(Vector* v);
void vector_push_back(Vector* v, int value);
int vector_pop_back(Vector* v);
int vector_get(Vector* v, int index);
void vector_set(Vector* v, int index, int value);
int vector_size(Vector* v);
int vector_capacity(Vector* v);

#endif