#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char* delete_first(char *s, char *pattern)
{
	strcpy(strstr(s,pattern),strstr(s,pattern)+strlen(pattern));
	return s;
}

int main(){
	char s[] = "Ana are mere";
	char *pattern = "re";

	// Decomentati linia dupa ce ati implementat functia delete_first.
	printf("%s\n", delete_first(s, pattern));

	return 0;
}
