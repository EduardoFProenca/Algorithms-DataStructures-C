/*
Beecrowd : 1367 - Ajude!
https://judge.beecrowd.com/pt/problems/view/1367

**Explicação do Código:**
Este código resolve o problema de cálculo de pontuação de uma maratona de programação.
O objetivo é ler um conjunto de submissões de problemas e calcular:
1. O número total de problemas que foram resolvidos com sucesso (aceitos).
2. O tempo total acumulado pela equipe.

A lógica de cálculo do tempo funciona da seguinte maneira:
- Cada problema aceito soma o tempo em que foi submetido.
- Além disso, soma-se uma penalidade de 20 minutos para cada tentativa incorreta 
  (incorrect) que foi feita para esse mesmo problema antes de acertar.
O processo se repete para vários casos de teste até que o número de submissões lido seja 0.
*/

#include <stdio.h>
#include <string.h>

int main() {
    int numSubmissions; // Número de submissões para o caso de teste atual

    // Loop principal que processa cada caso de teste
    while (1) {
        // Array para marcar se o problema já foi aceito (1 = sim, 0 = não)
        int solved[26] = {0};
        // Contador de problemas resolvidos corretamente
        int totalCorrect = 0;
        // Array para contar o número de tentativas incorretas por problema (para cálculo de penalidade)
        int penaltyAttempts[26] = {0};
        // Variável para acumular o tempo total da competição
        int totalTime = 0;

        scanf("%d", &numSubmissions);
        
        // Se o número de submissões for 0, encerra o programa
        if(numSubmissions == 0)
            break;

        // Loop para ler cada uma das submissões
        for (int i = 0; i < numSubmissions; i++) {
            char problemId; // Letra do problema (ex: 'A', 'B')
            int submissionTime; // Tempo da submissão em minutos
            char verdict[10]; // Resultado do juiz (correct, incorrect, etc.)
            
            scanf(" %c %d %s", &problemId, &submissionTime, verdict);

            // Converte a letra do problema em um índice numérico (0 a 25)
            int index = problemId - 'A';

            // Verifica se o julgamento foi "correct" (correto)
            if (strcmp(verdict, "correct") == 0) {
                // Marca o problema como resolvido
                solved[index] = 1;
                // Incrementa o contador de problemas resolvidos
                totalCorrect++;
                // Soma ao tempo total: o tempo da submissão + (20 minutos * tentativas erradas anteriores)
                totalTime += submissionTime + 20 * penaltyAttempts[index];
            } else {
                // Se não foi correto, incrementa o contador de tentativas incorretas para este problema
                penaltyAttempts[index]++;
            }
        }

        // Imprime a quantidade de problemas resolvidos e o tempo total
        printf("%d %d\n", totalCorrect, totalTime);
    }
    return 0;
}