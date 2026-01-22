#include <stdio.h>
#include <stdlib.h>

// Definição de constantes para representar booleanos
#define FALSE 0
#define TRUE 1

// Estrutura do nó da Árvore Binária de Busca (BST)
struct regNo
{
    struct regNo *esq;  // Ponteiro para o filho à esquerda (menores)
    int valor;          // Valor armazenado no nó
    int quantidade;     // Contador de frequência do valor (para duplicatas)
    struct regNo *pai;  // Ponteiro para o nó pai
    struct regNo *dir;  // Ponteiro para o filho à direita (maiores)
};
typedef struct regNo TNo;

// Protótipos das funções utilizadas no programa
TNo *AchaPai(TNo *, int);              // Encontra o nó pai para um novo valor
int ContaNos(TNo *);                    // Conta o número total de nós únicos na árvore
int ContaValores(TNo *);                // Conta o total de valores inseridos (soma das quantidades)
void Impressao(TNo *);                  // Função wrapper para imprimir a árvore
void ImprimeAncestrais(TNo *);          // Imprime o caminho do nó até a raiz
void ImprimeArvore(TNo *, int);         // Imprime a árvore visualmente com indentação
int IncluiItem(TNo **, int);            // Insere um novo valor ou incrementa a quantidade se existir
TNo *PesquisaValor(TNo *, int);         // Busca um valor específico na árvore

// Ponteiro global para a raiz da árvore
TNo *raiz = NULL;

int main(void)
{
    int numero;

    // Loop principal para inserção de dados
    while (TRUE)
    {
        printf("\nInforme o valor:\n");
        scanf("%d", &numero);

        // Condição de parada para a inserção: digitar -999
        if (numero == -999)
            break;

        // Tenta incluir o número na árvore
        if (IncluiItem(&raiz, numero) == FALSE)
        {
            puts("Memoria insuficiente para inclusao");
            return 2;
        }
    }

    // Imprime a estrutura da árvore após a inserção de todos os números
    Impressao(raiz);

    // Loop principal para pesquisa de dados
    while (TRUE)
    {
        printf("\nPesquisa um valor:\n");
        scanf("%d", &numero);

        // Condição de parada para a pesquisa: digitar -999
        if (numero == -999)
            break;

        // Busca o valor na árvore
        if (PesquisaValor(raiz, numero) == NULL)
            printf("Valor %d nao encontrado na arvore\n", numero);
        else
        {
            // Se encontrado, imprime os ancestrais (caminho até a raiz)
            ImprimeAncestrais(PesquisaValor(raiz, numero));
            printf("\n");
        }
    }

    return 0;
}

// Função recursiva para encontrar qual nó deve ser o pai de um novo valor 'n'
TNo *AchaPai(TNo *r, int n)
{
    if (r == NULL)
        return NULL;
    else if (n <= r->valor)
        /* Se o valor 'n' é menor ou igual, deve ir para a esquerda */
        if (r->esq == NULL)
            return r; // Se não tem filho esquerdo, este nó 'r' é o pai
        else
            return AchaPai(r->esq, n); // Se tem, desce à esquerda
    else
        /* Se o valor 'n' é maior, deve ir para a direita */
        if (r->dir == NULL)
            return r; // Se não tem filho direito, este nó 'r' é o pai
        else
            return AchaPai(r->dir, n); // Se tem, desce à direita
}

// Função recursiva para contar quantos nós (estruturas) existem na árvore
int ContaNos(TNo *r)
{
    if (r == NULL)
        return 0;
    else
        return 1 + ContaNos(r->esq) + ContaNos(r->dir);
}

// Função que prepara e chama a impressão da árvore
void Impressao(TNo *r)
{
    if (r == NULL)
        puts("Arvore vazia");
    else
    {
        // Imprime o total de nós (distintos) e o total de valores (incluindo repetições)
        printf("A arvore possui %d nos e %d valores:\n ", ContaNos(r), ContaValores(raiz));
        ImprimeArvore(r, 0);
    }
}

// Função recursiva para imprimir a árvore em ordem (esquerda, nó, direita) com indentação
void ImprimeArvore(TNo *r, int n)
{
    int c;

    if (r != NULL)
    {
        // Primeiro imprime a subárvore esquerda (recursivamente)
        ImprimeArvore(r->esq, n + 1);

        // Imprime espaços proporcional à profundidade 'n' para criar efeito visual
        for (c = 0; c < n; c++)
            printf("  ");
        
        // Imprime o valor do nó
        printf("%d", r->valor);
        
        // Se a quantidade for maior que 1, significa que o número foi inserido múltiplas vezes
        if (r->quantidade != 1)
            printf(" [%d] \n", r->quantidade);
        else
            printf("\n");

        // Por fim, imprime a subárvore direita (recursivamente)
        ImprimeArvore(r->dir, n + 1);
    }
}

// Função para incluir um novo item na árvore
int IncluiItem(TNo **r, int n)
{
    TNo *aux, *pai;

    // Aloca memória para o novo nó
    aux = (TNo *)malloc(sizeof(TNo));
    if (aux == NULL)
        return FALSE; // Falha na alocação de memória

    // Verifica se o valor já existe na árvore
    if (PesquisaValor(*r, n) != NULL)
    {
        // Se já existe, apenas incrementa o contador de quantidade
        PesquisaValor(*r, n)->quantidade += 1;
        free(aux); // Libera a memória alocada desnecessariamente
        return TRUE;
    }
    
    // Se não existe, preenche os dados do novo nó
    aux->valor = n;
    aux->quantidade = 1;
    aux->dir = NULL;
    aux->esq = NULL;

    /* Encontrando e fazendo o encadeamento do novo nó */
    pai = AchaPai(*r, n);
    
    // Se o pai for NULL, a árvore estava vazia, este é o novo nó raiz
    if (pai == NULL)
    {
        *r = aux;
        aux->pai = NULL;
        return TRUE;
    }
    else if (n <= pai->valor)
        // Se o valor é menor ou igual ao pai, insere à esquerda
        pai->esq = aux;
    else
        // Se o valor é maior, insere à direita
        pai->dir = aux;

    // Define o ponteiro pai do novo nó
    aux->pai = pai;
    return TRUE;
}

// Função recursiva para buscar um valor na árvore
TNo *PesquisaValor(TNo *r, int n)
{
    // Se chegou numa folha (NULL) ou encontrou o valor, retorna o ponteiro atual
    if (r == NULL || r->valor == n)
        return r;

    if (n < r->valor)
        // Se o valor buscado é menor, busca na esquerda
        return PesquisaValor(r->esq, n);
    else
        // Se é maior, busca na direita
        return PesquisaValor(r->dir, n);
}

// Função recursiva para imprimir os ancestrais de um nó (do nó até a raiz)
void ImprimeAncestrais(TNo *r)
{
    // Caso base: chegou na raiz (pai é NULL)
    if (r->pai == NULL)
        printf("%d <- Raiz", r->valor);
    

    // Se ainda não chegou na raiz, imprime o valor atual e chama recursivamente para o pai
    if (r->pai != NULL)
    {
        printf("%d <- ", r->valor);
        ImprimeAncestrais(r->pai);
    }
}

// Função recursiva que soma o campo 'quantidade' de todos os nós
// Isso retorna o número total de itens inseridos, contando repetições
int ContaValores(TNo *r)
{
    if (r == NULL)
        return 0;
    else
        return r->quantidade + ContaValores(r->esq) + ContaValores(r->dir);
    
}