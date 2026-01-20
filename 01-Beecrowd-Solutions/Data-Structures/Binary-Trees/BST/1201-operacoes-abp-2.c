/*
Beecrowd : 1201 - Operações em ABP II
https://judge.beecrowd.com/pt/problems/view/1201

**Explicação do Código:**
Este programa implementa uma Árvore Binária de Busca (BST) com operações avançadas de inserção, pesquisa e remoção.
Além disso, permite a impressão da árvore em três ordens: Pré-ordem, Em-ordem (Infixa) e Pós-ordem.

A estrutura do nó inclui um ponteiro para o nó pai (*parent), o que facilita a operação de remoção.

As operações suportadas são:
- "I X": Insere o inteiro X na árvore.
- "P X": Pesquisa se X existe na árvore. Imprime "X existe" ou "X nao existe".
- "R X": Remove o inteiro X da árvore, mantendo as propriedades da BST.
  A remoção trata três casos:
  1. Nó folha (sem filhos).
  2. Nó com apenas um filho.
  3. Nó com dois filhos (substitui pelo antecessor).
- "PREFIXA", "INFIXA", "POSFIXA": Imprimem a árvore na ordem correspondente.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FALSE 0
#define TRUE 1

// Estrutura do nó da árvore binária
struct TreeNode
{
    struct TreeNode *left;  // Ponteiro para o filho à esquerda
    int value;             // Valor armazenado no nó
    struct TreeNode *parent;// Ponteiro para o nó pai
    struct TreeNode *right; // Ponteiro para o filho à direita
};
typedef struct TreeNode TNode;

// Protótipos das funções
int SearchValue(TNode *, int);
TNode *RemoveNode(TNode *, int);
TNode *FindParent(TNode *, int);
void PrintPreOrder(TNode *r, int *isFirst);
void PrintInOrder(TNode *r, int *isFirst);
void PrintPostOrder(TNode *r, int *isFirst);
int InsertNode(TNode **, int);
void FreeTree(TNode *r);

int main(void)
{
    TNode *root = NULL;
    char command[8];
    int number;

    // Loop que lê comandos até o fim do arquivo (EOF)
    while (scanf(" %s", command) != EOF)
    {

        if (strcmp("INFIXA", command) == 0)
        {
            int isFirst = 0;
            PrintInOrder(root, &isFirst);
            printf("\n");
        }
        else if ('I' == command[0]) // Comando de Inserção
        {
            scanf(" %d", &number);
            if (InsertNode(&root, number) == FALSE)
            {
                puts("Memoria insuficiente para inclusao");
                return 2;
            }
        }
        if (strcmp("PREFIXA", command) == 0)
        {
            int isFirst = 0;
            PrintPreOrder(root, &isFirst);
            printf("\n");
        }
        else if (strcmp("POSFIXA", command) == 0)
        {
            int isFirst = 0;
            PrintPostOrder(root, &isFirst);
            printf("\n");
        }
        else if (command[0] == 'P') // Comando de Pesquisa
        {
            scanf(" %d", &number);
            if (SearchValue(root, number) != FALSE)
                printf("%d existe\n", number);
            else
                printf("%d nao existe\n", number);
        }
        if (command[0] == 'R') // Comando de Remoção
        {
            scanf(" %d", &number);
            root = RemoveNode(root, number);
        }
    }

    // Libera a memória ao final
    FreeTree(root);
    root = NULL;
    return 0;
}

// Função para inserir um novo nó
int InsertNode(TNode **rootRef, int n)
{
    TNode *newNode, *parent;

    newNode = (TNode *)malloc(sizeof(TNode));
    if (newNode == NULL)
        return FALSE;

    newNode->value = n;
    newNode->right = NULL;
    newNode->left = NULL;
    newNode->parent = NULL; // Inicializa o pai como NULL

    /* Encontra o pai do novo nó para fazer o encadeamento */
    parent = FindParent(*rootRef, n);
    if (parent == NULL)
    {
        *rootRef = newNode; // Se não tem pai, é a raiz
        newNode->parent = NULL;
    }
    else
    {
        if (n <= parent->value)
            parent->left = newNode;
        else
            parent->right = newNode;
        newNode->parent = parent; // Define o pai do novo nó
    }
    return TRUE;
}

