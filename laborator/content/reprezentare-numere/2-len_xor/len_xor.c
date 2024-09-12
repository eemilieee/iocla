#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int my_strlen(const char *str)
{
	/* TODO */
	(void) str;
	const char *p;
	int nr=0;
	p=str;
	while(*p)
	{
		nr++;
		p++;
	}
	return nr;
}

int pow_2(int x)
{
	return 1<<x;
}

void equality_check(const char *str)
{
	/* TODO */
	(void) str;
	int i=0;
	for(i=0; i<my_strlen(str); i++)
		if((i+pow_2(i))<my_strlen(str))
		{
			if(!((*(str+i))^(*(str+i+pow_2(i)))))
				printf("%X\n",&(*(str+i)));
		}
		else
			{
				if(!((*(str+i))^(*(str+(i+pow_2(i))%my_strlen(str)))))
				printf("%X\n",&(*(str+i)));
			}
	printf("\n");
}

int main(void)
{
	/* TODO: Test functions */
	const char s[]="aac";
	printf("%d\n",my_strlen(s));
	equality_check(s);
	return 0;
}

