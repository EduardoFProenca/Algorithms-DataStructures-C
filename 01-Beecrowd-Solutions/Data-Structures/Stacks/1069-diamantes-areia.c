/*
Beecrowd : 1069 - Diamantes e Areia
https://judge.beecrowd.com/pt/problems/view/1069

**Explicação do Código:**
Este programa conta a quantidade de diamantes que podem ser formados em uma string de mineração.
Um diamante é definido como um par de caracteres: um '<' seguido posteriormente por um '>'.

Para realizar essa contagem de forma eficiente, o algoritmo utiliza uma estrutura de **Pilha (Stack)**:
1. Percorre a string caractere por caractere.
2. Quando encontra um '<' (abre), ele empilha um caractere '>' na pilha.
   (Isso é feito para facilitar a verificação: o topo da pilha sempre indica que estamos esperando um '>').
3. Quando encontra um '>' (fecha), ele tenta desempilhar (remover) um item da pilha.
   - Se a remoção for bem-sucedida, significa que encontramos um par correspondente, e incrementamos o contador de diamantes.
   - Se a pilha estiver vazia, o '>' é ignorado (é areia).
4. Ao final, imprime o total de diamantes encontrados.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TRUE	1
#define FALSE	0
#define EXEC_SUCCESS	0
#define MEMORY_ERROR	2

// Estrutura do nó da pilha
struct Node
{
    char value;            // Valor armazenado (no caso, usado para marcar espera de fechamento)
    struct Node *next;     // Ponteiro para o próximo nó
};
typedef struct Node TNode;

// Estrutura descritora da pilha
struct Stack
{
    TNode *top;            // Topo da pilha
    int count;             // Quantidade de elementos
};
typedef struct Stack TStack;

// Protótipos das funções
int Pop(TStack *, char);
void InitializeStack(TStack *);
int Push(TStack *, char);

int main(void)
{
    TStack stack;
    char expression[1001];
    char character;
    int i = 0;
    int isBalanced = TRUE; // Variável mantida conforme lógica original (não utilizada ativamente)

    int numCases;
    scanf(" %d", &numCases);

    for(int j = 0 ; j < numCases ; j++) {
        InitializeStack(&stack);

        scanf(" %s", expression);
        int diamondCount = 0;

        // Percorre a string caractere por caractere
        for (i = 0; i < strlen(expression); i++)
        {
            character = expression[i];
            switch(character) {
            case '<':
                // Encontrou abertura: empilha o fechamento correspondente '>'
                Push(&stack, '>');
                break;
            case '>':
                // Encontrou fechamento: tenta desempilhar.
                // Se conseguir (Pop retorna TRUE), forma-se um diamante.
                if(Pop(&stack, character))
                    diamondCount++;
                break;
            default:
                // Ignora outros caracteres (considerados areia)
                break;
            }
        }
        printf("%d\n", diamondCount);
    }
    return EXEC_SUCCESS;
}

// Inicializa a pilha como vazia
void InitializeStack(TStack *stack) {
    stack->top = NULL;
    stack->count = 0;
}

// Empilha um caractere (Push)
int Push(TStack *stack, char expectedChar) {
    TNode *newNode;

    newNode = (TNode *) malloc(sizeof(TNode));
    if (newNode == NULL) {
        puts("Erro fatal: Memoria insuficiente para esta operacao");
        return MEMORY_ERROR;
    }

    newNode->value = expectedChar;
    newNode->next = stack->top;

    stack->top = newNode;
    stack->count++;
    return TRUE;
}

// Desempilha um caractere (Pop)
int Pop(TStack *stack, char currentChar) {
    TNode *temp;

    if (stack->top == NULL) {
        return FALSE; // Pilha vazia, não forma diamante
    }
    else if (stack->top->value == currentChar)
    {
        // O topo da pilha corresponde ao fechamento esperado
        temp = stack->top;
        stack->top = stack->top->next;
        stack->count--;
        free(temp);
        return TRUE;
    }
    else
        return FALSE;
}