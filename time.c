#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/time.h>
#include <errno.h>
#include <string.h>

int main()
{
    char path[256], arg[256];
    int status = 0, flag = 0;
    struct timeval inicio, inicio_geral, fim_geral, final;

    while (scanf("%s %s", path, arg) != EOF)
    {
        if (flag == 0)
        {

            gettimeofday(&inicio_geral, NULL);
            flag = 1;
        }

        gettimeofday(&inicio, NULL);

        fflush(stdout);
        int pid = fork();

        if (pid == 0)
        {
            int retorno = execl(path, path, arg, NULL);
            if (retorno == -1)
            {
                printf("> Erro: %s\n", strerror(errno));
                fflush(stdout);
                status = errno;
                fclose(stdin);
                return errno;
            }
            return retorno;
        }

        if (waitpid(pid, &status, WUNTRACED))
        {
            int retorno_processo = WEXITSTATUS(status);

            gettimeofday(&final, NULL);

            printf("> Demorou %.1lf segundos, retornou %d\n", (double)(final.tv_usec - inicio.tv_usec) / 1000000 + (double)(final.tv_sec - inicio.tv_sec), retorno_processo);
            fflush(stdout);
        }
    }
    gettimeofday(&fim_geral, NULL);

    printf(">> O tempo total foi de %.1lf segundos\n", (double)(fim_geral.tv_usec - inicio_geral.tv_usec) / 1000000 + (double)(fim_geral.tv_sec - inicio_geral.tv_sec));
    fflush(stdout);
    exit(0);
}
