#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv) {
    for (int i = 1; i < argc; i++) {
        for (int j = i + 1; j < argc; j++) {
            FILE *arquivo1 = fopen(argv[i], "rb");
            FILE *arquivo2 = fopen(argv[j], "rb");

            fseek(arquivo1, 0, SEEK_END);
            long tamanho1 = ftell(arquivo1);
            fseek(arquivo2, 0, SEEK_END);
            long tamanho2 = ftell(arquivo2);

            if (tamanho1 != tamanho2) {
                printf("%s %s diferentes\n", argv[i], argv[j]);
                fclose(arquivo1);
                fclose(arquivo2);
                continue;
            }

            rewind(arquivo1);
            rewind(arquivo2);
            int compara = 1;
            for (int k = 0; k < tamanho1; k++) {
                char byte1, byte2;
                fread(&byte1, 1, 1, arquivo1);
                fread(&byte2, 1, 1, arquivo2);
                if (byte1 != byte2) {
                    compara = 0;
                    break;
                }
            }

            if (compara) {
                printf("%s %s iguais\n", argv[i], argv[j]);
            } else {
                printf("%s %s diferentes\n", argv[i], argv[j]);
            }

            fclose(arquivo1);
            fclose(arquivo2);
        }
    }

    return 0;
}