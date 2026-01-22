/*
     
 * Este programa verifica se uma expressão aritmética inserida pelo usuário possui
 * delimitadores (parênteses, colchetes e chaves) corretamente balanceados.
 *
 * ESTRUTURA DE DADOS (PILHA ENCADEADA):
 * - O programa utiliza uma estrutura de dados do tipo PILHA (Stack).
 * - A pilha armazena nós (`TNode`) que contêm um caractere e um ponteiro para o próximo.
 * - LIFO (Last In, First Out): O último elemento a entrar é o primeiro a sair.
 *
 * ESTRATÉGIA DE VALIDAÇÃO:
 * 1. Quando um delimitador de ABERTURA é encontrado (ex: '{', '[', '('),
 *    o programa empilha (Push) o delimitador de FECHAMENTO correspondente
 *    (ex: '}', ']', ')'). Isso simplifica a verificação posterior.
 *
 * 2. Quando um delimitador de FECHAMENTO é encontrado, o programa tenta
 *    desempilhar (Pop).
 *    - Se a pilha estiver vazia: Erro (fechamento sem abertura).
 *    - Se o caractere do topo da pilha for diferente do atual: Erro (mismatch).
 *    - Se forem iguais: Sucesso, remove da pilha e continua.
 *
 * 3. Ao final da leitura da string, se a pilha estiver vazia, a expressão é válida.
 *    Se sobrarem itens na pilha, significa que faltam fechamentos.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TRUE            1
#define FALSE           0
#define EXEC_SUCCESS    0
#define MEMORY_ERROR    2

// Estrutura do nó da lista encadeada (usada para a pilha)
struct Node
{
    char value;              // O caractere armazenado (ex: o fechamento esperado)
    struct Node *next;       // Ponteiro para o próximo nó da pilha
};
typedef struct Node TNode;

// Descritor da Pilha
struct StackDescriptor
{
    TNode *top;              // Ponteiro para o topo da pilha
    int count;               // Contador de elementos na pilha
};
typedef struct StackDescriptor DStack;

// Protótipos das funções
int PopItem(DStack *, char);
void InitStack(DStack *);
int PushItem(DStack *, char);

int main(void)
{
    DStack stack;            // Instância da pilha
    char expression[20];      // String para armazenar a expressão aritmética
    char character;          // Variável auxiliar para ler caractere por caractere
    int i = 0;
    int isBalanced = TRUE;   // Flag para controlar o estado da validação

    // Inicializa a pilha (topo NULL, contador 0)
    InitStack(&stack);

    printf("Informe a expressao aritmetica:\n");
    scanf("%s", expression); // Lê a string (note: para até o primeiro espaço)

    // Percorre a string caractere por caractere
    for (i = 0; i < strlen(expression); i++)
    {
        character = expression[i];

        switch(character) {
        case '{':
            // Se encontrou '{', empilha o que esperamos encontrar depois: '}'
            PushItem(&stack, '}');
            break;
        case '[':
            // Se encontrou '[', empilha ']'
            PushItem(&stack, ']');
            break;
        case '(':
            // Se encontrou '(', empilha ')'
            PushItem(&stack, ')');
            break;

        case '}':
        case ']':
        case ')':
            // Se encontrou um fechamento, tenta desempilhar e verificar se corresponde
            isBalanced = PopItem(&stack, character);
            break;
        default:
            // Ignora caracteres que não são delimitadores (números, operadores, etc)
            break;
        }

        // Se a função PopItem retornar FALSE, houve erro de balanceamento
        if (isBalanced == FALSE) {
            printf("\nErro: delimitador '%c' nao corresponde\n", character);
            return EXEC_SUCCESS;
        }
    }

    // Após processar toda a string, verifica se a pilha está vazia
    if(stack.top == NULL)
        printf("\nExpressao valida!\n");
    else
        // Se não está vazia, faltam fechamentos para o que está no topo
        printf("\nErro: faltam delimitadores de fechamento. Esperado '%c'\n", stack.top->value);

    return EXEC_SUCCESS;
}

// Função para inicializar a pilha
void InitStack(DStack *stack) {
    stack->top = NULL;
    stack->count = 0;
}

// Função para Empilhar (Push): Adiciona um novo nó no topo da pilha
int PushItem(DStack *stack, char expectedDelimiter) {
    TNode *newNode;

    // Aloca memória para o novo nó
    newNode = (TNode *) malloc(sizeof(TNode));
    if (newNode == NULL){
        puts("Erro fatal: Memoria insuficiente para esta operacao");
        return MEMORY_ERROR;
    }

    // Define o valor e aponta o novo nó para o antigo topo
    newNode->value = expectedDelimiter;
    newNode->next = stack->top;

    // Atualiza o topo da pilha e incrementa o contador
    stack->top = newNode;
    stack->count++;
    return TRUE;
}

// Função para Desempilhar (Pop): Remove o nó do topo e verifica a correspondência
int PopItem(DStack *stack, char currentDelimiter) {
    TNode *nodeToRemove;

    // Se a pilha está vazia, não existe abertura correspondente (Erro)
    if (stack->top == NULL) {
        return FALSE;
    }
    // Verifica se o valor do topo é igual ao caractere de fechamento atual
    else if (stack->top->value == currentDelimiter)
    {
        // Salva o endereço do nó a ser removido
        nodeToRemove = stack->top;
        
        // Atualiza o topo para o próximo nó da pilha
        stack->top = stack->top->next;
        stack->count--;
        
        // Libera a memória do nó removido
        free(nodeToRemove);
        return TRUE;
    }
    else
        // O valor do topo é diferente do fechamento encontrado (Mismatch)
        return FALSE;
}