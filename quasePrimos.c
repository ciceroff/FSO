#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <math.h>

struct parametroThread {
    int n;
    int result;
};

int contaDivisores(int numero) {
    int count = 0;
    double sqrtNumero = sqrt(numero);
    for (int i = 2; i < 11; i++) {
        if (numero % i == 0 ) {
            return 0;
        }
    }

    for (int i = 11; i < sqrtNumero; i+=2) {
        if (numero % i == 0 ) {
             count++;
        }
        if (count > 10) return 1;
    }

    return 0;
    
}

void * calculaPrimo(void *parametro) {
    struct parametroThread *final = (struct parametroThread *)(parametro);
    if(final->n < 508079){
        final->result = 508079;
    } else {
        while(1) {
            final->n+=1;
            if(contaDivisores(final->n)) {
                final->result = final->n;
                break;
            }
        }
        
    }
}

int main()
{
    int n, numero;
    pthread_t t1, t2;
    scanf("%d", &n);

    while(1) {
        if(scanf("%d", &numero) == EOF) break;

        struct parametroThread PARAMETRO_A;
        PARAMETRO_A.n = numero;
        pthread_create(&t1, NULL, calculaPrimo, (void *)&PARAMETRO_A);
        
        if(scanf("%d", &numero) == EOF) { 
            pthread_join(t1, NULL);
            printf("%d\n", PARAMETRO_A.result);
            break;
        }

        struct parametroThread PARAMETRO_B;
        PARAMETRO_B.n = numero;    
        pthread_create(&t2, NULL, calculaPrimo, (void *)&PARAMETRO_B);
        
        if(scanf("%d", &numero) == EOF) { 
            pthread_join(t1, NULL);
            pthread_join(t2, NULL);
            printf("%d\n%d\n", PARAMETRO_A.result, PARAMETRO_B.result);
            break;
        }

        
        struct parametroThread PARAMETRO_C;
        PARAMETRO_C.n = numero;    
        calculaPrimo((void *) &PARAMETRO_C);
        
        pthread_join(t1, NULL);
        pthread_join(t2, NULL);
        printf("%d\n%d\n%d\n", PARAMETRO_A.result, PARAMETRO_B.result, PARAMETRO_C.result);

        
    }   

    return 0;
}
