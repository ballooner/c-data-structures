#ifndef DYNAMIC_ARRAY_H
#define DYNAMIC_ARRAY_H

#include <stdlib.h>
#include <stdbool.h>
#include "errors.h"

#define MAX_CAPACITY 1024
#define DEFAULT_CAPACITY 1

typedef struct DynamicArray
{
	int* array;
	size_t size;
	size_t capacity;
} dynamic_array_t;

// Initialization/Deinitialization
dynamic_array_t* init_dynamic_array(void);
dynamic_array_t* init_size_dynamic_array(size_t size);
void free_dynamic_array(dynamic_array_t* arr);

// Access functions
enum ds_error at(dynamic_array_t* arr, int* var, int index);

// Capacity/size functions
static enum ds_error increase_size(dynamic_array_t* arr);
bool empty(dynamic_array_t* arr);
size_t capacity(dynamic_array_t* arr);

// Modifiers
enum ds_error clear(dynamic_array_t* arr);
enum ds_error insert(dynamic_array_t* arr, int val, int index);
enum ds_error push_back(dynamic_array_t* arr, int val);
int pop_back(dynamic_array_t* arr);

#endif