// Função para encontrar o pai onde o nó deve ser inserido
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

// Impressão em Pré-ordem (Raiz, Esq, Dir)
void PrintPreOrder(TNode *r, int *isFirst)
{
    if (r != NULL)
    {
        if (*isFirst == 0)
        {
            printf("%d", r->value);
            *isFirst = 1;
        }
        else
            printf(" %d", r->value);

        PrintPreOrder(r->left, isFirst);
        PrintPreOrder(r->right, isFirst);
    }
}

// Impressão Em-ordem (Esq, Raiz, Dir)
void PrintInOrder(TNode *r, int *isFirst)
{
    if (r != NULL)
    {
        PrintInOrder(r->left, isFirst);

        if (*isFirst == 0)
        {
            printf("%d", r->value);
            *isFirst = 1;
        }
        else
            printf(" %d", r->value);

        PrintInOrder(r->right, isFirst);
    }
}

// Impressão Pós-ordem (Esq, Dir, Raiz)
void PrintPostOrder(TNode *r, int *isFirst)
{
    if (r != NULL)
    {
        PrintPostOrder(r->left, isFirst);
        PrintPostOrder(r->right, isFirst);

        if (*isFirst == 0)
        {
            printf("%d", r->value);
            *isFirst = 1;
        }
        else
            printf(" %d", r->value);
    }
}

// Libera a memória da árvore
void FreeTree(TNode *r)
{
    if (r != NULL)
    {
        FreeTree(r->left);
        FreeTree(r->right);
        free(r);
    }
}

// Função de busca (retorna TRUE ou FALSE)
int SearchValue(TNode *r, int n)
{
    if (r == NULL)
        return FALSE;
    else if (r->value == n)
        return TRUE;
    else if (r->value > n)
        return SearchValue(r->left, n);
    else
        return SearchValue(r->right, n);
}

// Função de remoção de um nó
TNode *RemoveNode(TNode *r, int n)
{
    if (r == NULL)
        return NULL;

    if (r->value == n)
    {
        /* Caso 1 e 2: sem filhos (folha) ou um filho */
        if (r->left == NULL && r->right == NULL) // Caso 1: Nó folha
        {
            if (r->parent != NULL) // Se não for a raiz, atualiza o pai
            {
                if (r->parent->left == r)
                    r->parent->left = NULL;
                else
                    r->parent->right = NULL;
            }
            free(r);
            return NULL; // Retorna NULL para o pai (se for chamado recursivamente)
        }
        else if (r->left == NULL || r->right == NULL) // Caso 2: Um filho
        {
            TNode *child;
            child = (r->left != NULL) ? r->left : r->right;

            if (r->parent != NULL)
            {
                // Conecta o filho diretamente ao pai do nó removido
                if (r->parent->left == r)
                    r->parent->left = child;
                else
                    r->parent->right = child;
                child->parent = r->parent;
            }
            else
            {
                // Se for a raiz, o filho se torna a nova raiz (sem pai)
                child->parent = NULL;
            }
            free(r);
            return child; // Retorna o filho para subir na árvore
        }
        /* Caso 3: dois filhos - usar ANTECESSOR */
        else
        {
            TNode *predecessor;
            // O antecessor é o maior valor da subárvore esquerda (mais à direita)
            predecessor = r->left;

            while (predecessor->right != NULL)
            {
                predecessor = predecessor->right;
            }

            // Copia o valor do antecessor para o nó atual
            r->value = predecessor->value;
            
            // Remove recursivamente o antecessor da subárvore esquerda
            r->left = RemoveNode(r->left, predecessor->value);
            return r;
        }
    }
    else
    {
        // Navega na árvore para encontrar o nó a ser removido
        if (n < r->value)
            r->left = RemoveNode(r->left, n);
        else
            r->right = RemoveNode(r->right, n);
        return r;
    }
}