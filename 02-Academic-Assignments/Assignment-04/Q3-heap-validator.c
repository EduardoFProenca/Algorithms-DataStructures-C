#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Definição de constantes e valores booleanos
#define TRUE  1
#define FALSE 0
// Capacidade máxima para a fila estática auxiliar usada na busca do pai
#define QTDE_MAX 500

// Estrutura do Nó da Árvore Binária (completa)
struct regNo
{	struct regNo *esq; // Ponteiro para o filho à esquerda
    int valor;         // Valor armazenado no nó
    struct regNo *mae; // Ponteiro para o nó pai ("mãe" do nó)
    struct regNo *dir; // Ponteiro para o filho à direita
};
typedef struct regNo TNo;

// Protótipos das funções
TNo *AchaPai(TNo *, int);              // Encontra o local de inserção para manter árvore completa
int IncluiItem(TNo **, int);           // Insere um valor na árvore
int DeterminarMaxHeap(TNo *);          // Verifica se a árvore é um Max-Heap
int DeterminarMinHeap(TNo *);          // Verifica se a árvore é um Min-Heap
void DestroiLista(TNo *);              // Libera a memória da árvore recursivamente

int main(void)
{	TNo *raiz = NULL;
    int numero, quant;

    // Loop que lê múltiplos casos de teste até o fim do arquivo (EOF)
    while (scanf("%d", &quant) != EOF) {
        // Reseta a raiz para cada novo caso de teste
        raiz = NULL;
        
        // Loop para ler e inserir 'quant' números na árvore
        for(int i = 0; i < quant; i++ )
        {	
            scanf("%d", &numero);

            // Tenta inserir o número. Se falhar (memória cheia), encerra o programa.
            if (IncluiItem(&raiz, numero) == FALSE)
            {	puts("Memoria insuficiente para inclusao");
                return 2;
            }
        }
        
        // Verifica as propriedades de Heap após a construção da árvore
        if(DeterminarMaxHeap(raiz))
            printf("max\n");      // É um Max-Heap (Pai >= Filhos)
        else if (DeterminarMinHeap(raiz))
            printf("min\n");      // É um Min-Heap (Pai <= Filhos)
        else
            printf("nada\n");     // Não é nem Max nem Min Heap
        
        // Libera a memória alocada para a árvore atual antes de prosseguir
        DestroiLista(raiz);
    }
    return 0;
}

// Função que encontra o nó pai onde o novo valor deve ser inserido.
// Utiliza uma fila estática (array) para percorrer a árvore em nível (BFS),
// garantindo que a árvore seja uma "Complete Binary Tree" (cheia da esquerda para a direita).
TNo *AchaPai(TNo *r, int n)
{	TNo *fila[QTDE_MAX], *aux;
    int inicio, final;

    if (r == NULL)
        return NULL;

    inicio = final = 0;
    aux = r;
    
    // Percorre a árvore enquanto o nó atual tiver ambos os filhos (esq e dir) ocupados
    while (aux->esq != NULL && aux->dir != NULL)
    {	
        // Adiciona os filhos à fila para processamento posterior
        fila[final++] = aux->esq;
        fila[final++] = aux->dir;
    
        // Pega o próximo nó da fila
        aux = fila[inicio++];
    }
    
    // Retorna o nó que possui espaço vazio (esq ou dir) para receber o novo filho
    return aux;
}

// Função que cria um novo nó e o insere na árvore
int IncluiItem(TNo **r, int n)
{	TNo *aux, *pai;

    // Aloca memória para o novo nó
    aux = (TNo *) malloc(sizeof(TNo));
    if (aux == NULL)
        return FALSE;

    aux->valor = n;
    aux->dir = NULL;
    aux->esq = NULL;
    aux->mae = NULL;

    /* Fazendo o encadeamento do novo noh */
    pai = AchaPai(*r, n);
    
    // Se não encontrou pai, a árvore estava vazia. O novo nó é a raiz.
    if (pai == NULL) 
        *r = aux;
    else {
        // Se o filho esquerdo do pai estiver livre, insere lá
        if (pai->esq == NULL)
            pai->esq = aux;
        // Senão, insere na direita
        else
            pai->dir = aux;
        
        // Define o ponteiro 'mae' (pai) do novo nó
        aux->mae = pai;
    }
    return TRUE;
}

// Verifica recursivamente se a árvore satisfaz a propriedade de Max-Heap:
// Todo nó pai deve ser maior ou igual aos seus filhos.
int DeterminarMaxHeap(TNo *r) {
    // Caso base: árvore vazia é um heap válido
    if(r == NULL)
        return TRUE;
    // Se o filho esquerdo existe e é maior que o pai, não é Max-Heap
    else if(r->esq != NULL && r->esq->valor > r->valor)
        return FALSE;
    // Se o filho direito existe e é maior que o pai, não é Max-Heap
    else if(r->dir != NULL && r->dir->valor > r->valor)
        return FALSE;
    
    // Recursão: Verifica se as subárvores esquerda e direita também são Max-Heaps
    return DeterminarMaxHeap(r->esq) && DeterminarMaxHeap(r->dir);
}

// Verifica recursivamente se a árvore satisfaz a propriedade de Min-Heap:
// Todo nó pai deve ser menor ou igual aos seus filhos.
int DeterminarMinHeap(TNo *r) {
    // Caso base: árvore vazia é um heap válido
    if(r == NULL)
        return TRUE;
    // Se o filho esquerdo existe e é menor que o pai, não é Min-Heap
    else if(r->esq != NULL && r->esq->valor < r->valor)
        return FALSE;
    // Se o filho direito existe e é menor que o pai, não é Min-Heap
    else if(r->dir != NULL && r->dir->valor < r->valor)
        return FALSE;
        
    // Recursão: Verifica se as subárvores esquerda e direita também são Min-Heaps
    return DeterminarMinHeap(r->esq) && DeterminarMinHeap(r->dir);
}

// Função para liberar a memória alocada dinamicamente (Percurso pós-ordem)
void DestroiLista(TNo *r)
{
    if(r != NULL)
    {
        // Primeiro destrói as subárvores
        DestroiLista(r->esq);
        DestroiLista(r->dir);
        // Depois libera o nó atual
        free(r);
    }
}