#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main(int argc, char**argv)
{
	//printf("TUN");
	FILE*f;
	f= fopen("vocale.txt","r");
	char*c=malloc(10*sizeof(char));
	int nr=0;
	while(!feof(f))
	{
		fgets(c,50,f);
		int i;
		for(i=0;i<strlen(c);i++)
		{
			if(strchr("aeiouAEIOU",c[i]))
				 nr++;
		}
	}
	printf("%d",nr);
	free(c);
	printf("\n");
	return 0;
}

