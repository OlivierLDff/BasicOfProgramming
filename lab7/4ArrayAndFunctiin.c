#include <stdio.h>
#define SIZE 6
int foo(const int * arr, const size_t size, const int value)
{
	size_t i = 0;
	for (; i < size; ++i) if (arr[i] == value) return i;
	return -1;
}

const int * bar(const int * arr, const size_t size, const int value)
{
	size_t i = 0;
	for (; i < size; ++i) if (arr[i] == value) return &arr[i];
	return NULL;
}

int * foo2(int * arr, const size_t size, const int value)
{
	int * it = arr;
	for (; it < arr + size; ++it) if (*it == value) return it;
	return NULL;
}

int main()
{
	int arr[SIZE] = { 1, 2, 3, 4, 5, 3 };
	printf("index of 3 is : %d (must be 2)\n", foo(arr, SIZE, 3));
	printf("address of 3 is : %p \n", bar(arr, SIZE, 3));
	size_t idx = bar(arr, SIZE, 3) - arr;
	printf("index without foo of 3 is : %d \n", idx);
	printf("address of 3 is : %p \n", foo2(arr, SIZE, 3));

	printf("index of 10 is : %d (must be -1)\n", foo(arr, SIZE, 10));
	printf("address of 10 is : %p \n", bar(arr, SIZE, 10));
	printf("address of 10 is : %p \n", foo2(arr, SIZE, 10));
#ifdef WIN32
	system("pause");
#endif
	return 0;
}
