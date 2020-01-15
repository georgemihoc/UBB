

#include<stdio.h>
#include<stdlib.h>
int main(int argc,char** argv)
{
	int m,n;
	FILE *f;
	//int *s;
	f=fopen(argv[1],"r");
	fscanf(f,"%d",&m);
	fscanf(f,"%d",&n);
	int k;
	int **matrice =(int**)  malloc(n*sizeof(int*));
	for (k=0;k<n;k++)
	{
		matrice[k] = (int*)malloc(m*sizeof(int));
	}
	int i,j;

	//Citirea matricei
	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++){
			fscanf(f,"%d",&matrice[i][j]);
			//printf("%d ",matrice[i][j]);
		}
		//printf("\n");
	}

	//Afisarea matricei transpuse
	for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++){
			//fscanf(f,"%d",&matrice[i][j]);
			printf("%d ",matrice[j][i]);
		}
		printf("\n");
	}

	//Dealocam vectorul 
	for(i=0;i<n;i++)
		free(matrice[i]);
	free(matrice);//
	fclose(f);
	return 0;
}
