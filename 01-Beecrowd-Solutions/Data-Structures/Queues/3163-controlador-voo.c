/*
Beecrowd : 3163 - Controlador de Vôo
https://judge.beecrowd.com/pt/problems/view/3163

**Explicação do Código:**
Este programa simula um sistema de gerenciamento de voos onde as aeronaves (ou passageiros)
possuem códigos de identificação e prioridades numéricas.

O processo funciona da seguinte maneira:
1. O programa lê códigos de voo e suas prioridades (números inteiros).
2. Com base na prioridade, os códigos são separados em 4 filas distintas (Queues):
   - Prioridade -1: Fila 1
   - Prioridade -2: Fila 2
   - Prioridade -3: Fila 3
   - Prioridade -4: Fila 4
3. Em seguida, o programa esvazia essas 4 filas em uma ordem específica de atendimento
   para uma fila final (Fila 5):
   - Primeiro, todos da Fila 1.
   - Depois, todos da Fila 3.
   - Depois, todos da Fila 2.
   - Por fim, todos da Fila 4.
4. Por último, imprime a lista final de códigos de voo na ordem de embarque.

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TRUE	1
#define FALSE	0
#define EXEC_SUCCESS	0
#define MEMORY_ERROR	2

// Estrutura do nó da fila (lista encadeada)
struct Node
{
    char value[10];       // Armazena o código do voo
    struct Node *next;    // Ponteiro para o próximo elemento
};
typedef struct Node TNode;

// Descritor da fila (controla o início, fim e quantidade)
struct Queue
{
    TNode *front;         // Início da fila (topo)
    TNode *rear;          // Fim da fila
    int count;            // Quantidade de itens na fila
};
typedef struct Queue TQueue;

// Protótipos das funções
int Dequeue(TQueue *, char *);
void InitializeQueue(TQueue *);
int Enqueue(TQueue *, char *);

int main(void)
{
    // 5 filas: 4 temporárias para prioridades e 1 final
    TQueue queue1, queue2, queue3, queue4, finalQueue;
    
    InitializeQueue(&queue1); 
    InitializeQueue(&queue2); 
    InitializeQueue(&queue3); 
    InitializeQueue(&queue4); 
    InitializeQueue(&finalQueue); 

    char flightCode[10];
    int priority;

    while (1) {
        scanf("%d", &priority);
        if (priority == 0) 
            break;
            
        scanf("%s", flightCode);

        // Distribuição nas filas baseada na prioridade (número negativo)
        if (priority == -1)
            Enqueue(&queue1, flightCode);
        else if (priority == -2)
            Enqueue(&queue2, flightCode);
        else if (priority == -3)
            Enqueue(&queue3, flightCode);
        else if (priority == -4)
            Enqueue(&queue4, flightCode);
    }

    // Consolidação das filas na fila final na ordem específica: 1 -> 3 -> 2 -> 4
    while (queue1.count > 0 || queue3.count > 0 || queue2.count > 0 || queue4.count > 0) {
        
        if (queue1.count > 0) {
            strcpy(flightCode, queue1.front->value);
            Dequeue(&queue1, flightCode); // Remove da fila 1
            Enqueue(&finalQueue, flightCode); // Adiciona na fila final
        }
        if (queue3.count > 0) {
            strcpy(flightCode, queue3.front->value);
            Dequeue(&queue3, flightCode);
            Enqueue(&finalQueue, flightCode);
        }
        if (queue2.count > 0) {
            strcpy(flightCode, queue2.front->value);
            Dequeue(&queue2, flightCode);
            Enqueue(&finalQueue, flightCode);
        }
        if (queue4.count > 0) {
            strcpy(flightCode, queue4.front->value);
            Dequeue(&queue4, flightCode);
            Enqueue(&finalQueue, flightCode);
        }
    }

    // Impressão da fila final
    TNode *current = finalQueue.front;
    int isFirst = 1;
    
    while (current != NULL) {
        if (!isFirst) 
            printf(" "); // Adiciona espaço entre os códigos, exceto antes do primeiro
        printf("%s", current->value);
        isFirst = 0;
        current = current->next;
    }
    printf("\n");

    return EXEC_SUCCESS;
}

// Inicializa os ponteiros da fila como vazios
void InitializeQueue(TQueue *queue) {
    queue->front = NULL;
    queue->rear = NULL;  
    queue->count = 0;
}

// Adiciona um item ao final da fila (Enqueue)
int Enqueue(TQueue *queue, char *value) {
    TNode *newNode = (TNode *) malloc(sizeof(TNode));
    
    if (newNode == NULL) {
        puts("Erro fatal: Memoria insuficiente para esta operacao");
        return MEMORY_ERROR;
    }
    strcpy(newNode->value, value);
    newNode->next = NULL;

    if (queue->rear == NULL) {
        // Se a fila estava vazia, o novo nó é o front e o rear
        queue->front = queue->rear = newNode;
    } else {
        // Adiciona ao final e atualiza o rear
        queue->rear->next = newNode;
        queue->rear = newNode;
    }
    queue->count++;
    return TRUE;
}

// Remove um item do início da fila (Dequeue)
// mas a função sempre remove do front (início).
int Dequeue(TQueue *queue, char *value) {
    if (queue->front == NULL) {
        return FALSE;
    }
    TNode *temp = queue->front;
    
    // Move o front para o próximo nó
    queue->front = queue->front->next;
    
    if (queue->front == NULL) {
        // Se a fila ficou vazia, o rear também deve ser NULL
        queue->rear = NULL;
    }
    
    free(temp);
    queue->count--;
    return TRUE;
}