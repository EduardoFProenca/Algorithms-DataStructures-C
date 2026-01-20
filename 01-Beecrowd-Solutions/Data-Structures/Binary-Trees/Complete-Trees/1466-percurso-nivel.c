/*
Beecrowd : 1466 - Percurso em Árvore por Nível
https://judge.beecrowd.com/pt/problems/view/1466

**Explicação do Código:**
Este programa resolve o problema de percorrer uma Árvore Binária de Busca (BST) por nível (Level Order Traversal).
A travessia por nível visita os nós da árvore começando pela raiz, depois os nós no nível 1 (da esquerda para a direita),
e assim sucessivamente nível por nível.

Para implementar isso, o código utiliza uma estrutura de Fila (Queue):
1. Insere os números na árvore seguindo a lógica de BST (menores à esquerda, maiores à direita).
2. Imprime a árvore em nível:
   a. Enfileira a raiz.
   b. Enquanto a fila não estiver vazia:
      i. Desenfileira um nó.
      ii. Imprime o valor do nó.
      iii. Enfileira os filhos à esquerda e à direita desse nó (se existirem).
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
    int value;             // Valor do nó
    struct TreeNode *right;// Filho à direita
};
typedef struct TreeNode TNode;

// Estrutura do nó da fila (lista encadeada usada como fila)
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
int ExcludeItemQueue(TQueue *, char *); // Mantido conforme original, não utilizado no corpo
void InitializeQueue(TQueue *);
int Enqueue(TQueue *, TNode *);
TNode *Dequeue(TQueue *);

TNode *FindParent(TNode *, int);

void PrintLevelOrder(TNode *, int);
int InsertNode(TNode **, int);
void FreeTree(TNode *r, int n);

int main(void)
{
    TNode *root = NULL;
    int numCases, number, numNodes, caseIndex;
    
    scanf(" %d", &numCases);
    
    for(caseIndex = 0; caseIndex < numCases; caseIndex++) {
        scanf(" %d", &numNodes);

        for(int i = 0; i < numNodes; i++)
        {
            scanf("%d", &number);

            // Condicional original preservada
            if (number == -999)
                break;

            if (InsertNode(&root, number) == FALSE)
            {
                puts("Memoria insuficiente para inclusao");
                return 2;
            }
        }

        PrintLevelOrder(root, caseIndex+1);
        printf("\n\n");
        FreeTree(root, 0);
        root = NULL;
    }

    return 0;
}

// Função para inserir um novo valor na árvore
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

// Função de impressão em nível (Breadth-First Search)
void PrintLevelOrder(TNode *root, int caseNum)
{   
    int i = 0;
    TQueue queue;
    InitializeQueue(&queue);
    if (root != NULL)
    {
        // Adiciona a raiz na fila
        Enqueue(&queue, root);

        while(1)
        {
            // Remove o nó da frente da fila
            TNode *currentNode = Dequeue(&queue);
            if (currentNode == NULL)
                break;
            
            // Lógica de impressão original preservada:
            // Na primeira iteração, imprime o "Case" e o valor da raiz explicitamente
            if ( i == 0 ) {
                printf("Case %d:\n", caseNum);
                printf("%d", root->value);
                i++;
            }
            else
                printf(" %d", currentNode->value);
            

            // Adiciona os filhos à fila para processamento
            if (currentNode->left != NULL)
                Enqueue(&queue, currentNode->left);
            if (currentNode->right != NULL)
                Enqueue(&queue, currentNode->right);
        }
    }
}

/// Funções da Fila

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