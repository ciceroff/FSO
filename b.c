#include <dlfcn.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
    void *handle;

    handle = dlopen(argv[1], RTLD_NOW);


    if(!handle || dlerror() != NULL){
        printf("nao disponivel\n");
        return 0;
    }

    int (*imprime)() = dlsym(handle, "imprime");

    if(!imprime || dlerror() != NULL) {
        printf("nao implementado\n");
    } else {
        printf("%d\n", imprime());
    }

    int (*calcula)() = dlsym(handle, "calcula");

    if(!calcula || dlerror() != NULL) {
        printf("nao implementado\n");
    } else {
        printf("%d\n", calcula((atoi(argv[2])), atoi(argv[3])));
    }

    char *ptr;
    double variavelTrigo;

    int (*trigo)() = dlsym(handle, "trigo");
    variavelTrigo = strtod(argv[4], &ptr);
    
    if(!trigo || dlerror() != NULL) {
        printf("nao implementado\n");
    } else {
        printf("%d\n", trigo(variavelTrigo));
    }
    
    dlclose(handle);

    return 0;
}



