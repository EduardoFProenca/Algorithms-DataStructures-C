/*
Beecrowd : 1200 - Operações em ABP I
https://judge.beecrowd.com/pt/problems/view/1200

**Explicação do Código:**
Este programa implementa uma Árvore Binária de Busca (BST) para manipular caracteres.
O programa lê comandos continuamente até o fim do arquivo (EOF) e executa operações específicas:

- "I X": Insere o caractere X na árvore. Se já existir, ele é inserido de acordo com a regra da BST
  (menores ou iguais à esquerda, maiores à direita).
- "P X": Pesquisa se o caractere X existe na árvore e imprime "X existe" ou "X nao existe".
- "PREFIXA": Imprime os elementos da árvore em pré-ordem (Raiz -> Esquerda -> Direita).
- "INFIXA": Imprime os elementos da árvore em ordem simétrica/infixa (Esquerda -> Raiz -> Direita).
- "POSFIXA": Imprime os elementos da árvore em pós-ordem (Esquerda -> Direita -> Raiz).

A formatação da impressão controla o espaçamento para garantir que não haja espaço antes do primeiro elemento.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FALSE	0
#define TRUE	1

// Estrutura do nó da árvore binária
struct TreeNode
{
    struct TreeNode *left; // Ponteiro para o filho à esquerda
    char value;            // Valor armazenado no nó (caractere)
    struct TreeNode *right;// Ponteiro para o filho à direita
};
typedef struct TreeNode TNode;

// Protótipos das funções
TNode *SearchNode(TNode *, char);
TNode *FindParent(TNode *, char);
void PrintPreOrder(TNode *r, int *isFirst);
void PrintInOrder(TNode *r, int *isFirst);
void PrintPostOrder(TNode *r, int *isFirst);
int InsertNode(TNode **, char);
void FreeTree(TNode *r);

int main(void)
{
    TNode *root = NULL;
    char command[8]; // Buffer para ler o comando (I, P, PREFIXA, etc.)
    char letter;

    // Loop que lê comandos até o fim do arquivo (EOF)
    while(scanf(" %s", command) != EOF) {

        if(strcmp("INFIXA", command) == 0) {
            int isFirst = 0; // Flag auxiliar para controlar o espaço antes do primeiro item
            PrintInOrder(root, &isFirst);
            printf("\n");
        } else if('I' == command[0]) { // Comando de Inserção (I)
            scanf(" %c", &letter);
            if (InsertNode(&root, letter) == FALSE)
            {
                puts("Memoria insuficiente para inclusao");
                return 2;
            }
        }

        if(strcmp("PREFIXA", command) == 0) {
            int isFirst = 0;
            PrintPreOrder(root, &isFirst);
            printf("\n");
        }
        else if (strcmp("POSFIXA", command) == 0) {
            int isFirst = 0;
            PrintPostOrder(root, &isFirst);
            printf("\n");
        }
        else if (command[0] == 'P') { // Comando de Pesquisa (P)
            scanf(" %c", &letter);
            if (SearchNode(root, letter) != NULL)
                printf("%c existe\n", letter);
            else
                printf("%c nao existe\n", letter);
        }
    }

    // Libera toda a memória alocada para a árvore ao final
    FreeTree(root);
    root = NULL;
    return 0;
}

// Função para inserir um novo nó na árvore
int InsertNode(TNode **rootRef, char n)
{
    TNode *newNode, *parent;

    // Aloca memória para o novo nó
    newNode = (TNode *) malloc(sizeof(TNode));
    if (newNode == NULL)
        return FALSE;

    newNode->value = n;
    newNode->right = NULL;
    newNode->left = NULL;

    /* Encontra o pai do novo nó para fazer o encadeamento */
    parent = FindParent(*rootRef, n);
    if (parent == NULL)
        *rootRef = newNode; // Se não tem pai, é a raiz
    else if (n <= parent->value)
        parent->left = newNode; // Insere à esquerda
    else
        parent->right = newNode; // Insere à direita

    return TRUE;
}

// Função recursiva para encontrar o local de inserção (pai do novo nó)
TNode *FindParent(TNode *r, char n)
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
        // Controle de impressão para não colocar espaço no primeiro elemento
        if(*isFirst == 0) {
            printf("%c", r->value);
            *isFirst = 1;
        } else
            printf(" %c", r->value);

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

        if(*isFirst == 0) {
            printf("%c", r->value);
            *isFirst = 1;
        } else
            printf(" %c", r->value);

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

        if(*isFirst == 0) {
            printf("%c", r->value);
            *isFirst = 1;
        } else
            printf(" %c", r->value);
    }
}

// Libera a memória da árvore recursivamente
void FreeTree(TNode *r)
{
    if(r != NULL)
    {
        FreeTree(r->left);
        FreeTree(r->right);
        free(r);
    }
}

// Função de busca para verificar se um caractere existe na árvore
TNode *SearchNode(TNode *r, char n) {
    if (r != NULL) {
         if( n > r->value )
            return SearchNode(r->right, n);
        else if( n < r->value )
            return SearchNode(r->left, n);
        else if (n == r->value)
            return r;
    }
    return NULL;
}