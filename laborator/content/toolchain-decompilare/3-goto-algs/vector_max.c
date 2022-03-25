#include <stdio.h>

int main(void)
{
	int v[] = {4, 1, 2, -17, 15, 22, 6, 200};
	int max;
	int i;

	int n = sizeof(v)/sizeof(int);

	/* TODO: Implement finding the maximum value in the vector */
	max = v[0];
	i = 1;

	(void) i;
	(void) max;

sarim:
	if(i == n)
		goto out;
	if(max < v[i])
		max = v[i];
	i++;
	goto sarim;

out:
	printf("%d\n",max);
}
