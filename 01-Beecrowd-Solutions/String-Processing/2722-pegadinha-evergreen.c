/*
Beecrowd : 2722 - Pegadinha de Evergreen
https://judge.beecrowd.com/pt/problems/view/2722

**Explicação do Código:**
Este programa resolve o problema de decifrar uma mensagem secreta escrita em um diário antigo.
A regra para formar a mensagem secreta é intercalar caracteres de duas linhas de texto:
- Ler dois caracteres da primeira linha.
- Depois, ler dois caracteres da segunda linha.
- Repetir esse processo alternadamente até que os caracteres de ambas as linhas acabem.

O algoritmo funciona da seguinte maneira:
1. Lê a quantidade de casos de teste.
2. Para cada caso, lê duas linhas completas (que podem conter espaços).
3. Percorre as duas linhas simultaneamente usando índices (`i` para linha 1, `j` para linha 2).
4. Utiliza uma flag (`readFromLine1`) para alternar entre as linhas.
5. A cada alternação, copia até dois caracteres da linha atual para a string de resultado.
*/

#include <stdio.h>
#include <string.h>

int main() {
    int numCases;
    scanf("%d", &numCases);

    while (numCases--) {
        char line1[105], line2[105], result[210];
        // Lê as duas linhas completas, incluindo espaços
        scanf(" %[^\n]", line1);
        scanf(" %[^\n]", line2);

        int i = 0, j = 0, k = 0;
        int readFromLine1 = 1; // Flag para alternar entre a linha 1 e a linha 2

        // Loop continua enquanto houver caracteres em qualquer uma das linhas
        while (i < strlen(line1) || j < strlen(line2)) {
            if (readFromLine1) {
                // Pega até dois caracteres da linha 1
                if (i < strlen(line1))
                    result[k++] = line1[i++];
                if (i < strlen(line1))
                    result[k++] = line1[i++];
                readFromLine1 = 0;
            } else {
                // Pega até dois caracteres da linha 2
                if (j < strlen(line2))
                    result[k++] = line2[j++];
                if (j < strlen(line2))
                    result[k++] = line2[j++];
                readFromLine1 = 1;
            }
        }
        result[k] = '\0'; // Adiciona o terminador nulo à string de resultado
        printf("%s\n", result);
    }

    return 0;
}