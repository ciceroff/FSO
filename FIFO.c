#include <stdio.h>

int n;
int q;    
int contadorDeFaults = 0;
int cont;
void remaneja(int array[], int numero) {
    for (int i = q - 1; i > -1; i--)
    {
        if(i == 0) {
            array[i] = numero;
            return;
        }
        array[i] = array[i-1];
    }
}

void hash(int numero, int array[]) {
    for (int i = q-1; i > -1; i--)
    {   
        if(numero == array[i]){
            return;
        }
    }
    contadorDeFaults++;
    remaneja(array, numero);

}


int main()
{
    scanf("%d", &q);
    int numero;
    scanf("%d", &n);
    int array[q];
    cont = q - 1;

    for (int i = 0; i < q; i++)
    {
        array[i] = -1;
    }
    
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &numero);
        hash(numero, array);
        if(cont != -1){
            cont--;
        }
    }
    printf("%d\n", contadorDeFaults);
    return 0;
}
