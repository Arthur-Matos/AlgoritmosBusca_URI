    #include <stdio.h>
    #include <stdlib.h>

    int main() {
        int quantidadeInstancias;
        scanf("%d", &quantidadeInstancias);
        while (quantidadeInstancias--) {
            int quantidadeElementos;
            scanf("%d", &quantidadeElementos);

            int *permutacao = (int*)malloc((quantidadeElementos + 1) * sizeof(int));
            int *visitado = (int*)calloc(quantidadeElementos + 1, sizeof(int));

            for (int posicao = 1; posicao <= quantidadeElementos; posicao++) {
                scanf("%d", &permutacao[posicao]);
            }

            int trocasMinimas = 0;
            for (int inicio = 1; inicio <= quantidadeElementos; inicio++) {
                if (!visitado[inicio]) {
                    int tamanhoCiclo = 0;
                    int posicaoAtual = inicio;

                    while (!visitado[posicaoAtual]) {
                        visitado[posicaoAtual] = 1;
                        posicaoAtual = permutacao[posicaoAtual];
                        tamanhoCiclo++;
                    }

                    if (tamanhoCiclo > 1) {
                        trocasMinimas += (tamanhoCiclo - 1);
                    }
                }
            }

            printf("%d\n", trocasMinimas);

            free(permutacao);
            free(visitado);
        }
        return 0;
    }
