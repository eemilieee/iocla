#include <stdio.h>

int main(void)
{
	int v[] =  {1, 2, 15, 51, 53, 66, 202, 7000};
	int dest = v[2]; /* 15 */
	int start = 0;
	int end = sizeof(v) / sizeof(int) - 1;
	int middle;
	int index = -1;

	/* TODO: Implement binary search */

	(void) dest;
	(void) start;
	(void) end;

sarim:
	if(start > end)
		goto out;
	middle = (start + end) / 2;
	if(dest == v[middle])
	{
		index = middle;
		goto out;
	}
	if(dest > v[middle])
	{
		start = middle + 1;
		goto sarim;
	}
	if(dest < v[middle])
	{
		end = middle - 1;
		goto sarim;
	}

out:
	printf("%d\n", index);
}
