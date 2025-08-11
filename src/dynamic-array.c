#include "dynamic-array.h"
#include "errors.h"

// Initialization/Deinitialization
enum ds_error init_dynamic_array(dynamic_array_t* arr)
{
	arr = malloc(sizeof(dynamic_array_t));
	if (!arr)
	{
		return DS_ERR_ALLOC_FAIL;
	}

	arr->size = 0;
	arr->capacity = 1;
	int* tmp = malloc(sizeof(int) * arr->capacity);
	if (!tmp)
	{
		return DS_ERR_ALLOC_FAIL;
	}
	arr->array = tmp;

	return DS_OK;
}

void free_dynamic_array(dynamic_array_t* arr)
{
	free(arr->array);
	free(arr);
}

// Access functions
enum ds_error at(dynamic_array_t* arr, int* var, int index)
{
	if (index > (int)arr->capacity)
	{
		return DS_ERR_IOB;
	}

	*var = arr->array[index];
	return DS_OK;
}

void front(dynamic_array_t* arr, int* val)
{
	*val = arr->array[0];
}

void back(dynamic_array_t* arr, int* val)
{
	*val = arr->array[arr->size - 1];
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
