/*
 * Este programa calcula a distância Euclidiana entre dois pontos em um
 * plano cartesiano 2D (coordenadas X e Y).
 *
 * 1. ESTRUTURA DE DADOS:
 *    - É utilizada uma estrutura (struct) chamada 'point' para representar
 *      as coordenadas de um ponto no espaço.
 *
 * 2. FLUXO DE EXECUÇÃO:
 *    - O programa entra em um loop infinito (do-while).
 *    - Solicita ao usuário que digite 4 números: x1, y1, x2, y2.
 *
 * 3. CONDIÇÃO DE PARADA (Sentinela):
 *    - O loop é interrompido apenas quando o usuário digitar 0 (zero)
 *      para todas as quatro coordenadas (0 0 0 0).
 *
 * 4. CÁLCULO:
 *    - Se a condição de parada não for atendida, o programa aplica o
 *      Teorema de Pitágoras para encontrar a hipotenusa (distância):
 *      Distância = Raiz Quadrada( (x2 - x1)² + (y2 - y1)² )
 *      Utiliza as funções da biblioteca <math.h>: pow (potência) e sqrt (raiz).
 *
 * 5. SAÍDA:
 *    - O resultado é impresso na tela com precisão de duas casas decimais.
 */

#include <stdio.h>
#include <math.h>
#include <stdbool.h>

// Estrutura para representar um ponto com coordenadas x e y
struct point { 
    float x; 
    float y; 
};
 
int main()
{
    // Declaração de dois pontos (p1 e p2) e da variável para armazenar a distância
    struct point p1, p2;
    float distance;
    
    // Loop 'do-while' que executa indefinidamente até o comando 'break' ser acionado
    do {
        // Solicita ao usuário as coordenadas dos dois pontos
        printf("\nInforme as coordenadas (x1 y1 x2 y2): ");
        scanf("%f %f %f %f", &p1.x, &p1.y, &p2.x, &p2.y); 
    
        // Verifica se todos os valores são zero (Condição de parada)
        if (p1.x == 0 && p1.y == 0 && p2.x == 0 && p2.y == 0){
            break; // Interrompe o loop e encerra o programa
        }
        
        // Cálculo da distância Euclidiana
        // Fórmula: d = sqrt((x2 - x1)^2 + (y2 - y1)^2)
        distance = sqrt(pow(p2.x - p1.x, 2) + pow(p2.y - p1.y, 2));
        
        // Exibe o resultado formatado
        printf("\nA Distancia entre os pontos é: %.2f\n", distance);
    
    } while(true); // Condição sempre verdadeira para manter o loop
    
    return 0;
}