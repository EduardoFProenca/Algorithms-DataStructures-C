/*
Beecrowd : 2177 - Rio 2016
https://judge.beecrowd.com/pt/problems/view/2177

**Explicação do Código:**
Este programa simula um radar ou sistema de busca de pontos de interesse em um mapa 2D.
O objetivo é verificar quais pontos de uma lista estão dentro de uma distância específica (raio) a partir de um ponto central.

O fluxo do algoritmo é:
1. Lê as coordenadas (X, Y) de um ponto central e a quantidade de pontos a serem verificados.
2. Para cada ponto na lista:
   a. Lê as coordenadas (X, Y) e um valor inteiro (que representa o raio de alcance).
   b. Calcula a distância euclidiana entre o ponto central e o ponto atual.
   c. Se a distância calculada for menor que o raio de alcance do ponto atual, considera-se válido.
3. Imprime os índices (1-based) dos pontos válidos em uma única linha, separados por espaço.
   Se nenhum ponto for válido, imprime -1.
*/

#include <stdio.h>
#include <math.h>

typedef struct {
    double x, y;
    int value; // Campo genérico: armazena a quantidade de pontos na variável central, e o raio nos alvos
} TPoint;

double CalculateDistance(TPoint, TPoint);

int main() {
    TPoint centralPoint, targetPoint;
    
    // Lê o ponto central e a quantidade de pontos ('value' armazena a quantidade N)
    scanf("%lf %lf %d", &centralPoint.x, &centralPoint.y, &centralPoint.value);

    // Array dinâmico (VLA) para armazenar os índices dos pontos válidos
    int validIndices[centralPoint.value];
    int validCount = 0;

    // Loop para ler e processar cada ponto alvo
    for (int j = 0; j < centralPoint.value; j++) {
        // Lê o ponto alvo e seu raio de detecção ('value' armazena o raio)
        scanf("%lf %lf %d", &targetPoint.x, &targetPoint.y, &targetPoint.value);

        // Calcula a distância entre o ponto central e o ponto alvo
        double dist = CalculateDistance(centralPoint, targetPoint);

        // Se a distância for menor que o raio do ponto alvo, é um ponto válido
        if (dist < targetPoint.value) {
            validIndices[validCount] = j + 1; // Armazena o índice (1-based)
            validCount++;
        }
    }

    // Saída: Imprime -1 se nenhum for válido, ou a lista de índices
    if (validCount == 0) {
        printf("-1\n");
    } else {
        for (int i = 0; i < validCount; i++) {
            if (i > 0) printf(" "); // Adiciona espaço entre os números, exceto antes do primeiro
            printf("%d", validIndices[i]);
        }
        printf("\n");
    }

    return 0;
}

// Função auxiliar para calcular a distância euclidiana entre dois pontos
double CalculateDistance(TPoint p1, TPoint p2)
/* Retorna a distância entre dois pontos no plano */
{
    return sqrt(pow(p1.x - p2.x, 2.0) + pow(p1.y - p2.y, 2.0));
}