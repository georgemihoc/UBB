#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <string.h>
#define MAX_NUM 100

int mici=0,mari=0,cifre=0;

pthread_mutex_t mtx = PTHREAD_MUTEX_INITIALIZER;

void* f(void* a)
{
  int i,ok=0;
  char *k = (char*)a;
  //printf("%s ",k);
  pthread_mutex_lock(&mtx);
  for(i=0;i<strlen(k);i++)
  {
	if(k[i]>='a' && k[i]<='z') mici+=1;
	if(k[i]>='A' && k[i]<='Z') mari+=1;
	if(k[i]>='0' && k[i]<='9') ok=1;
  }
  if(ok) cifre+=1;
  pthread_mutex_unlock(&mtx);	
  return NULL;
}

int main(int argc, char* argv[])
{
  pthread_t t[MAX_NUM];
  
  int i=0, j=0,n=0;
  while(argv[i+1])
  {
	n+=1;
	//printf("%s ",argv[i]);
	pthread_create(&t[i], NULL, f, (void*)argv[i+1]);
	i+=1;
  }

  for (i = 0; i < n; i++)
  {
    pthread_join(t[i], NULL);
  }
  printf("Litere mici: %d \nLitere mari: %d \n",mici,mari);
  printf("Argumente care contin cifre: %d \n",cifre);
  return 0;
}

