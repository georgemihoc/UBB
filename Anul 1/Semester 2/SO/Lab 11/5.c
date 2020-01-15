#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define MAX_THR 100     // numarul de thread-uri
#define MAX_LIM 1000
#define MAX_NUM 100000  // dimensiunea tabloului de numere

int sum = 0;            // suma numerelor
int numbers[100000];    // tabloul de numere aleatoare

pthread_mutex_t mtx = PTHREAD_MUTEX_INITIALIZER;

//
// Rutina de start a thread-urilor
//
void* f(void* a)
{
  int k = *(int*)a;

  //printf("k = %d\n", k);

  int i;
  int max = k + MAX_LIM;
  for (i = k; i < max; i++)
  {
    pthread_mutex_lock(&mtx);
    sum += numbers[i];
    pthread_mutex_unlock(&mtx);
  }

  //printf("Suma calculata: %d\n", sum);

  free(a);

  return NULL;
}



int main(int argc, char* argv[])
{
  pthread_t t[MAX_THR]; // tabloul cu identificatorii thread-urilor

  // generam 100.000 de numere aleatoare
  int i;
  srand(time(NULL));
  for (i = 0; i < MAX_NUM; i++)
  {
    int k = 10;
    numbers[i] = rand() % k;
  }

  // cream 100 thread-uri
  for (i = 0; i < MAX_THR; i++)
  {
    int *n = (int*)malloc(sizeof(int));
    *n = i * MAX_LIM;
    pthread_create(&t[i], NULL, f, n);
  }

  // asteptam terminarea thread-urilor
  for (i = 0; i < MAX_THR; i++)
  {
    pthread_join(t[i], NULL);
  }

  printf("Suma calculata:  %d\n", sum);

  // verificam daca suma este corecta
  int check_sum = 0;
  for (i = 0; i < MAX_NUM; i++)
  {
    check_sum += numbers[i];
  }

  printf("Suma verificata: %d\n", check_sum);

  return 0;
}
