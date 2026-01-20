/*
Beecrowd : 1062 - Trilhos
https://judge.beecrowd.com/pt/problems/view/1062

**Explicação do Código:**
Este programa simula a organização de vagões de trem em uma estação ferroviária.
O problema consiste em verificar se uma determinada permutação de vagões (de 1 a N) 
pode ser obtida usando uma pilha (o pátio da estação).

A lógica funciona da seguinte maneira:
1. Os vagões entram na estação em ordem crescente (1, 2, 3, ... N).
2. O objetivo é fazer com que eles saiam na ordem especificada pelo vetor "permutacao".
3. O algoritmo usa uma pilha ("station") para reorganizar os vagões:
   - Empilha (Push) os vagões vindos da entrada até que o vagão desejado esteja no topo da pilha.
   - Se o vagão desejado estiver no topo, ele é desempilhado (Pop).
   - Se a fila de entrada acabar e o vagão do topo não for o desejado, a ordem é impossível ("No").
   - Se todos os vagões forem processados com sucesso, a ordem é possível ("Yes").
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TRUE	1
#define FALSE	0
#define EXEC_SUCCESS	0
#define MEMORY_ERROR	2

// Estrutura do nó da pilha
struct Node
{
    int value;
    struct Node *next;
};
typedef struct Node TNode;

// Estrutura descritora da pilha
struct Stack
{
    TNode *top;    // Topo da pilha
    TNode *bottom; // Fundo da pilha (não utilizado ativamente na lógica de push/pop deste código)
    int count;     // Quantidade de elementos
};
typedef struct Stack TStack;

// Protótipos das funções
int Pop(TStack *, int);
void InitializeStack(TStack *);
int Push(TStack *, int);

int main(void)
{
    int numWagons;
    int firstFlag = 1; // Variável de controle (renomeada de 'pri', mantendo a lógica original)

    while (1) {
        scanf("%d", &numWagons);
        if (numWagons == 0)
            break;

        firstFlag = 0;

        while (1) {
            int firstValue;
            scanf("%d", &firstValue);
            if (firstValue == 0)
                break;

            int permutation[1000];
            permutation[0] = firstValue;
            
            // Lê a sequência desejada de vagões
            for (int i = 1; i < numWagons; i++) 
                scanf("%d", &permutation[i]);
            

            TStack station; // A estação é simulada como uma pilha
            InitializeStack(&station);

            int nextIncoming = 1;    // Próximo vagão que chega na entrada (1 até N)
            int isPossible = TRUE;  // Flag para verificar se a permutação é válida

            for (int i = 0; i < numWagons; i++) {
                int target = permutation[i]; // O vagão que queremos retirar agora

                // Enquanto o topo da pilha não for o alvo e ainda houver vagões entrando:
                // Empilhe os vagões da entrada na estação.
                while ((station.top == NULL || station.top->value != target) && nextIncoming <= numWagons) {
                    Push(&station, nextIncoming);
                    nextIncoming++;
                }

                // Se o topo da pilha agora é o alvo, remova-o (desempilhe)
                if (station.top != NULL && station.top->value == target)
                    Pop(&station, target);
                else {
                    // Se não tem mais vagões para entrar e o topo não é o alvo, é impossível
                    isPossible = FALSE;
                    break;
                }

            }

            if (isPossible)
                printf("Yes\n");
            else
                printf("No\n");

        }
        printf("\n");
    }

    return EXEC_SUCCESS;
}

// Inicializa a pilha
void InitializeStack(TStack *stack) {
    stack->top = NULL;
    stack->count = 0;
}

// Empilha um vagão (Push)
int Push(TStack *stack, int value) {
    TNode *newNode;

    newNode = (TNode *) malloc(sizeof(TNode));
    if (newNode == NULL) {
        puts("Erro fatal: Memoria insuficiente para esta operacao");
        return MEMORY_ERROR;
    }

    newNode->value = value;
    newNode->next = stack->top; // Insere no topo (LIFO)

    stack->top = newNode;
    stack->count++;
    return TRUE;
}

// Desempilha um vagão (Pop)
int Pop(TStack *stack, int value) {
    TNode *temp;

    if (stack->top == NULL) {
        return FALSE;
    }
    else if (stack->top->value == value) // Só remove se o valor corresponder
    {
        temp = stack->top;
        stack->top = stack->top->next;
        stack->count--;
        free(temp);
        return TRUE;
    }
    else
        return FALSE;
}