#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
		char *c = "hello@bye";
		//char *abc = strdup(c);
		char *temp = NULL;

		temp = strchr(c, '@');
		printf("temp add %p\n", temp);
		*temp = 0;
		printf(" %c ", *temp);
		return 0;
}
