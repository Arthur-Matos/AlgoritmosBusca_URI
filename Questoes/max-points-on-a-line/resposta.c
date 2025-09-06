#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int dx, dy;
    int qtd;
    int ocupado;
} EntradaReta;

int mdc(int a, int b) {
    if (b == 0) {
        return a;
    }
    return mdc(b, a % b);
}

long long hash(int dx, int dy, int capacidade) {
    const int P1 = 1000003;
    const int P2 = 10000019;
    long long h = (long long)dx * P1 + (long long)dy * P2;
    return (h % capacidade);
}

int adicionarHash(EntradaReta* tabela, int capacidade, int dx, int dy) {
    long long h = hash(dx, dy, capacidade);

    while (tabela[h].ocupado) {
        if (tabela[h].dx == dx && tabela[h].dy == dy) {
            tabela[h].qtd++;
            return tabela[h].qtd;
        }
        h = (h + 1) % capacidade;
    }

    tabela[h].ocupado = 1;
    tabela[h].dx = dx;
    tabela[h].dy = dy;
    tabela[h].qtd = 1;
    return 1;
}

int maxPoints(int** points, int pointsSize, int* pointsColSize) {
    if (pointsSize <= 2) {
        return pointsSize;
    }

    int resposta = 0;
    for (int i = 0; i < pointsSize; i++) {
        int capacidade = pointsSize * 4;
        EntradaReta* tabela = calloc(capacidade, sizeof(EntradaReta));

        int duplicados = 1;
        int maxLocal = 0;
        for (int j = i + 1; j < pointsSize; j++) {
            int dx = points[j][0] - points[i][0];
            int dy = points[j][1] - points[i][1];

            if (dx == 0 && dy == 0) {
                duplicados++;
                continue;
            }

            int g = mdc(abs(dx), abs(dy));
            dx /= g;
            dy /= g;

            if (dx < 0) {
                dx = -dx;
                dy = -dy;
            } else if (dx == 0) {
                dy = 1;
            } else if (dy == 0) {
                dx = 1;
            }

            int qtd = adicionarHash(tabela, capacidade, dx, dy);
            if (qtd > maxLocal) {
                maxLocal = qtd;
            }
        }

        if (maxLocal + duplicados > resposta) {
            resposta = maxLocal + duplicados;
        }
    }

    return resposta;
}

int main() {
    int pontosLidos = 0;
    int capacidade = 100;
    int** pontos = malloc(capacidade * sizeof(int*));

    int x, y;
    while (scanf("%d %d", &x, &y) == 2) {
        pontos[pontosLidos] = malloc(2 * sizeof(int));
        pontos[pontosLidos][0] = x;
        pontos[pontosLidos][1] = y;
        pontosLidos++;
    }

    int resultado = maxPoints(pontos, pontosLidos, NULL);
    printf("Máximo de pontos na mesma reta: %d\n", resultado);

    return 0;
}
