/*
 * Este programa verifica se um ponto específico (ponto de teste) está
 * localizado dentro de uma área retangular definida por outros dois pontos.
 *
 * 1. ESTRUTURA DE DADOS:
 *    - Utiliza uma estrutura (struct) chamada 'point' para armazenar
 *      coordenadas cartesianas (x, y).
 *
 * 2. LÓGICA DE VERIFICAÇÃO:
 *    - O retângulo é definido assumindo que 'p1' é o canto inferior esquerdo
 *      e 'p2' é o canto superior direito.
 *    - Para que o ponto de teste ('p3' ou 'testPoint') seja considerado "Contido",
 *      sua coordenada X deve estar entre p1.x e p2.x, E sua coordenada Y deve estar
 *      entre p1.y e p2.y.
 *
 * 3. FLUXO:
 *    - O usuário primeiro informa quantos testes deseja realizar.
 *    - Em um loop, o programa lê as coordenadas do retângulo (x0, y0, x1, y1)
 *      e do ponto de teste (x, y).
 *    - Verifica a condição de contido/não-contido e imprime o resultado.
 *
 * NOTA: O código assume estritamente que os valores de p1 são menores ou iguais
 * aos de p2 (p1 define os limites mínimos e p2 os máximos). Se os pontos forem
 * inseridos invertidos (ex: p1 à direita de p2), a lógica falhará.
 */

#include <stdio.h>
#include <math.h> // Incluído, embora não seja estritamente necessário para a lógica atual

// Estrutura para representar um ponto no plano 2D
struct point { 
    float x; 
    float y; 
};
 
int main()
{
    // p1 e p2 definem os limites do retângulo, p3 é o ponto a ser testado
    struct point p1, p2, testPoint;
    
    // Número de casos de teste que o usuário deseja executar
    int numCases;
    
    printf("\n Número de casos de teste: ");
    scanf("%i", &numCases); 
    
    // Loop que itera pela quantidade de casos informados
    for(int i = 0; i < numCases; i++){
    
        // Solicita as coordenadas: dois pontos para o retângulo e um para teste
        printf("\n Digite as coordenadas (x0 y0 x1 y1 x y):");
        scanf("%f %f %f %f %f %f", &p1.x, &p1.y, &p2.x, &p2.y, &testPoint.x, &testPoint.y); 
    
        // Verificação se o ponto está dentro do retângulo
        // Lógica: testPoint.x deve estar entre p1.x e p2.x
        //      E testPoint.y deve estar entre p1.y e p2.y
        // Obs: Assume-se p1 como limite inferior e p2 como limite superior.
        if (p1.x <= testPoint.x && testPoint.x <= p2.x && 
            testPoint.y >= p1.y && testPoint.y <= p2.y) {
            
            printf("\n Contido ");
        } 
        else {
            printf("\n Nao-contido ");
        }
    }
    
    return 0;
}