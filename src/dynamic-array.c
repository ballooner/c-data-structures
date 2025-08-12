#include "dynamic-array.h"
#include "errors.h"

// Initialization/Deinitialization
dynamic_array_t* init_dynamic_array(void)
{
	dynamic_array_t* arr = malloc(sizeof(dynamic_array_t));
	int* tmp = malloc(sizeof(int) * DEFAULT_CAPACITY);

	if (arr != NULL && tmp != NULL)
	{
		arr->size = 0;
		arr->capacity = DEFAULT_CAPACITY;
		arr->array = tmp;
	} else
	{
		if (tmp == NULL)
		{
			free(tmp);
		}

		if (arr == NULL)
		{
			free(arr);
		}
	}

	return arr;
}

void free_dynamic_array(dynamic_array_t* arr)
{
	if (arr != NULL)
	{
		free(arr->array);
		free(arr);
	}
}

// Access functions
enum ds_error at(dynamic_array_t* arr, int* var, int index)
{
	if (arr == NULL)
	{
		return DS_ERR_ARRAY_NULL;
	}

	if (index > (int)arr->capacity)
	{
		return DS_ERR_IOB;
	}

	*var = arr->array[index];
	return DS_OK;
}

// Capacity/size functions
static enum ds_error increase_size(dynamic_array_t* arr)
{
	if (arr == NULL)
	{
		return DS_ERR_ARRAY_NULL;
	}

	if (arr->capacity == MAX_CAPACITY)
	{
		return DS_ERR_OUT_OF_MEMORY;
	}

	if (arr->capacity * 2 > MAX_CAPACITY)
	{
		arr->capacity = MAX_CAPACITY;
	} else
	{
		arr->capacity *= 2;
	}
	
	int *newArray = realloc(arr->array, sizeof(int) * arr->capacity);
	if (newArray == NULL)
	{
		return DS_ERR_ALLOC_FAIL;
	}
	arr->array = newArray;

	return DS_OK;
}

bool empty(dynamic_array_t* arr)
{
	if (arr == NULL || arr->size == 0)
	{
		return true;
	}

	return false;
}

size_t capacity(dynamic_array_t* arr)
{
	if (arr == NULL)
	{
		return 0;
	}

	return arr->capacity;
}

// Modifiers
enum ds_error clear(dynamic_array_t* arr);
enum ds_error insert(dynamic_array_t* arr, int val, int i);
enum ds_error push_back(dynamic_array_t* arr, int val);
int pop_back(dynamic_array_t* arr);
