#include<stdio.h>
#include<stdlib.h>
int main(int argc,char** argv)
{
	int m,n;
	FILE *f;
	f=fopen("matrice.txt","r");
	fscanf(f,"%d",&n);
	fscanf(f,"%d",&m);
	int **matrice,k;
	matrice = malloc(n*sizeof(int*));
	for (k=0;k<n;k++)
	{
		matrice[k] = (int*)malloc(m*sizeof(int));
	}
	int i,j;
	for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++){
			fscanf(f,"%d",&matrice[i][j]);
			printf("%d ",matrice[i][j]);
		}
		printf("\n");
	}
	for(i=0;i<n;i++)
		free(matrice[i]);
	free(matrice);
	fclose(f);
	return 0;
}

