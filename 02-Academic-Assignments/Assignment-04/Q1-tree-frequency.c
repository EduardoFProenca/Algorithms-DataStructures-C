/*
 * 
 * Este programa implementa uma Árvore Binária de Busca (BST - Binary Search Tree)
 * para gerenciar um conjunto de números inteiros.
 *
 * CARACTERÍSTICAS DA IMPLEMENTAÇÃO:
 * 1. ESTRUTURA DE NÓ:
 *    - Cada nó contém ponteiros para filhos à esquerda (menores) e direita (maiores).
 *    - Contém um ponteiro para o nó pai (permitindo navegação ascendente).
 *    - Possui um contador 'count' para lidar com duplicatas. Se um valor já existe,
 *      não cria um novo nó, apenas incrementa este contador.
 *
 * 2. OPERAÇÕES PRINCIPAIS:
 *    - INSERÇÃO: Usa a lógica da BST para encontrar a posição correta e recursão
 *      para buscar o pai. Verifica duplicatas.
 *    - IMPRESSÃO: Exibe a árvore de forma visual (rotacionada 90 graus) usando
 *      travessia "in-order" (Esquerda -> Raiz -> Direita) com indentação
 *      proporcional à profundidade.
 *    - BUSCA: Localiza um valor específico.
 *    - ANCESTRAIS: Imprime o caminho de um nó até a raiz, mostrando a hierarquia.
 *
 * 3. CONTAGENS:
 *    - Conta Nós: Quantos valores únicos existem.
 *    - Conta Valores: Soma total de inserções (único + repetições).
 * 
 */

#include <stdio.h>
#include <stdlib.h>

// Definição de constantes para representar booleanos
#define FALSE 0
#define TRUE 1

// Estrutura do nó da Árvore Binária de Busca (BST)
struct Node
{
    struct Node *left;   // Ponteiro para o filho à esquerda (menores)
    int value;           // Valor armazenado no nó
    int count;           // Contador de frequência do valor (para duplicatas)
    struct Node *parent; // Ponteiro para o nó pai
    struct Node *right;  // Ponteiro para o filho à direita (maiores)
};
typedef struct Node TNode;

// Protótipos das funções utilizadas no programa
TNode *FindParent(TNode *, int);           // Encontra o nó pai para um novo valor
int CountNodes(TNode *);                   // Conta o número total de nós únicos na árvore
int CountTotalValues(TNode *);             // Conta o total de valores inseridos (soma das quantidades)
void PrintTreeInfo(TNode *);               // Função wrapper para imprimir a árvore
void PrintAncestors(TNode *);              // Imprime o caminho do nó até a raiz
void PrintTreeStructure(TNode *, int);     // Imprime a árvore visualmente com indentação
int InsertItem(TNode **, int);             // Insere um novo valor ou incrementa a quantidade se existir
TNode *SearchValue(TNode *, int);         // Busca um valor específico na árvore

// Ponteiro global para a raiz da árvore
TNode *root = NULL;

int main(void)
{
    int number;

    // Loop principal para inserção de dados
    while (TRUE)
    {
        printf("\nInforme o valor:\n");
        scanf("%d", &number);

        // Condição de parada para a inserção: digitar -999
        if (number == -999)
            break;

        // Tenta incluir o número na árvore
        if (InsertItem(&root, number) == FALSE)
        {
            puts("Memoria insuficiente para inclusao");
            return 2;
        }
    }

    // Imprime a estrutura da árvore após a inserção de todos os números
    PrintTreeInfo(root);

    // Loop principal para pesquisa de dados
    while (TRUE)
    {
        printf("\nPesquisa um valor:\n");
        scanf("%d", &number);

        // Condição de parada para a pesquisa: digitar -999
        if (number == -999)
            break;

        // Busca o valor na árvore
        if (SearchValue(root, number) == NULL)
            printf("Valor %d nao encontrado na arvore\n", number);
        else
        {
            // Se encontrado, imprime os ancestrais (caminho até a raiz)
            PrintAncestors(SearchValue(root, number));
            printf("\n");
        }
    }

    return 0;
}

// Função recursiva para encontrar qual nó deve ser o pai de um novo valor 'n'
TNode *FindParent(TNode *r, int n)
{
    if (r == NULL)
        return NULL;
    else if (n <= r->value)
        /* Se o valor 'n' é menor ou igual, deve ir para a esquerda */
        if (r->left == NULL)
            return r; // Se não tem filho esquerdo, este nó 'r' é o pai
        else
            return FindParent(r->left, n); // Se tem, desce à esquerda
    else
        /* Se o valor 'n' é maior, deve ir para a direita */
        if (r->right == NULL)
            return r; // Se não tem filho direito, este nó 'r' é o pai
        else
            return FindParent(r->right, n); // Se tem, desce à direita
}

