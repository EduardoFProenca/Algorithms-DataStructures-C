/*
 * Este programa implementa uma Árvore Binária **Completa** (Complete Binary Tree),
 * onde a inserção de novos nós sempre busca a primeira posição disponível
 * nível por nível, da esquerda para a direita.
 *
 * DIFERENÇA PARA BST (Árvore de Busca Binária):
 * - Em uma BST, valores menores ficam à esquerda e maiores à direita.
 * - NESTE CÓDIGO, a inserção não considera o valor numérico para posicionamento,
 *   apenas mantém a estrutura cheia. Portanto, a busca é feita percorrendo
 *   toda a árvore (se necessário) e não apenas um ramo.
 *
 * ESTRUTURAS UTILIZADAS:
 * 1. ÁRVORE BINÁRIA (Nós com ponteiros para esquerda e direita).
 * 2. FILA DINÂMICA (Lista Encadeada): Utilizada para a impressão da árvore
 *    por níveis (Breadth-First Search - BFS).
 * 3. FILA ESTÁTICA (Array): Utilizada internamente na função `FindParent`
 *    para localizar o próximo local de inserção vazio.
 *
 * FUNCIONALIDADES:
 * - Inserção de valores (-999 encerra).
 * - Impressão da árvore por níveis.
 * - Estatísticas: Total de nós, Altura (considerando o ramo esquerdo), Quantidade de pares.
 * - Busca de valores (retorna se existe ou não).
 * 
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

// Códigos de retorno para status de execução
#define EXEC_SUCCESS 0
#define MEMORY_ERROR 2

// Definições de tipo booleano
#define TRUE 1
#define FALSE 0
// Capacidade máxima para filas auxiliares estáticas
#define MAX_QTY 500

// Estrutura do Nó da Árvore Binária
struct Node
{
    struct Node *left;  // Ponteiro para o filho à esquerda
    int value;          // Valor armazenado no nó
    struct Node *right; // Ponteiro para o filho à direita
};
typedef struct Node TNode;

// Estrutura de um Nó da Lista Encadeada (usada para implementar a Fila)
struct ListNode
{
    TNode *nodeValue;        // Ponteiro para um nó da árvore
    struct ListNode *next;   // Ponteiro para o próximo elemento da lista/fila
};
typedef struct ListNode TList;

// Descritor da Fila (controla o início, fim e quantidade)
struct QueueDescriptor
{
    TList *head; // Ponteiro para o início da fila
    TList *tail; // Ponteiro para o fim da fila
    int count;   // Contador de elementos na fila
};
typedef struct QueueDescriptor DQueue;

// Protótipos das funções
int DequeueItem(DQueue *, char *);           // Protótipo declarado mas não implementado
void InitializeQueue(DQueue *);               // Inicializa a fila vazia
int EnqueueItem(DQueue *, TNode *);           // Enfileira um nó da árvore
TNode *Dequeue(DQueue *);                    // Desenfileira (remove e retorna) um nó da árvore

TNode *FindParent(TNode *, int);              // Encontra o local correto para inserção (árvore completa)
int GetTreeHeight(TNode *);                  // Calcula a altura da árvore (baseada na esquerda)
int CountNodes(TNode *);                     // Conta o total de nós
int CountEvens(TNode *);                     // Conta quantos valores são pares
void PrintTreeLevelOrder(TNode *, int);         // Imprime a árvore por níveis (BFS)
int InsertNode(TNode **, int);               // Insere um novo valor na árvore
int SearchValue(TNode *, int);               // Busca um valor na árvore (genérico, não BST)

int main(void)
{
    // Ponteiro para a raiz da árvore, inicialmente nulo
    TNode *root = NULL;

    int number;

    // Loop para leitura e inserção de valores
    while (TRUE)
    {
        printf("\nInforme o valor:\n");
        scanf("%d", &number);

        // Condição de parada: -999
        if (number == -999)
            break;

        // Tenta inserir o valor na árvore
        if (InsertNode(&root, number) == FALSE)
        {
            puts("Memoria insuficiente para inclusao");
            return 2;
        }
    }

    // Exibe o conteúdo e as estatísticas da árvore
    printf("\n\nConteudo da arvore\n");
    PrintTreeLevelOrder(root, 0);
    printf("\n\nResumo\n");
    printf("  Qtde nos: %3d\n", CountNodes(root));
    printf("  Altura .: %3d\n", GetTreeHeight(root));
    printf("  Pares ..: %3d\n", CountEvens(root));
    printf("\n");

    // Loop para pesquisa de valores
    while (TRUE)
    {
        printf("\nPesquisa um valor:\n");
        scanf("%d", &number);

        if (number == -999)
            break;

        // A pesquisa retorna TRUE ou FALSE
        if (SearchValue(root, number) == FALSE)
            printf("Valor %d nao existe na arvore\n", number);
        else
            printf("%d encontrado\n", number);
    }

    return 0;
}

// Função para encontrar o nó pai onde o novo valor deve ser inserido.
// Este algoritmo tenta manter a árvore "cheia" (Complete Binary Tree),
// preenchendo nível por nível da esquerda para a direita.
TNode *FindParent(TNode *r, int n)
{
    // Fila estática auxiliar para fazer uma busca em largura (BFS)
    TNode *queueArray[MAX_QTY], *current;
    int start, end;

    if (r == NULL)
        return NULL;

    start = end = 0;
    current = r;
    
    // Percorre a árvore procurando o primeiro nó que tem espaço vazio (esq ou dir nulo)
    // O loop continua enquanto o nó atual tiver ambos os filhos preenchidos
    while (current->left != NULL && current->right != NULL)
    {
        // Adiciona os filhos à fila local para visitá-los depois
        queueArray[end++] = current->left;
        queueArray[end++] = current->right;

        // Pega o próximo nó da fila
        current = queueArray[start++];
    }

    // Retorna o nó que possui um filho livre para receber o novo nó
    return current;
}

// Função de inclusão de um novo item na árvore
int InsertNode(TNode **r, int n)
{
    TNode *newNode, *parentNode;

    // Aloca memória para o novo nó
    newNode = (TNode *)malloc(sizeof(TNode));
    if (newNode == NULL)
        return FALSE;

    newNode->value = n;
    newNode->right = NULL;
    newNode->left = NULL;

    // Encontra o pai correto usando a lógica de árvore completa
    parentNode = FindParent(*r, n);
    
    // Se o pai for NULL, a árvore estava vazia. O novo nó é a raiz.
    if (parentNode == NULL)
        *r = newNode;
    // Se o filho à esquerda do pai estiver livre, insere lá
    else if (parentNode->left == NULL)
        parentNode->left = newNode;
    // Senão, insere na direita
    else
        parentNode->right = newNode;

    return TRUE;
}

// Conta recursivamente o número total de nós na árvore
int CountNodes(TNode *r)
{
    if (r == NULL)
        return 0;
    else
        return 1 + CountNodes(r->left) + CountNodes(r->right);
}

// Busca recursivamente um valor na árvore
// Nota: Esta não é uma Árvore Binária de Busca (não usa < ou >),
// portanto, ela verifica ambos os lados (OR lógico) até encontrar.
int SearchValue(TNode *r, int n)
{
    if (r == NULL)
        return FALSE;
    else if (r->value == n)
        return TRUE;
    else
        return SearchValue(r->left, n) || SearchValue(r->right, n);
}

// Conta quantos nós possuem valores pares
int CountEvens(TNode *r)
{
    if (r == NULL)
        return 0;
    else if (r->value % 2 == 0)
        return 1 + CountEvens(r->left) + CountEvens(r->right);
    else
        return CountEvens(r->left) + CountEvens(r->right);
}

// Calcula a altura da árvore descendo apenas pelo ramo esquerdo
// (Funciona corretamente para árvores completas ou cheias)
int GetTreeHeight(TNode *r)
{
    if (r == NULL)
        return 0;
    else
        return 1 + GetTreeHeight(r->left);
}

// Imprime a árvore nível por nível (travessia em largura) usando uma Fila dinâmica
void PrintTreeLevelOrder(TNode *r, int n)
{
    DQueue queue;
    InitializeQueue(&queue);
    int N = 0, D = 1, i = 1;
    
    if (r != NULL)
    {

        printf("Conteudo da arvore\n");
        printf("Nivel Valores\n");
        printf("---------------------------------------- ");
        
        // Começa enfileirando a raiz
        EnqueueItem(&queue, r);

        // Loop de processamento da fila
        while(1)
        {
            
            TNode *node = Dequeue(&queue);
            if (node == NULL)
                break;
            
            // Lógica para identificar mudança de nível com base na potência de 2
            // Supondo uma árvore binária cheia para quebra de linha
            if ( i == D ){
                printf("\n %d: %d ", N, node->value);
                N++;
                D = D * 2; // Dobra a quantidade esperada de nós para o próximo nível (1, 2, 4, 8...)
            }
            else
                printf(" %d  ", node->value);

            // Enfileira os filhos (esquerda e direita) se existirem
            if (node->left != NULL)
                EnqueueItem(&queue, node->left);
            if (node->right != NULL)
                EnqueueItem(&queue, node->right);
            i++;
        }
    }
}

/// --- Funções de Manipulação da Fila ---

// Inicializa os ponteiros e o contador da fila
void InitializeQueue(DQueue *list)
{
    list->head = NULL;
    list->tail = NULL;
    list->count = 0;
}

// Insere um novo item no final da fila (Enqueue)
int EnqueueItem(DQueue *list, TNode *value)
{
    TList *newNode = (TList *)malloc(sizeof(TList));

    if (newNode == NULL)
    {
        puts("Erro fatal: Memoria insuficiente para esta operacao");
        return MEMORY_ERROR;
    }
    newNode->nodeValue = value;
    newNode->next = NULL;

    if (list->head == NULL)
    {
        // Se a fila estava vazia, o novo nó é o primeiro e o último
        list->head = newNode;
        list->tail = newNode;
    }
    else
    {
        // Senão, insere no fim e atualiza o ponteiro tail
        list->tail->next = newNode;
        list->tail = newNode;
    }
    list->count++;
    return TRUE;
}

// Remove o item do início da fila e retorna o valor (Dequeue)
TNode *Dequeue(DQueue *list)
{
    if (list->head == NULL)
        return NULL;

    TList *temp = list->head;
    TNode *value = temp->nodeValue;

    // Avança o ponteiro de início para o próximo nó
    list->head = list->head->next;

    // Se a fila ficou vazia, ajusta o ponteiro tail também
    if (list->head == NULL)
        list->tail = NULL;

    // Libera a memória do nó da lista (não da árvore)
    free(temp);
    list->count--;

    return value;
}