#include <stdio.h>

unsigned int get_max(unsigned int *arr, unsigned int len, unsigned int *poz);

int main(void)
{
	unsigned int arr[] = { 19, 7, 129, 87, 54, 218, 67, 12, 19, 99 };
	unsigned int max;

	unsigned int poz = 0;

	max = get_max(arr, 10, &poz);

	printf("max: %u\n", max);
	printf("poz: %u\n", poz);

	return 0;
}
