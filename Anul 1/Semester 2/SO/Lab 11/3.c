
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#define MAX_NUM 100

pthread_mutex_t mtx = PTHREAD_MUTEX_INITIALIZER;

int div3=0,div4=0,div5=0;

void* f(void* a)
{
  int k = *(int *)a;
  free(a);
  
  pthread_mutex_lock(&mtx);
  if(k%3==0)
	div3+=1;
  if(k%4==0)
	div4+=1;
  if(k%5==0)
	div5+=1;

  pthread_mutex_unlock(&mtx);
 //printf("Thread-ul %d\n", k);

  return NULL;
}

int main(int argc, char* argv[])
{
  pthread_t t[MAX_NUM];
  
  int i,n;
  scanf("%d",&n);

  int* p;
  for (i = 0; i < n; i++)
  {
    p = (int *)malloc(sizeof(int));      // dynamic allocation
    //*p = i;
    scanf("%d",p);

    pthread_create(&t[i], NULL, f, p);
  }

  for (i = 0; i < n; i++)
  {
    pthread_join(t[i], NULL);
  }
  printf("Div cu 3: %d \nDiv cu 4: %d \nDiv cu 5: %d \n",div3,div4,div5);

  return 0;
}
