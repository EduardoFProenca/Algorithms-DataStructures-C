/*
Beecrowd : 1548 - Fila do Recreio
https://judge.beecrowd.com/pt/problems/view/1548

**Explicação do Código:**
Este programa simula a reorganização de uma fila de alunos baseada nas suas notas.
O objetivo é descobrir quantos alunos não precisariam sair do lugar se a fila fosse
ordenada em ordem decrescente de notas (maior nota na frente).

O processo é o seguinte:
1. Lê a quantidade de casos de teste.
2. Para cada caso, lê a quantidade de alunos e as notas deles.
3. Cria uma cópia do vetor de notas.
4. Ordena essa cópia em ordem decrescente (usando o algoritmo Bubble Sort).
5. Compara o vetor original de notas com o vetor ordenado posição por posição.
6. Se a nota do aluno na posição X do vetor original for igual à nota da posição X
   do vetor ordenado, significa que ele já está no lugar certo e é contabilizado.
*/

#include <stdio.h>

int main() {
    int numCases;
    
    scanf("%d", &numCases);

    for (int i = 0; i < numCases; i++) {
        int numStudents;
        
        scanf("%d", &numStudents);
        int originalGrades[numStudents], sortedGrades[numStudents];

        // Lê as notas e preenche o vetor original e a cópia
        for (int j = 0; j < numStudents; j++) {
            scanf("%d", &originalGrades[j]);
            sortedGrades[j] = originalGrades[j]; 
        }

        // Algoritmo Bubble Sort para ordenar o vetor copiado em ordem decrescente
        for (int a = 0; a < numStudents - 1; a++) {
            
            for (int b = 0; b < numStudents - 1 - a; b++) {
                
                // Se o elemento atual for menor que o próximo, troca
                if (sortedGrades[b] < sortedGrades[b + 1]) { 
                    int temp = sortedGrades[b];
                    sortedGrades[b] = sortedGrades[b + 1];
                    sortedGrades[b + 1] = temp;
                }
            }
        }

        int correctCount = 0;
        // Compara os vetores para contar quantos alunos já estavam na posição correta
        for (int a = 0; a < numStudents; a++) {
            if (originalGrades[a] == sortedGrades[a]) 
                correctCount++;
        }

        printf("%d\n", correctCount);
    }

    return 0;
}