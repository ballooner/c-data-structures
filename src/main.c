#include "dynamic-array.h"
#include <stdio.h>

int main(void)
{
	dynamic_array_t* arr;
	init_dynamic_array(arr);


	free_dynamic_array(arr);
}
