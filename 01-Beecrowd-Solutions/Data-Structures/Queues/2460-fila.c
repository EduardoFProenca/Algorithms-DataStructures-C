/*
Beecrowd : 2460 - Fila
https://judge.beecrowd.com/pt/problems/view/2460

**Explicação do Código:**
Este programa simula a manutenção de uma fila de pessoas (representadas por números inteiros).
O funcionamento é o seguinte:
1. Lê a quantidade inicial de pessoas na fila (N) e seus identificadores, inserindo-os na lista.
2. Lê a quantidade de pessoas que sairão da fila (M) e seus identificadores.
3. Para cada identificador de saída, busca a pessoa na lista e a remove.
4. Ao final, imprime os identificadores das pessoas que permaneceram na fila, na ordem original.

O programa utiliza uma lista encadeada simples para gerenciar a fila.
*/

#include <stdio.h>
#include <stdlib.h>

#define TRUE	1
#define FALSE	0
#define MEMORY_ERROR	2
#define EXEC_SUCCESS	0

// Estrutura que representa um nó (uma pessoa) na lista
struct Node
{
    int value;              // Identificador da pessoa
    struct Node *next;      // Ponteiro para a próxima pessoa na fila
};
typedef struct Node TNode;

// Estrutura descritora da lista (Fila)
typedef struct
{
    TNode *head;            // Início da fila
    TNode *tail;            // Fim da fila
    int count;              // Quantidade de pessoas na fila
    int sum;                // Soma dos valores (mantida pela lógica original, mas não usada)
} TList;

// Protótipos das funções
void DestroyList(TList *);
int RemoveItem(TList *, int);
void PrintList(TList *);
int AddItem(TList *, int);
void InitializeList(TList *);

int main(void)
{
    int number;
    TList queue; // 'queue' representa a fila de pessoas

    InitializeList(&queue);
    int n;
    scanf("%d", &n);
    
    // Lê as N pessoas iniciais e insere na fila
    for(int i = 0 ; i < n; i++)
    {
        scanf("%d", &number);

        if (AddItem(&queue, number) == FALSE)
        {
            puts("Erro fatal: Memoria insuficiente para esta operacao");
            return MEMORY_ERROR;
        }
    }

    int m;
    scanf("%d", &m);
    
    // Lê as M pessoas que sairão e as remove da fila
    for(int i = 0; i < m ; i++ )
    {
        scanf("%d", &number);

        if (RemoveItem(&queue, number) == FALSE)
            puts("Valor informado nao existe na lista");
    }
    
    // Imprime a fila final
    PrintList(&queue);
    DestroyList(&queue);

    return EXEC_SUCCESS;
}

// Função para liberar a memória de toda a lista
void DestroyList(TList *list)
{
    TNode *current, *nextNode;

    current = list->head;
    while (current != NULL)
    {
        nextNode = current->next;
        free(current);
        current = nextNode;
    }

    // Reinicia os descritores da lista
    InitializeList(list);
}

// Função para remover um item específico da lista pelo valor
int RemoveItem(TList *list, int value)
{
    TNode *current, *previous;

    /* Pesquisando na lista o item a ser excluido */
    previous = NULL;
    current = list->head;
    
    // Percorre a lista até encontrar o valor ou chegar ao fim
    while (current != NULL && current->value != value)
    {
        previous = current;
        current = current->next;
    }

    /* Removendo da lista o item solicitado */
    if (current == NULL)
        return FALSE; // Valor não encontrado
    else
    {
        /* Acertando o encadeamento na lista */
        if (previous == NULL)
            list->head = current->next; // Remove do início
        else
            previous->next = current->next; // Remove do meio ou fim

        /* atualizando os descritores complementares */
        list->count = list->count - 1;
        list->sum = list->sum - current->value;

        // Se o removido era o último, atualiza o ponteiro 'tail'
        if (current == list->tail)
            list->tail = previous;

        free(current);
    }

    return TRUE;
}

// Função para imprimir os elementos da lista
void PrintList(TList *list)
{
    TNode *current;

    /* imprimindo os valores da lista */
    if (list->head == NULL)
        puts("Lista vazia");
    else
    {
        current = list->head;
        while (current != NULL)
        {
            printf("%d", current->value);
            current = current->next;
            if(current != NULL)
                printf(" "); // Imprime espaço entre números, exceto após o último
        }
    }
    printf("\n");
}

// Função para inicializar os descritores da lista
void InitializeList(TList *list)
{
    list->head = NULL;
    list->tail = NULL;
    list->count = 0;
    list->sum = 0;
}

// Função para adicionar um novo item ao final da lista
int AddItem(TList *list, int value)
{
    TNode *newNode;

    /* criando uma variável struct Node dinamicamente */
    newNode = (TNode *) malloc(sizeof(TNode));

    if (newNode == NULL)
        return TRUE; // Nota: A lógica original retorna TRUE mesmo em erro de alocação

    /* preenchendo os campos da variável criada dinamicamente */
    newNode->value = value;
    newNode->next = NULL;

    /* fazendo o encadeamento do novo item na lista */
    if (list->head == NULL)
        list->head = newNode; // Se estava vazia, o novo nó é o cabeça
    else
        list->tail->next = newNode; // Adiciona após o último nó

    /* atualizando os descritores complementares */
    list->count = list->count + 1;
    list->sum = list->sum + newNode->value;
    list->tail = newNode; // Atualiza o ponteiro de fim para o novo nó

    return TRUE;
}