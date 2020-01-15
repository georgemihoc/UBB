#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

pthread_mutex_t mt=PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t cond= PTHREAD_MUTEX_INITIALIZER;

int* vector;

typedef struct{
	char fisier[100];
	int indice;
}fis;

void* threadBla1(void *par){
	fis* str = par;
	char fisier[100];
	strcpy(fisier, str->fisier);
	FILE* f = fopen(fisier,"r");
	int a, b;
	fscanf(f,"%d",&a);
	fscanf(f,"%d",&b);
	int indice = str->indice;
	pthread_mutex_lock(&mt);
	while(vector[indice] <= b)
		vector[indice]+=a;
	pthread_cond_signal(&cond);
	pthread_mutex_unlock(&mt);
	return NULL;
}

void* threadBla2(void *par){
	fis* str = par;
	int indice = str->indice;
	pthread_mutex_lock(&mt);
	while(vector[indice] == 0)
		pthread_cond_wait(&cond,&mt);
	printf("%s: %d\n", str->fisier, vector[indice]);
	pthread_mutex_unlock(&mt);
	return NULL;
}
int main(int argc, char**argv){

	int i;
	//pthread_mutex_init(&mt,NULL);
	vector = malloc(sizeof(int)*( argc - 1));

	pthread_t threads1[argc];
	pthread_t threads2[argc];
	fis params[argc];
	for(i = 1; argv[i]; i++){
		strcpy(params[i].fisier, argv[i]);
		params[i].indice = i;
		pthread_create(&threads2[i],NULL,threadBla1,&params[i]);
		pthread_create(&threads1[i],NULL,threadBla2,&params[i]);
	}

	for(i = 1; i<argc; i++){
		pthread_join(threads2[i],NULL);
		pthread_join(threads1[i],NULL);
	}
	pthread_mutex_destroy(&mt);
	pthread_cond_destroy(&cond);
	free(vector);
	return 0;
}
