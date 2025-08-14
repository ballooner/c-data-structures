#include "dynamic-array.h"
#include <stdio.h>

int main(void)
{
	dynamic_array_t* arr = init_size_dynamic_array(10);

	printf("Array empty? %d\n", empty(arr));
	printf("Array capacity: %zu\n", capacity(arr));

	free_dynamic_array(arr);
}
