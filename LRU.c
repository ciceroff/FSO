#include<stdio.h>

int q, n;
int counter = 0, pos;
int valida1, valida2;
int contadorDeFaults = 0;

int lru(int time[], int n) {
    int minimo = time[0];
    int pos = 0;
 
    for(int i = 1; i < n; i++){
        if(time[i] < minimo){
        minimo = time[i];
        pos = i;
        }
    }
    return pos;
}

int hash(int arrayFrames[], int arrayPages[], int time[]) {
    for(int i = 0; i < n; i++){
        valida1 = valida2 = 0;
    
        for(int j = 0; j < q; j++){
            if(arrayFrames[j] == arrayPages[i]){
                counter++;
                time[j] = counter;
                valida1 = valida2 = 1;
                break;
            }
        }
    
        if(valida1 == 0){
            for(int j = 0; j < q; j++){
                if(arrayFrames[j] == -1){
                counter++;
                contadorDeFaults++;
                arrayFrames[j] = arrayPages[i];
                time[j] = counter;
                valida2 = 1;
                break;
                }
            }
        }
    
        if(valida2 == 0){
            pos = lru(time, q);
            counter++;
            contadorDeFaults++;
            arrayFrames[pos] = arrayPages[i];
            time[pos] = counter;
        }
    }
}
int main() {
   
    scanf("%d", &q);
    scanf("%d", &n);

    int arrayFrames[q], arrayPages[n], time[q];

    for(int i = 0; i < n; i++){
        scanf("%d", &arrayPages[i]);
    }
    
    for(int i = 0; i < q; ++i){
        arrayFrames[i] = -1;
    }
    
    hash(arrayFrames, arrayPages, time);


    printf("%d\n", contadorDeFaults);
    return 0;
}