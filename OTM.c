#include <stdio.h>

int n;
int q;    
int contadorDeFaults = 0;
int valida1, valida2, valida3;
int pos, max;

void hash(int arrayFrames[], int arrayPages[], int temp[]) {
    for(int i = 0; i < n; i++){
        valida1 = valida2 = 0;
        
        for(int j = 0; j < q; j++){
            if(arrayFrames[j] == arrayPages[i]){
                valida1 = valida2 = 1;
                    break;
            }
        }
        
        if(valida1 == 0){
            for(int j = 0; j < q; j++){
                if(arrayFrames[j] == -1){
                    contadorDeFaults++;
                    arrayFrames[j] = arrayPages[i];
                    valida2 = 1;
                    break;
                }
            }    
        }
        
        if(valida2 == 0){
         valida3 = 0;
        
            for(int j = 0; j < q; j++){
                temp[j] = -1;
            
                for(int k = i + 1; k < n; k++){
                    if(arrayFrames[j] == arrayPages[k]){
                        temp[j] = k;
                        break;
                    }
                }
            }
            
            for(int j = 0; j < q; j++){
                if(temp[j] == -1){
                    pos = j;
                    valida3 = 1;
                    break;
                }
            }
            
            if(valida3 == 0){
                max = temp[0];
                pos = 0;
            
                for(int j = 1; j < q; j++){
                    if(temp[j] > max){
                        max = temp[j];
                        pos = j;
                    }
                }            
            }
            arrayFrames[pos] = arrayPages[i];
            contadorDeFaults++;
        }
    }
}

int main()
{
    scanf("%d", &q);
    scanf("%d", &n);
    int arrayFrames[q];
    int arrayPages[n];
    int temp[q];
    for(int i = 0; i < n; ++i){
        scanf("%d", &arrayPages[i]);
    }
    
    for(int i = 0; i < q; ++i){
        arrayFrames[i] = -1;
    }

    hash(arrayFrames, arrayPages, temp);
    
    printf("%d\n", contadorDeFaults);
    return 0;
}
