#ifndef DYNAMIC_ARRAY_H
#define DYNAMIC_ARRAY_H

#include <stdlib.h>
#include <stdbool.h>
#include "errors.h"

#define MAX_CAPACITY 1024

typedef struct DynamicArray
{
	int* array;
	size_t size;
	size_t capacity;
} dynamic_array_t;

// Initialization/Deinitialization
enum ds_error init_dynamic_array(dynamic_array_t* arr);
void free_dynamic_array(dynamic_array_t* arr);

// Access functions
enum ds_error at(dynamic_array_t* arr, int* var, int index);
void front(dynamic_array_t* arr, int* val);
void back(dynamic_array_t* arr, int* val);

// Capacity/size functions
static enum ds_error increase_size(dynamic_array_t* arr);
bool empty(dynamic_array_t* arr);
size_t size(dynamic_array_t* arr);
size_t max_size(dynamic_array_t* arr);
size_t capacity(dynamic_array_t* arr);

// Modifiers
void clear(dynamic_array_t* arr);
void insert(dynamic_array_t* arr, int val, int i);
void push_back(dynamic_array_t* arr, int val);
int pop_back(dynamic_array_t* arr);

#endif
