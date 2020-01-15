#include <unistd.h>
#include <pthread.h>
#include<stdio.h>
int n;
pthread_mutex_t m = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t c = PTHREAD_COND_INITIALIZER;
pthread_t tid[2];
void* t1(void *x)
{
	printf("N=");
	scanf("%d", &n);
	while(n<52)
		n+=5;
	pthread_mutex_lock(&m);
	pthread_cond_signal(&c);
	pthread_mutex_unlock(&m);
	return x;
}
void* t2(void *x)
{
	pthread_mutex_lock(&m);
	while(n<52)
		pthread_cond_wait(&c,&m);
	printf("%d thread 2 \n",n);
	pthread_mutex_unlock(&m);
	return x;
}

int main()
{
	n=0;
	pthread_create(&tid[0],NULL, t1, NULL);
	pthread_create(&tid[1],NULL,t2,NULL);

	pthread_join(tid[0],NULL);
	pthread_join(tid[1],NULL);
	return 0;
}
