#include <unistd.h>
#include <pthread.h>
#include <stdio.h>

pthread_t tid[2];

void* t1(void *x)
{
	int *n= (int*) x;
	//printf("%d",n[0]);
	printf("Suma = %d \n",n[0] + n[1]);
	return NULL;
}
int main()
{
	int n[2];
	printf("N1 = ");
	scanf("%d", &n[0]);
	printf("N2 = ");
	scanf("%d",&n[1]);
	//printf("%d",n[0]);
	pthread_create(&tid[0], NULL, t1, n);
	pthread_join(tid[0], NULL);
	return 0;
}
