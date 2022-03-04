#include <stdio.h>
#include <stdlib.h>

void print_binary(int number, int nr_bits)
{
	/* TODO */
	(void) number;
	(void) nr_bits;
	int i;
	printf("0b");
	for(i=nr_bits-1; i>=0; i--)
		if(number&(1<<i))
			printf("1");
		else
			printf("0");
	printf("\n");
}

void check_parity(int *numbers, int n)
{
	/* TODO */
	(void) numbers;
	(void) n;
	/*int i;
	for(i=0; i<n; i++)
		if(((*(numbers+i))&1))
			printf("%X\n",*(numbers+i));
		else
			print_binary(*(numbers+i),8);
	*/
	int *p;
	for(p=numbers; p<numbers+n; p++)
		if((*p)&1)
			printf("%X\n",*p);
		else
			print_binary(*p,8);
}

int main()
{
	/* TODO: Test functions */
	int *v,n,i;
	scanf("%d",&n);
	v=(int *)malloc(n*sizeof(int));
	for(i=0; i<n; i++)
		scanf("%d",v+i);
	check_parity(v,n);
	free(v);
	return 0;
}

