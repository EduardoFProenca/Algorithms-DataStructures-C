/*
 * 
 * Este programa gerencia listas encadeadas dinâmicas (Linked Lists) com
 * alocação de memória em tempo de execução. Ele implementa uma estrutura
 * que permite inserção eficiente no final da lista (mantendo um ponteiro para
 * o "tail" ou cauda da lista).
 *
 * FUNCIONALIDADES:
 * 1. CRIAÇÃO E LEITURA:
 *    - O usuário pode criar listas e inserir números reais (float) até que
 *      um número negativo seja digitado (condição de parada).
 *
 * 2. CONCATENAÇÃO:
 *    - O programa pega duas listas originais e copia seus elementos para uma
 *      terceira lista.
 *    - Nota: A ordem no exemplo é: Lista 2 concatenada com Lista 1.
 *    - Os elementos são copiados (alocados novos nós), preservando as listas
 *      originais até que sejam explicitamente destruídas.
 *
 * 3. GERENCIAMENTO DE MEMÓRIA:
 *    - Utiliza `malloc` para criar novos nós.
 *    - Utiliza `free` para liberar a memória e evitar vazamentos.
 *
 * ESTRUTURA DA LISTA:
 * - `head` (inicio): Ponteiro para o primeiro elemento.
 * - `tail` (final): Ponteiro para o último elemento (otimiza inserção).
 * - `count` (qtde): Contador de elementos na lista.
 * 
 */

#include <stdio.h>
#include <stdlib.h>

#define TRUE            1
#define FALSE           0
#define MEMORY_ERROR    2
#define EXEC_SUCCESS    0

// Estrutura do nó (elemento) da lista encadeada
struct Node {
    float value;             // Valor armazenado
    struct Node* next;       // Ponteiro para o próximo nó
};

typedef struct Node TNode;

// Descritor da lista (mantém o controle da cabeça, cauda e quantidade)
typedef struct {
    TNode *head;             // Início da lista
    TNode *tail;             // Final da lista
    int count;               // Quantidade de elementos
} TList;

// Protótipos das funções
float    ConcatenateLists(TList *, TList *);
void     DestroyList(TList *);
float    AppendItem(TList *, float);
void     PrintList(TList *, char *);
void     InitializeList(TList *);
int      ReadData(TList *, char *);

int main(void)
{
    TList list1, list2, list3;

    // Inicializa todas as listas (head = NULL, tail = NULL, count = 0)
    InitializeList(&list1);
    InitializeList(&list2);
    InitializeList(&list3);

    printf("== PRIMEIRA LISTA ==\n");
    ReadData(&list1, " lista 1:");

    printf("\n== SEGUNDA LISTA ==\n");
    ReadData(&list2, " lista 2:");

    printf("\n=== CONCATENANDO LISTAS ===\n");
    // Concatena a lista 2 na lista 3 (copiando os elementos)
    ConcatenateLists(&list3, &list2);
    // Concatena a lista 1 na lista 3 (após o conteúdo da lista 2)
    ConcatenateLists(&list3, &list1);

    PrintList(&list3, "Conteudo da lista 3 (lst2 + lst1):");

    // Libera a memória das listas originais
    DestroyList(&list1);
    DestroyList(&list2);
    // Nota: A lista 3 não é destruída aqui no código original, resultando em leak se não fosse pelo fim do programa.

    return EXEC_SUCCESS;
}

// Inicializa os ponteiros e o contador da lista
void InitializeList(TList *list)
{
    list->head = NULL;
    list->tail = NULL;
    list->count = 0;
}

// Lê números do usuário e insere na lista até que um número negativo seja digitado
int ReadData(TList *list, char *label)
{
    float number = 0;

    while (TRUE)
    {
        printf("Informe o numero da %s (negativo para encerrar): \n", label);
        scanf("%f", &number);

        if (number < 0) {
            printf("Encerrado!\n");
            return EXEC_SUCCESS;
        }
        // Insere o número lido no final da lista
        AppendItem(list, number);
    }
    return FALSE;
}

// Insere um novo item no final da lista (Fila)
float AppendItem(TList *list, float value)
{
    TNode *newNode;

    // Aloca memória para o novo nó
    newNode = (TNode *) malloc(sizeof(TNode));

    if (newNode == NULL){
        puts("Erro fatal: Memoria insuficiente para esta operacao");
        return MEMORY_ERROR;
    }

    // Configura o novo nó
    newNode->value = value;
    newNode->next = NULL;

    // Se a lista estiver vazia, o novo nó é o cabeça e a cauda
    if (list->head == NULL)
        list->head = newNode;
    else
        // Se não, liga o antigo final ao novo nó
        list->tail->next = newNode;

    // Atualiza a cauda e o contador
    list->count = list->count + 1;
    list->tail = newNode;

    return TRUE;
}

// Copia os elementos da lista de origem para a lista de destino
float ConcatenateLists(TList *destList, TList *sourceList) {
    TNode *currentNode;

    // Se a lista de origem estiver vazia, nada a fazer
    if (sourceList->head == NULL)
        return TRUE;

    currentNode = sourceList->head;

    // Percorre a lista de origem e insere cada valor na lista de destino
    while (currentNode != NULL) {
        if (AppendItem(destList, currentNode->value) == FALSE)
            return FALSE;

        currentNode = currentNode->next;
    }
    return TRUE;
}

// Imprime todos os valores da lista
void PrintList(TList *list, char *label)
{
    TNode *currentNode;

    if (list->head == NULL)
        puts("Lista vazia");
    else
    {
        printf("\n%s\n", label);
        printf("  Valores: ");

        currentNode = list->head;

        while (currentNode != NULL)
        {
            printf("%.2f", currentNode->value);

            // Imprime seta se não for o último elemento
            if (currentNode->next != NULL) {
                printf(" -> ");
            }

            currentNode = currentNode->next;
        }
        printf("\n");
    }
}

// Libera toda a memória alocada para a lista e reinicia seus ponteiros
void DestroyList(TList *list)
{
    TNode *currentNode, *nextNode;
    currentNode = list->head;

    while (currentNode != NULL)
    {
        // Salva o ponteiro do próximo nó antes de liberar o atual
        nextNode = currentNode->next;
        free(currentNode);
        currentNode = nextNode;
    }

    // Reseta a lista para o estado inicial
    InitializeList(list);
}