#include <stdio.h>
#include <string.h>

#define ASCII_TAM 256

int hash(char c) {
    return c % ASCII_TAM;
}

int lengthOfLongestSubstring(char* s) {
    int hashTable[ASCII_TAM];
    for (int i = 0; i < ASCII_TAM; i++) {
        hashTable[i] = -1;
    }

    int inicio = 0, maxLen = 0;
    for (int i = 0; s[i] != '\0'; i++) {
        int h = hash(s[i]);

        if (hashTable[h] >= inicio) {
            inicio = hashTable[h] + 1;
        }

        hashTable[h] = i;
    
        int lenAtual = i - inicio + 1;
        if (lenAtual > maxLen) {
            maxLen = lenAtual;
        }
    }

    return maxLen;
}

int main() {
    char entrada[1000];

    if (scanf("%s", entrada) == 1) {
        int resultado = lengthOfLongestSubstring(entrada);
        printf("%d\n", resultado);
    }

    return 0;
}
