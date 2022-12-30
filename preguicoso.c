#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>

int counterAlrm = 0;

void handleSignalSIGUSR1() {
    printf("SIGUSR1 eh para aproveitar mais um pouco\n");
}

void handleSignalSIGALRM(){
    if(counterAlrm > 1) {
        printf("Os incomodados que se mudem, tchau\n");
        exit(0);
    } else {
        printf("Ai que sono, quero dormir mais um pouco\n");
        counterAlrm++;
    }
}

int main() {
    signal(SIGUSR1, handleSignalSIGUSR1);
    signal(SIGALRM, handleSignalSIGALRM);
    
    while(1)
        pause();

 }