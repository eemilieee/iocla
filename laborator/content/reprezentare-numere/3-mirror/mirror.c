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

void mirror(char *s)
{
	/* TODO */
	(void) s;
	int i;
	char aux;
	for(i=0; i<my_strlen(s)/2; i++)
	{
		aux=*(s+i);
		*(s+i)=*(s+my_strlen(s)-1-i);
		*(s+my_strlen(s)-1-i)=aux;
	}
}

int main()
{
	/* TODO: Test function */
	char s[100];
	fgets(s,100,stdin);
	strcpy(s+my_strlen(s)-1,s+my_strlen(s));
	mirror(s);
	printf("%s\n",s);
	return 0;
}

