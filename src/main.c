#include "dynamic-array.h"
#include <stdio.h>

int main(void)
{
	dynamic_array_t* arr = init_dynamic_array();
	insert(arr, 5, 0);
	int val;
	at(arr, &val, 0);
	printf("Array[0]: %d\n", val);

	printf("Array empty? %s\n", empty(arr) ? "True\n" : "False\n");
	clear(arr);
	printf("Array empty? %s\n", empty(arr) ? "True\n" : "False\n");
	printf("Array capacity: %zu\n", capacity(arr));

	free_dynamic_array(arr);
}
