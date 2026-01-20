/*
Beecrowd : 1195 - Árvore Binária de Busca
https://judge.beecrowd.com/pt/problems/view/1195

**Explicação do Código:**
Este programa resolve o problema de construir e percorrer Árvores Binárias de Busca (BST).

O fluxo do programa é:
1. Lê o número de casos de teste (C).
2. Para cada caso:
   a. Lê a quantidade de números (N) a serem inseridos na árvore.
   b. Insere cada número na árvore seguindo a regra da BST:
      - Se o número for menor ou igual ao nó atual, vai para a esquerda.
      - Se for maior, vai para a direita.
   c. Imprime a sequência de visitação da árvore em três ordens diferentes:
      - Pré-ordem (Pre): Raiz -> Esquerda -> Direita.
      - Em-ordem (In): Esquerda -> Raiz -> Direita.
      - Pós-ordem (Post): Esquerda -> Direita -> Raiz.
   d. Libera a memória alocada para a árvore antes do próximo caso.
*/

#include <stdio.h>
#include <stdlib.h>

#define FALSE	0
#define TRUE	1

// Estrutura do nó da árvore binária
struct TreeNode
{
    struct TreeNode *left; // Ponteiro para o filho à esquerda
    int value;             // Valor armazenado no nó
    struct TreeNode *right;// Ponteiro para o filho à direita
};
typedef struct TreeNode TNode;

// Protótipos das funções utilizadas
TNode *FindParent(TNode *, int);
void PrintPreOrder(TNode *r, int level);
void PrintInOrder(TNode *r, int level);
void PrintPostOrder(TNode *r, int level);
int CountNodes(TNode *);
int InsertNode(TNode **, int);
void DestroyTree(TNode *r, int level);

int main(void)
{
    TNode *root = NULL;
    int number, numNodes, cases;
    scanf("%d", &cases);
    
    for(int i = 0; i < cases; i++) {
        
        scanf("%d", &numNodes);

        for(int j = 0; j < numNodes; j++) {
            scanf("%d", &number);

            // Tenta inserir o número na árvore
            if (InsertNode(&root, number) == FALSE) {
                puts("Memoria insuficiente para inclusao");
                return 2;
            }
        }
        
        // Imprime os resultados para o caso atual
        printf("Case %d:\n", i+1);
        printf("Pre.:");
        PrintPreOrder(root, 0);
        printf("\n");
        printf("In..:");
        PrintInOrder(root, 0);
        printf("\n");
        printf("Post:");
        PrintPostOrder(root, 0);
        printf("\n\n");
        
        // Libera a memória da árvore atual para preparar o próximo teste
        DestroyTree(root, 0);
        root = NULL;
    }
    return 0;
}

// Função para inserir um novo nó na árvore
int InsertNode(TNode **rootRef, int val)
{
    TNode *newNode, *parent;

    // Aloca memória para o novo nó
    newNode = (TNode *) malloc(sizeof(TNode));
    if (newNode == NULL)
        return FALSE;

    newNode->value = val;
    newNode->right = NULL;
    newNode->left = NULL;

    /* Encontra o pai do novo nó para fazer o encadeamento */
    parent = FindParent(*rootRef, val);
    
    if (parent == NULL)
        *rootRef = newNode; // A árvore estava vazia, este é o novo root
    else if (val <= parent->value)
        parent->left = newNode; // Insere à esquerda
    else
        parent->right = newNode; // Insere à direita

    return TRUE;
}

// Função auxiliar recursiva para encontrar onde o novo nó deve ser inserido
TNode *FindParent(TNode *node, int val)
{
    if (node == NULL)
        return NULL;
    else if (val <= node->value)
        /* val é descendente do lado esquerdo de node */
        if (node->left == NULL)
            return node;
        else
            return FindParent(node->left, val);
    else
        /* val é descendente do lado direito de node */
        if (node->right == NULL)
            return node;
        else
            return FindParent(node->right, val);
}

// Impressão em Pré-ordem (Raiz, Esq, Dir)
void PrintPreOrder(TNode *r, int level)
{
    if (r != NULL) {
        printf(" %d", r->value);
        PrintPreOrder(r->left, level + 1);
        PrintPreOrder(r->right, level + 1);
    }
}

// Impressão Em-ordem (Esq, Raiz, Dir)
void PrintInOrder(TNode *r, int level)
{
    if (r != NULL) {
        PrintInOrder(r->left, level + 1);
        printf(" %d", r->value);
        PrintInOrder(r->right, level + 1);
    }
}

// Impressão Pós-ordem (Esq, Dir, Raiz)
void PrintPostOrder(TNode *r, int level)
{
    if (r != NULL) {
        PrintPostOrder(r->left, level + 1);
        PrintPostOrder(r->right, level + 1);
        printf(" %d", r->value);
    }
}

// Conta o total de nós (não utilizado no main, mas mantido)
int CountNodes(TNode *r)
{
    if (r == NULL)
        return 0;
    else
        return 1 + CountNodes(r->left) + CountNodes(r->right);
}

// Libera a memória da árvore recursivamente
void DestroyTree(TNode *r, int level)
{
    if(r != NULL) {
        DestroyTree(r->left, level + 1);
        DestroyTree(r->right, level + 1);
        free(r);
    }
}