#include <stdio.h>

void rotate_left(int *number, int bits)
{
	/* TODO */
	(void) number;
	(void) bits;
	int bit,masca,i;
	for(i=1; i<=bits; i++)
	{
		if((*number)&(1<<31))
			bit=1;
		else
			bit=0;
		*number=(*number)<<1;
		if(bit)
			{
				masca=1;
				*number=(*number)|masca;
			}
		else
		{
			masca=1;
			masca=~masca;
			*number=(*number)&masca;
		}
	}
}

void rotate_right(int *number, int bits)
{
	/* TODO */
	(void) number;
	(void) bits;
	int bit,masca,i;
	for(i=1; i<=bits; i++)
	{
		if((*number)&1)
			bit=1;
		else
			bit=0;
		*number=(*number)>>1;
		if(bit)
			{
				masca=1<<31;
				*number=(*number)|masca;
			}
		else
		{
			masca=1<<31;
			masca=~masca;
			*number=(*number)&masca;
		}
	}
}

int main()
{
	/* TODO: Test functions */
	int n,b,m;
	scanf("%d%d",&n,&b);
	m=n;
	rotate_left(&n,b);
	rotate_right(&m,b);
	printf("%d %d\n",n,m);
	return 0;
}

