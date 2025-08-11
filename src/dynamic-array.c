#include "dynamic-array.h"
#include "errors.h"

// Initialization/Deinitialization
dynamic_array_t* init_dynamic_array(void)
{
	dynamic_array_t* arr = malloc(sizeof(dynamic_array_t));

	arr->size = 0;
	arr->capacity = 1;
	arr->array = malloc(sizeof(int) * arr->capacity);

	return arr;
}

void free_dynamic_array(dynamic_array_t* arr)
{
	free(arr->array);
	free(arr);
}

// Access functions
int at(dynamic_array_t* arr, int index)
{
	if (index > (int)arr->capacity)
	{
		return -1;
	}

	return arr->array[index];
}

int front(dynamic_array_t* arr)
{
	return arr->array[0];
}

int back(dynamic_array_t* arr)
{
	return arr->array[arr->size - 1];
}

// Capacity/size functions
static enum ds_error increase_size(dynamic_array_t* arr)
{
	if (arr->capacity == MAX_CAPACITY)
	{
		return DS_ERR_OUT_OF_MEMORY;
	}

	arr->capacity *= 2;
	
	int *newArray = realloc(arr->array, sizeof(int) * arr->capacity);
	if (!newArray)
	{
		return DS_ERR_ALLOC_FAIL;
	}
	arr->array = newArray;

	return DS_OK;
}

bool empty(dynamic_array_t* arr);
size_t size(dynamic_array_t* arr);
size_t max_size(dynamic_array_t* arr);
size_t capacity(dynamic_array_t* arr);

// Modifiers
void clear(dynamic_array_t* arr);
void insert(dynamic_array_t* arr, int val, int i);
void push_back(dynamic_array_t* arr, int val);
int pop_back(dynamic_array_t* arr);
