/*
Beecrowd : 1068 - Balanço de Parênteses I
https://judge.beecrowd.com/pt/problems/view/1068

**Explicação do Código:**
Este programa verifica se uma expressão matemática contendo parênteses está corretamente balanceada.
O critério para balanceamento é que cada parêntese de abertura '(' deve ter um correspondente 
parêntese de fechamento ')' na ordem correta.

Para isso, o código utiliza uma estrutura de **Pilha (Stack)**:
1. Percorre a string caractere por caractere.
2. Se encontrar um parêntese de abertura '(', insere um ')' na pilha.
   (Nota: O código insere o fechamento na pilha para simplificar a verificação posterior).
3. Se encontrar um parêntese de fechamento ')', verifica se o topo da pilha é também um ')'.
   - Se a pilha estiver vazia ou o valor no topo for diferente, a expressão está incorreta.
   - Se coincidir, remove o item da pilha.
4. Ao final do processamento, se a pilha estiver vazia e nenhum erro ocorreu, a expressão está correta.
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
    char value;            // Caractere armazenado (no caso, sempre será ')' se inserido via '(')
    struct Node *next;     // Ponteiro para o próximo nó da pilha
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

    // Lê expressões até o fim do arquivo (EOF)
    while(scanf(" %s", expression) != EOF ) {
        int isBalanced = TRUE;  
        InitializeStack(&stack);

        // Percorre cada caractere da expressão
        for (int i = 0; i < strlen(expression); i++)
        {
            char character = expression[i];
            switch(character) {
                case '(':
                    // Abriu parêntese? Empilha o fechamento correspondente ')'
                    Push(&stack, ')');
                    break;
                case ')':
                    // Fechou parêntese? Tenta desempilhar um ')'
                    isBalanced = Pop(&stack, character);
                    break;
                default:
                    // Ignora outros caracteres
                    break;
            }
            
            // Se em algum momento a validação falhar, interrompe o loop
            if (!isBalanced)
                break;
        }

        // Se a pilha estiver vazia e não houve erros durante o loop, está correto
        if (stack.top == NULL && isBalanced)
            printf("correct\n");
        else
            printf("incorrect\n");
    }
    return EXEC_SUCCESS;
}

// Inicializa a pilha como vazia
void InitializeStack(TStack *stack) {
    stack->top = NULL;
    stack->count = 0;
}

// Empilha um caractere (Push)
int Push(TStack *stack, char expectedDelimiter) {
    TNode *newNode;

    newNode = (TNode *) malloc(sizeof(TNode));
    if (newNode == NULL) {
        puts("Erro fatal: Memoria insuficiente para esta operacao");
        return MEMORY_ERROR;
    }

    newNode->value = expectedDelimiter;
    newNode->next = stack->top;

    stack->top = newNode;
    stack->count++;
    return TRUE;
}

// Desempilha um caractere (Pop)
int Pop(TStack *stack, char currentDelimiter) {
    TNode *temp;

    if (stack->top == NULL) {
        return FALSE; // Pilha vazia: não há correspondente
    }
    else if (stack->top->value == currentDelimiter)
    {
        // O topo da pilha corresponde ao fechamento esperado
        temp = stack->top;
        stack->top = stack->top->next;
        stack->count--;
        free(temp);
        return TRUE;
    }
    else
        return FALSE; // O topo da pilha não corresponde (ex: fechou algo que não abriu)
}