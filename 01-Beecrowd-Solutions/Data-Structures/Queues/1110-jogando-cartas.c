/*
Beecrowd : 1110 - Jogando Cartas Fora
https://judge.beecrowd.com/pt/problems/view/1110

**Explicação do Código:**
Este programa simula o processo de descartar cartas de um baralho.
O problema propõe um jogo onde as cartas são numeradas de 1 a N.
O processo se repete até que reste apenas uma carta:
1. A carta do topo é descartada.
2. A próxima carta do topo é movida para o final da pilha (fila).

O código utiliza uma estrutura de **Fila (Queue)** implementada com lista encadeada.
Embora a estrutura original se chame "Pilha" no código, a lógica de inserção no fim
(`IncluiItem`) e remoção no início (`ExcluiItem`) caracteriza o comportamento de uma Fila (FIFO).
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TRUE	1
#define FALSE	0
#define EXEC_SUCCESS	0
#define MEMORY_ERROR	2

// Estrutura que representa um nó (uma carta) na lista encadeada
struct Node
{
    int value;                // Valor da carta
    struct Node *next;        // Ponteiro para o próximo nó
};
typedef struct Node TNode;

// Estrutura descritora da fila (controla o início, fim e quantidade)
struct QueueDesc
{
    TNode *front;             // Ponteiro para o início da fila (topo)
    TNode *rear;              // Ponteiro para o fim da fila
    int count;                // Quantidade de elementos na fila
};
typedef struct QueueDesc TQueue;

// Protótipos das funções
int Dequeue(TQueue *, int);          // Remove item do início
void InitializeQueue(TQueue *);      // Inicializa a fila
int Enqueue(TQueue *, int);          // Adiciona item ao final

int main(void)
{
    TQueue deck; // 'deck' representa o baralho
    InitializeQueue(&deck);

    int n, discardedCard;

    // Loop principal que lê os casos de teste até que N seja 0
    while (1) {
        scanf("%d", &n);
        if (n == 0)
            break;

        // Popula o baralho (fila) com cartas de 1 a N
        for(int i = 1; i <= n ; i++)
            Enqueue(&deck, i);

        printf("Discarded cards:");

        // Loop do jogo: continua enquanto houver mais de 1 carta no baralho
        while(deck.count > 1) {
            // Passo 1: Pega a carta do topo para descarte
            discardedCard = deck.front->value;
            printf(" %d", discardedCard);
            
            // Remove a carta do topo (descarta-a)
            Dequeue(&deck, discardedCard);
            
            // Passo 2: Pega a nova carta do topo (que agora virou a primeira)
            discardedCard = deck.front->value;
            
            // Adiciona essa carta ao final da fila (move-a para o fundo)
            Enqueue(&deck, discardedCard);
            
            // Remove a carta do início (efetivamente avança a fila)
            // Nota: Dequeue remove sempre do 'front', que agora contém a carta subsequente
            Dequeue(&deck, discardedCard);
            
            // Se ainda houver cartas para processar, imprime vírgula
            if(deck.count > 1)
                printf(",");
        }
        
        // Ao sair do loop, sobra apenas uma carta no baralho
        discardedCard = deck.front->value;
        printf("\n");
        printf("Remaining card: %d\n", discardedCard);
        
        // Limpa o baralho para o próximo caso de teste
        Dequeue(&deck, discardedCard);
    }

    return EXEC_SUCCESS;
}

// Função para inicializar os ponteiros da fila como vazios
void InitializeQueue(TQueue *queue) {
    queue->front = NULL;
    queue->rear = NULL;
    queue->count = 0;
}

// Função para adicionar um item (Enqueue) ao final da fila
int Enqueue(TQueue *queue, int value) {
    TNode *newNode = (TNode *) malloc(sizeof(TNode));

    if (newNode == NULL) {
        puts("Erro fatal: Memoria insuficiente para esta operacao");
        return MEMORY_ERROR;
    }
    newNode->value = value;
    newNode->next = NULL;

    // Se a fila está vazia, o novo nó é tanto o front quanto o rear
    if (queue->rear == NULL) {
        queue->front = queue->rear = newNode;
    } else {
        // Caso contrário, insere após o rear e atualiza o rear
        queue->rear->next = newNode;
        queue->rear = newNode;
    }
    queue->count++;
    return TRUE;
}

// Função para remover um item (Dequeue) do início da fila
// Nota: O parâmetro 'value' é recebido mas não usado na busca, 
// pois a remoção é sempre feita no front (FIFO).
int Dequeue(TQueue *queue, int value) {
    if (queue->front == NULL) {
        return FALSE;
    }
    
    // Armazena o nó atual para liberar a memória depois
    TNode *tempNode = queue->front;

    // Move o front para o próximo nó
    queue->front = queue->front->next;
    
    // Se a fila ficou vazia, ajusta o rear também
    if (queue->front == NULL) {
        queue->rear = NULL;
    }
    
    free(tempNode);
    queue->count--;
    return TRUE;
}