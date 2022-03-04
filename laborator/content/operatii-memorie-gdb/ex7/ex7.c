#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <stdlib.h>

int my_strcmp(const char *s1, const char *s2)
{
	int sum1=0,sum2=0,i;
	for(i=0; i<strlen(s1); i++)
		sum1+=*(s1+i);
	for(i=0; i<strlen(s2); i++)
		sum2+=*(s2+i);
	return sum1-sum2;
}

void *my_memcpy(void *dest, const void *src, size_t n)
{
	int i;
	char *p=(char *)src;
	for(i=0; i<n; i++)
		*((char *)(dest+i))=*(p+i);
	return dest;
}

char *my_strcpy(char *dest, const char *src)
{
	int i;
	for(i=0; i<strlen(src); i++)
		*(dest+i)=*(src+i);
	*(dest+strlen(src))=0;
	return dest;
}

int main() {
	char s1[] = "Abracadabra";
	char s2[] = "Abracababra";
	char s3[101] =  "Learn IOCLA, you must!";
	char src[] = "Learn IOCLA, you must!";
	char *dest = malloc(sizeof(src));

	/*
	Decomentati pe rand cate un assert pe masura ce implementati o functie.
	Daca functia voastra este implementata corect atunci asertia se va realiza
	cu succes. In caz contrar, programul va crapa.
	*/

	printf("%d\n",my_strcmp(s1,s2));
	my_memcpy(dest,src,strlen(src)+1);
	printf("%s\n",dest);
	my_strcpy(strrchr(s3,' ')+1,s1+1);
	printf("%s\n",s3);

	assert(my_strcmp(s1, s2) == strcmp(s1, s2));
	assert(my_memcpy(dest, src, sizeof(src)) == memcpy(dest, src, sizeof(src)));
	assert(my_strcpy(dest, src) == strcpy(dest, src));

	free(dest);

	return 0;
}
