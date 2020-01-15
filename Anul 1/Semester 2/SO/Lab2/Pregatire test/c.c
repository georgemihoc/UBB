#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(int argc, char **argv)
{
	FILE *f;
	f=fopen("frecventa.txt","r");
	char *s = malloc(10*sizeof(char));
	//char *fr= malloc(30*sizeof(;
	while(!feof(f))
	{
		fgets(s,50,f);
		printf("%sboss\n",s);
	}
//	free(s);
//	fclose(f);
	return 0;
}
