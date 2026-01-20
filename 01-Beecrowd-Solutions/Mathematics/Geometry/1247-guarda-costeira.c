/*
Beecrowd : 1247 - Guarda Costeira
https://judge.beecrowd.com/pt/problems/view/1247

**Explicação do Código:**
Este programa determina se um barco da guarda costeira consegue interceptar um navio fugitivo.
O problema envolve geometria plana e cinemática, formando um triângulo retângulo:
- A guarda está a 12 milhas náuticas da costa.
- O fugitivo está a uma distância `D` ao longo da costa do ponto mais próximo da guarda.

O algoritmo executa os seguintes passos:
1. Lê a distância do fugitivo (`distanceShore`) e as velocidades do fugitivo (`speedFugitive`) e da guarda (`speedGuard`).
2. Calcula o tempo de referência para o fugitivo (segundo a fórmula presente no código original).
3. Calcula o tempo necessário para a guarda percorrer a hipotenusa do triângulo (distância de interceptação).
4. Compara os tempos: se o tempo da guarda for menor ou igual ao tempo do fugitivo, imprime "S" (Sim),
   caso contrário imprime "N" (Não).
*/

#include <stdio.h>
#include <math.h>

int main()
{
    int distanceShore, speedFugitive, speedGuard;
    double timeFugitive;

    // Loop que lê múltiplos casos de teste até o fim da entrada
    while (scanf("%d %d %d", &distanceShore, &speedFugitive, &speedGuard) == 3) {

        // Cálculo do tempo (mantendo a lógica exata do código original: 12.0 dividido pela velocidade)
        timeFugitive = 12.0 / speedFugitive;

        // Verifica se o tempo da guarda (Hipotenusa / Velocidade) é menor ou igual ao tempo do fugitivo
        // sqrt(distanceShore^2 + 12^2) calcula a distância da hipotenusa
        if (sqrt(distanceShore * distanceShore + 144) / speedGuard <= timeFugitive) {
            printf("S\n");
        } else {
            printf("N\n");
        }
    }
    return 0;
}