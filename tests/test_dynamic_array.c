#include "dynamic-array.h"
#include <stdio.h>
#include <assert.h>

int main(void)
{	
	// Test custom capacity dynamic array creation
	dynamic_array_t* arr = init_size_dynamic_array(10);
	assert(arr->capacity == 10);
	assert(arr->size == 0);

	free_dynamic_array(arr);

	// Test default dynamic array creation
	arr = init_dynamic_array();
	assert(arr != NULL);
	assert(arr->capacity == DEFAULT_CAPACITY);
	assert(arr->size == 0);

	// Test push_back() and at()
	push_back(arr, 10);
	assert(arr->array[0] == 10);
	int returnVal;
	at(arr, &returnVal, 0);
	assert(returnVal == 10);

	// Test empty() and pop_back();
	assert(!empty(arr));
	pop_back(arr);
	assert(empty(arr));

	// Test insert()
	push_back(arr, 10);
	insert(arr, 20, 0);
	insert(arr, 30, 0);
	assert(arr->array[0] == 30 && arr->array[1] == 20 && arr->array[2] == 10);

	// Test clear()
	clear(arr);
	assert(arr->size == 0);

	free(arr);

	printf("Dynamic array working properly\n");

	return 0;
}
