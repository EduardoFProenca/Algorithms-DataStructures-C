/*
Beecrowd : 3484 - Turma Dividida
https://judge.beecrowd.com/pt/problems/view/3484

**Explicação do Código:**
Este programa resolve o problema de analisar uma "Turma Dividida" representada por uma Árvore Binária de Busca (BST).
O objetivo é identificar o menor valor presente em cada nível da árvore.

O fluxo do algoritmo é:
1. Lê uma quantidade de números e os insere em uma Árvore Binária de Busca.
2. Percorre a árvore utilizando uma busca em largura (BFS - Level Order Traversal) por meio de uma Fila.
3. Para cada nível da árvore:
   - Processa todos os nós pertencentes a esse nível.
   - Encontra o menor valor (`min`) entre eles.
   - Imprime o número do nível e o menor valor encontrado.
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#define EXEC_SUCCESS 0
#define MEMORY_ERROR 2

#define TRUE 1
#define FALSE 0
#define QTDE_MAX 500

// Estrutura do nó da árvore binária
struct TreeNode
{
    struct TreeNode *left; // Filho à esquerda
    int value;             // Valor armazenado
    struct TreeNode *right;// Filho à direita
};
typedef struct TreeNode TNode;

// Estrutura do nó da fila (usada para BFS)
struct QueueNode
{
    TNode *value; // Ponteiro para o nó da árvore
    struct QueueNode *next;
};
typedef struct QueueNode TQueueNode;

// Descritor da fila
struct QueueDesc
{
    TQueueNode *front; // Início da fila
    TQueueNode *rear;  // Fim da fila
    int count;         // Quantidade de elementos
};
typedef struct QueueDesc TQueue;

// Protótipos das funções
int ExcludeItemQueue(TQueue *, char *); // Mantido conforme original
void InitializeQueue(TQueue *);
int Enqueue(TQueue *, TNode *);
TNode *Dequeue(TQueue *);

TNode *FindParent(TNode *, int);

void PrintTreeLevel(TNode *, int);
int InsertNode(TNode **, int);
void FreeTree(TNode *r, int n);

int main(void)
{
    TNode *root = NULL;
    int qt, number, n;

    scanf(" %d", &n);

    for(int i = 0; i < n ; i++)
    {
        //printf("\nInforme o valor:\n");
        scanf("%d", &number);

        if (number == -999)
            break;

        if (InsertNode(&root, number) == FALSE)
        {
            puts("Memoria insuficiente para inclusao");
            return 2;
        }
    }

    PrintTreeLevel(root, 0);
    FreeTree(root, 0);
    root = NULL;


    return 0;
}

// Função para inserir um novo nó na árvore
int InsertNode(TNode **rootRef, int n)
{
    TNode *newNode, *parent;

    newNode = (TNode *) malloc(sizeof(TNode));
    if (newNode == NULL)
        return FALSE;

    newNode->value = n;
    newNode->right = NULL;
    newNode->left = NULL;

    /* Fazendo o encadeamento do novo nó */
    parent = FindParent(*rootRef, n);
    if (parent == NULL)
        *rootRef = newNode; // Se não tem pai, é a raiz
    else if (n <= parent->value)
        parent->left = newNode;
    else
        parent->right = newNode;

    return TRUE;
}

// Função para encontrar o pai onde inserir o novo nó
TNode *FindParent(TNode *r, int n)
{
    if (r == NULL)
        return NULL;
    else if (n <= r->value)
        /* n é descendente do lado esquerdo de r */
        if (r->left == NULL)
            return r;
        else
            return FindParent(r->left, n);
    else
        /* n é descendente do lado direito de r */
        if (r->right == NULL)
            return r;
        else
            return FindParent(r->right, n);
}

// Função que imprime o menor valor por nível da árvore
void PrintTreeLevel(TNode *root, int unusedParam)
{
    TQueue queue;
    InitializeQueue(&queue);
    int level = 0;

    if (root != NULL)
        Enqueue(&queue, root);

    while (queue.count > 0)
    {
        // Número de nós no nível atual da árvore
        int nodesAtLevel = queue.count;
        // Inicializa o menor valor com um número alto conforme lógica original
        int min = 9999;

        // Processa todos os nós do nível atual
        for (int i = 0; i < nodesAtLevel; i++)
        {
            TNode *currentNode = Dequeue(&queue);
            
            // Atualiza o menor valor encontrado neste nível
            if (currentNode->value < min)
                min = currentNode->value;

            // Adiciona os filhos à fila para o próximo nível
            if (currentNode->left != NULL)
                Enqueue(&queue, currentNode->left);
            if (currentNode->right != NULL)
                Enqueue(&queue, currentNode->right);
        }

        // Imprime o nível e o menor valor encontrado nele
        printf("%d %d\n", level, min);
        level++;
    }
}

/// Funções da Fila (Queue)

void InitializeQueue(TQueue *queue)
{
    queue->front = NULL;
    queue->rear = NULL;
    queue->count = 0;
}

int Enqueue(TQueue *queue, TNode *nodeValue)
{
    TQueueNode *newNode = (TQueueNode *)malloc(sizeof(TQueueNode));

    if (newNode == NULL)
    {
        puts("Erro fatal: Memoria insuficiente para esta operacao");
        return MEMORY_ERROR;
    }
    newNode->value = nodeValue;
    newNode->next = NULL;

    if (queue->front == NULL)
    {
        queue->front = newNode;
        queue->rear = newNode;
    }
    else
    {
        queue->rear->next = newNode;
        queue->rear = newNode;
    }
    queue->count++;
    return TRUE;
}

TNode *Dequeue(TQueue *queue)
{
    if (queue->front == NULL)
        return NULL;

    TQueueNode *temp = queue->front;
    TNode *nodeValue = temp->value;

    queue->front = queue->front->next;

    if (queue->front == NULL)
        queue->rear = NULL;

    free(temp);
    queue->count--;

    return nodeValue;
}

// Função para liberar a memória da árvore
void FreeTree(TNode *r, int n)
{
    if(r != NULL)
    {
        FreeTree(r->left, n + 1);
        FreeTree(r->right, n + 1);
        free(r);
    }
}