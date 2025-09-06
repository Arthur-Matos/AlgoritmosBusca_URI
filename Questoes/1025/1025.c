#include <stdio.h>
#include <stdlib.h>

int comparar(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

int buscaBinaria(int vetor[], int tamanho, int valor) {
    int esquerda = 0, direita = tamanho - 1, resultado = -1;
    while (esquerda <= direita) {
        int meio = (esquerda + direita) / 2;
        if (vetor[meio] == valor) {
            resultado = meio;
            direita = meio - 1;
        } else if (vetor[meio] < valor) {
            esquerda = meio + 1;
        } else {
            direita = meio - 1;
        }
    }
    return resultado;
}

int main() {
    int qtdMarmores, qtdConsultas, caso = 1;
    while (1) {
        scanf("%d %d", &qtdMarmores, &qtdConsultas);
        if (qtdMarmores == 0 && qtdConsultas == 0) {
            break;
        }

        int marmores[qtdMarmores];
        for (int i = 0; i < qtdMarmores; i++) {
            scanf("%d", &marmores[i]);
        }

        qsort(marmores, qtdMarmores, sizeof(int), comparar);
        printf("CASE# %d:\n", caso++);
        for (int i = 0; i < qtdConsultas; i++) {
            int consulta;
            scanf("%d", &consulta);
            int pos = buscaBinaria(marmores, qtdMarmores, consulta);
            if (pos == -1) {
                printf("%d not found\n", consulta);
            } else {
                printf("%d found at %d\n", consulta, pos + 1);
            }
        }
    }

    return 0;
}
