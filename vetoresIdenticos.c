#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

int n;

int comparador(const void *a, const void *b) {
   if (*(int*)a > *(int*)b) {
      return 1;
   } else if (*(int*)a < *(int*)b) {
      return -1;
   } else {
      return 0;
   }
}

void * ordena(void * arg) {
    qsort(arg, n, sizeof(int), comparador);
}

void compara(int *vetor1, int *vetor2){
    for (int i = 0; i < n; i++)
    {
        if(vetor1[i] != vetor2[i]){
            printf("Diferentes\n");
            return;
        }
    }
    printf("Mesmos elementos\n");
}

int main() {
    scanf("%d", &n);
    pthread_t t1, t2;
    int vetor1[n];
    int vetor2[n];

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &vetor1[i]);
    }

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &vetor2[i]);
    }

    pthread_create(&t1, NULL, ordena, (void *)vetor1);
    pthread_create(&t2, NULL, ordena, (void *)vetor2);

    pthread_join(t1, NULL);
    pthread_join(t2, NULL);

    compara(vetor1, vetor2);

    return 0;
}