// Função recursiva para contar quantos nós (estruturas) existem na árvore
int CountNodes(TNode *r)
{
    if (r == NULL)
        return 0;
    else
        return 1 + CountNodes(r->left) + CountNodes(r->right);
}

// Função que prepara e chama a impressão da árvore
void PrintTreeInfo(TNode *r)
{
    if (r == NULL)
        puts("Arvore vazia");
    else
    {
        // Imprime o total de nós (distintos) e o total de valores (incluindo repetições)
        printf("A arvore possui %d nos e %d valores:\n ", CountNodes(r), CountTotalValues(root));
        PrintTreeStructure(r, 0);
    }
}

// Função recursiva para imprimir a árvore em ordem (esquerda, nó, direita) com indentação
void PrintTreeStructure(TNode *r, int level)
{
    int i;

    if (r != NULL)
    {
        // Primeiro imprime a subárvore esquerda (recursivamente)
        PrintTreeStructure(r->left, level + 1);

        // Imprime espaços proporcional à profundidade 'level' para criar efeito visual
        for (i = 0; i < level; i++)
            printf("  ");
        
        // Imprime o valor do nó
        printf("%d", r->value);
        
        // Se a quantidade for maior que 1, significa que o número foi inserido múltiplas vezes
        if (r->count != 1)
            printf(" [%d] \n", r->count);
        else
            printf("\n");

        // Por fim, imprime a subárvore direita (recursivamente)
        PrintTreeStructure(r->right, level + 1);
    }
}

// Função para incluir um novo item na árvore
int InsertItem(TNode **r, int n)
{
    TNode *newNode, *parentNode;

    // Aloca memória para o novo nó
    newNode = (TNode *)malloc(sizeof(TNode));
    if (newNode == NULL)
        return FALSE; // Falha na alocação de memória

    // Verifica se o valor já existe na árvore
    if (SearchValue(*r, n) != NULL)
    {
        // Se já existe, apenas incrementa o contador de quantidade
        SearchValue(*r, n)->count += 1;
        free(newNode); // Libera a memória alocada desnecessariamente
        return TRUE;
    }
    
    // Se não existe, preenche os dados do novo nó
    newNode->value = n;
    newNode->count = 1;
    newNode->right = NULL;
    newNode->left = NULL;

    /* Encontrando e fazendo o encadeamento do novo nó */
    parentNode = FindParent(*r, n);
    
    // Se o pai for NULL, a árvore estava vazia, este é o novo nó raiz
    if (parentNode == NULL)
    {
        *r = newNode;
        newNode->parent = NULL;
        return TRUE;
    }
    else if (n <= parentNode->value)
        // Se o valor é menor ou igual ao pai, insere à esquerda
        parentNode->left = newNode;
    else
        // Se o valor é maior, insere à direita
        parentNode->right = newNode;

    // Define o ponteiro pai do novo nó
    newNode->parent = parentNode;
    return TRUE;
}

// Função recursiva para buscar um valor na árvore
TNode *SearchValue(TNode *r, int n)
{
    // Se chegou numa folha (NULL) ou encontrou o valor, retorna o ponteiro atual
    if (r == NULL || r->value == n)
        return r;

    if (n < r->value)
        // Se o valor buscado é menor, busca na esquerda
        return SearchValue(r->left, n);
    else
        // Se é maior, busca na direita
        return SearchValue(r->right, n);
}

// Função recursiva para imprimir os ancestrais de um nó (do nó até a raiz)
void PrintAncestors(TNode *r)
{
    // Caso base: chegou na raiz (pai é NULL)
    if (r->parent == NULL)
        printf("%d <- Raiz", r->value);
    

    // Se ainda não chegou na raiz, imprime o valor atual e chama recursivamente para o pai
    if (r->parent != NULL)
    {
        printf("%d <- ", r->value);
        PrintAncestors(r->parent);
    }
}

// Função recursiva que soma o campo 'count' de todos os nós
// Isso retorna o número total de itens inseridos, contando repetições
int CountTotalValues(TNode *r)
{
    if (r == NULL)
        return 0;
    else
        return r->count + CountTotalValues(r->left) + CountTotalValues(r->right);
}