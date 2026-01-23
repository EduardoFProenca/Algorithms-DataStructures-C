/*
 * Este programa verifica se uma sequência de números inseridos forma um Heap.
 * Ele funciona em duas etapas principais:
 *
 * 1. CONSTRUÇÃO DA ÁRVORE BINÁRIA COMPLETA:
 *    - Ao contrário de uma Árvore Binária de Busca (BST), onde valores definem
 *      a posição (esquerda < raiz < direita), este programa constrói uma
 *      "Complete Binary Tree" (Árvore Binária Completa).
 *    - Isso significa que a inserção ocorre nível por nível, da esquerda para
 *      a direita, preenchendo todos os espaços disponíveis.
 *    - A função `FindParent` usa uma fila estática para encontrar o primeiro
 *      nó com um "buraco" (filho esquerdo ou direito nulo) para inserir o novo nó.
 *
 * 2. VERIFICAÇÃO DE HEAP:
 *    - Uma vez que a árvore está preenchida com os valores, o programa verifica
 *      as propriedades de Heap recursivamente:
 *      - **Max-Heap**: O valor de todo nó pai deve ser **maior ou igual** aos seus filhos.
 *      - **Min-Heap**: O valor de todo nó pai deve ser **menor ou igual** aos seus filhos.
 *
 * O programa lê múltiplos casos de teste (encerrados por EOF) e imprime "max",
 * "min" ou "nada" para cada caso.
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Definição de constantes e valores booleanos
#define TRUE  1
#define FALSE 0
// Capacidade máxima para a fila estática auxiliar usada na busca do pai
#define MAX_QUEUE_SIZE 500

// Estrutura do Nó da Árvore Binária
struct Node
{
    struct Node *left;   // Ponteiro para o filho à esquerda
    int value;           // Valor armazenado no nó
    struct Node *parent; // Ponteiro para o nó pai
    struct Node *right;  // Ponteiro para o filho à direita
};
typedef struct Node TNode;

// Protótipos das funções
TNode *FindParent(TNode *, int);    // Encontra o local de inserção para manter árvore completa
int InsertNode(TNode **, int);       // Insere um valor na árvore
int CheckMaxHeap(TNode *);          // Verifica se a árvore é um Max-Heap
int CheckMinHeap(TNode *);          // Verifica se a árvore é um Min-Heap
void DestroyTree(TNode *);           // Libera a memória da árvore recursivamente

int main(void)
{
    TNode *root = NULL;
    int number, count;

    // Loop que lê múltiplos casos de teste até o fim do arquivo (EOF)
    while (scanf("%d", &count) != EOF) {
        // Reseta a raiz para cada novo caso de teste
        root = NULL;
        
        // Loop para ler e inserir 'count' números na árvore
        for(int i = 0; i < count; i++ )
        {   
            scanf("%d", &number);

            // Tenta inserir o número. Se falhar (memória cheia), encerra o programa.
            if (InsertNode(&root, number) == FALSE)
            {   
                puts("Memoria insuficiente para inclusao");
                return 2;
            }
        }
        
        // Verifica as propriedades de Heap após a construção da árvore
        if(CheckMaxHeap(root))
            printf("max\n");      // É um Max-Heap (Pai >= Filhos)
        else if (CheckMinHeap(root))
            printf("min\n");      // É um Min-Heap (Pai <= Filhos)
        else
            printf("nada\n");     // Não é nem Max nem Min Heap
        
        // Libera a memória alocada para a árvore atual antes de prosseguir
        DestroyTree(root);
    }
    return 0;
}

// Função que encontra o nó pai onde o novo valor deve ser inserido.
// Utiliza uma fila estática (array) para percorrer a árvore em nível (BFS),
// garantindo que a árvore seja uma "Complete Binary Tree" (cheia da esquerda para a direita).
TNode *FindParent(TNode *r, int n)
{   
    TNode *queueArray[MAX_QUEUE_SIZE], *current;
    int start, end;

    if (r == NULL)
        return NULL;

    start = end = 0;
    current = r;
    
    // Percorre a árvore enquanto o nó atual tiver ambos os filhos (esq e dir) ocupados
    while (current->left != NULL && current->right != NULL)
    {   
        // Adiciona os filhos à fila para processamento posterior
        queueArray[end++] = current->left;
        queueArray[end++] = current->right;
    
        // Pega o próximo nó da fila
        current = queueArray[start++];
    }
    
    // Retorna o nó que possui espaço vazio (esq ou dir) para receber o novo filho
    return current;
}

// Função que cria um novo nó e o insere na árvore
int InsertNode(TNode **r, int n)
{   
    TNode *newNode, *parentNode;

    // Aloca memória para o novo nó
    newNode = (TNode *) malloc(sizeof(TNode));
    if (newNode == NULL)
        return FALSE;

    newNode->value = n;
    newNode->right = NULL;
    newNode->left = NULL;
    newNode->parent = NULL;

    /* Fazendo o encadeamento do novo nó */
    parentNode = FindParent(*r, n);
    
    // Se não encontrou pai, a árvore estava vazia. O novo nó é a raiz.
    if (parentNode == NULL) 
        *r = newNode;
    else {
        // Se o filho esquerdo do pai estiver livre, insere lá
        if (parentNode->left == NULL)
            parentNode->left = newNode;
        // Senão, insere na direita
        else
            parentNode->right = newNode;
        
        // Define o ponteiro 'parent' do novo nó
        newNode->parent = parentNode;
    }
    return TRUE;
}

// Verifica recursivamente se a árvore satisfaz a propriedade de Max-Heap:
// Todo nó pai deve ser maior ou igual aos seus filhos.
int CheckMaxHeap(TNode *r) {
    // Caso base: árvore vazia é um heap válido
    if(r == NULL)
        return TRUE;
    // Se o filho esquerdo existe e é maior que o pai, não é Max-Heap
    else if(r->left != NULL && r->left->value > r->value)
        return FALSE;
    // Se o filho direito existe e é maior que o pai, não é Max-Heap
    else if(r->right != NULL && r->right->value > r->value)
        return FALSE;
    
    // Recursão: Verifica se as subárvores esquerda e direita também são Max-Heaps
    return CheckMaxHeap(r->left) && CheckMaxHeap(r->right);
}

// Verifica recursivamente se a árvore satisfaz a propriedade de Min-Heap:
// Todo nó pai deve ser menor ou igual aos seus filhos.
int CheckMinHeap(TNode *r) {
    // Caso base: árvore vazia é um heap válido
    if(r == NULL)
        return TRUE;
    // Se o filho esquerdo existe e é menor que o pai, não é Min-Heap
    else if(r->left != NULL && r->left->value < r->value)
        return FALSE;
    // Se o filho direito existe e é menor que o pai, não é Min-Heap
    else if(r->right != NULL && r->right->value < r->value)
        return FALSE;
        
    // Recursão: Verifica se as subárvores esquerda e direita também são Min-Heaps
    return CheckMinHeap(r->left) && CheckMinHeap(r->right);
}

// Função para liberar a memória alocada dinamicamente (Percurso pós-ordem)
void DestroyTree(TNode *r)
{
    if(r != NULL)
    {
        // Primeiro destrói as subárvores
        DestroyTree(r->left);
        DestroyTree(r->right);
        // Depois libera o nó atual
        free(r);
    }
}