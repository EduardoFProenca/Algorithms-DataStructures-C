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
#define QTDE_MAX 500

// Estrutura do Nó da Árvore Binária
struct regNo
{
    struct regNo *esq; // Ponteiro para o filho à esquerda
    int valor;         // Valor armazenado no nó
    struct regNo *dir; // Ponteiro para o filho à direita
};
typedef struct regNo TNo;

// Estrutura de um Nó da Lista Encadeada (usada para implementar a Fila)
struct regLista
{
    TNo *valor;             // Ponteiro para um nó da árvore
    struct regLista *prox;  // Ponteiro para o próximo elemento da lista/fila
};
typedef struct regLista TLista;

// Descritor da Fila (controla o início, fim e quantidade)
struct descrFila
{
    TLista *topo; // Ponteiro para o início da fila
    TLista *fim;  // Ponteiro para o fim da fila
    int qtde;     // Contador de elementos na fila
};
typedef struct descrFila DFila;

// Protótipos das funções
int ExcluiItemFila(DFila *, char *);      // Protótipo declarado mas não implementado/utilizado no código
void InicializaFila(DFila *);             // Inicializa a fila vazia
int IncluiItemFila(DFila *, TNo *);       // Enfileira um nó da árvore
TNo *DesemFilar(DFila *);                 // Desenfileira (remove e retorna) um nó da árvore

TNo *AchaPai(TNo *, int);                 // Encontra o local correto para inserção (árvore completa)
int AlturaArv(TNo *);                     // Calcula a altura da árvore (baseada na esquerda)
int ContaNos(TNo *);                      // Conta o total de nós
int ContaPares(TNo *);                    // Conta quantos valores são pares
void ImprimeArvoreNvl(TNo *, int);        // Imprime a árvore por níveis (BFS)
int IncluiItem(TNo **, int);              // Insere um novo valor na árvore
int PesquisaValor(TNo *, int);            // Busca um valor na árvore (genérico)

int main(void)
{
    // Ponteiro para a raiz da árvore, inicialmente nulo
    TNo *raiz = NULL;

    int numero;

    // Loop para leitura e inserção de valores
    while (TRUE)
    {
        printf("\nInforme o valor:\n");
        scanf("%d", &numero);

        // Condição de parada: -999
        if (numero == -999)
            break;

        // Tenta inserir o valor na árvore
        if (IncluiItem(&raiz, numero) == FALSE)
        {
            puts("Memoria insuficiente para inclusao");
            return 2;
        }
    }

    // Exibe o conteúdo e as estatísticas da árvore
    printf("\n\nConteudo da arvore\n");
    ImprimeArvoreNvl(raiz, 0);
    printf("\n\nResumo\n");
    printf("  Qtde nos: %3d\n", ContaNos(raiz));
    printf("  Altura .: %3d\n", AlturaArv(raiz));
    printf("  Pares ..: %3d\n", ContaPares(raiz));
    printf("\n");

    // Loop para pesquisa de valores
    while (TRUE)
    {
        printf("\nPesquisa um valor:\n");
        scanf("%d", &numero);

        if (numero == -999)
            break;

        // A pesquisa retorna TRUE ou FALSE
        if (PesquisaValor(raiz, numero) == FALSE)
            printf("Valor %d nao existe na arvore\n", numero);
        else
            printf("%d encontrado\n", numero);
    }

    return 0;
}

// Função para encontrar o nó pai onde o novo valor deve ser inserido.
// Este algoritmo tenta manter a árvore "cheia" (Complete Binary Tree),
// preenchendo nível por nível da esquerda para a direita.
TNo *AchaPai(TNo *r, int n)
{
    // Fila estática auxiliar para fazer uma busca em largura (BFS)
    TNo *fila[QTDE_MAX], *aux;
    int inicio, final;

    if (r == NULL)
        return NULL;

    inicio = final = 0;
    aux = r;
    
    // Percorre a árvore procurando o primeiro nó que tem espaço vazio (esq ou dir nulo)
    // O loop continua enquanto o nó atual tiver ambos os filhos preenchidos
    while (aux->esq != NULL && aux->dir != NULL)
    {
        // Adiciona os filhos à fila local para visitá-los depois
        fila[final++] = aux->esq;
        fila[final++] = aux->dir;

        // Pega o próximo nó da fila
        aux = fila[inicio++];
    }

    // Retorna o nó que possui um filho livre para receber o novo nó
    return aux;
}

// Função de inclusão de um novo item na árvore
int IncluiItem(TNo **r, int n)
{
    TNo *aux, *pai;

    // Aloca memória para o novo nó
    aux = (TNo *)malloc(sizeof(TNo));
    if (aux == NULL)
        return FALSE;

    aux->valor = n;
    aux->dir = NULL;
    aux->esq = NULL;

    // Encontra o pai correto usando a lógica de árvore completa
    pai = AchaPai(*r, n);
    
    // Se o pai for NULL, a árvore estava vazia. O novo nó é a raiz.
    if (pai == NULL)
        *r = aux;
    // Se o filho à esquerda do pai estiver livre, insere lá
    else if (pai->esq == NULL)
        pai->esq = aux;
    // Senão, insere na direita
    else
        pai->dir = aux;

    return TRUE;
}

// Conta recursivamente o número total de nós na árvore
int ContaNos(TNo *r)
{
    if (r == NULL)
        return 0;
    else
        return 1 + ContaNos(r->esq) + ContaNos(r->dir);
}

// Busca recursivamente um valor na árvore
// Nota: Esta não é uma Árvore Binária de Busca (não usa < ou >),
// portanto, ela verifica ambos os lados (OR lógico) até encontrar.
int PesquisaValor(TNo *r, int n)
{
    if (r == NULL)
        return FALSE;
    else if (r->valor == n)
        return TRUE;
    else
        return PesquisaValor(r->esq, n) || PesquisaValor(r->dir, n);
}

// Conta quantos nós possuem valores pares
int ContaPares(TNo *r)
{
    if (r == NULL)
        return 0;
    else if (r->valor % 2 == 0)
        return 1 + ContaPares(r->esq) + ContaPares(r->dir);
    else
        return ContaPares(r->esq) + ContaPares(r->dir);
}

// Calcula a altura da árvore descendo apenas pelo ramo esquerdo
// (Funciona corretamente para árvores completas ou cheias)
int AlturaArv(TNo *r)
{
    if (r == NULL)
        return 0;
    else
        return 1 + AlturaArv(r->esq);
}

// Imprime a árvore nível por nível (travessia em largura) usando uma Fila dinâmica
void ImprimeArvoreNvl(TNo *r, int n)
{
    DFila fila;
    InicializaFila(&fila);
    int N = 0, D = 1, i = 1;
    
    if (r != NULL)
    {

        printf("Conteudo da arvore\n");
        printf("Nivel Valores\n");
        printf("---------------------------------------- ");
        
        // Começa enfileirando a raiz
        IncluiItemFila(&fila, r);

        // Loop de processamento da fila
        while(1)
        {
            
            TNo *numero = DesemFilar(&fila);
            if (numero == NULL)
                break;
            
            // Lógica para identificar mudança de nível com base na potência de 2
            // Supondo uma árvore binária cheia para quebra de linha
            if ( i == D ){
                printf("\n %d: %d ", N, numero->valor);
                N++;
                D = D * 2; // Dobra a quantidade esperada de nós para o próximo nível (1, 2, 4, 8...)
            }
            else
                printf(" %d  ", numero->valor);

            // Enfileira os filhos (esquerda e direita) se existirem
            if (numero->esq != NULL)
                IncluiItemFila(&fila, numero->esq);
            if (numero->dir != NULL)
                IncluiItemFila(&fila, numero->dir);
            i++;
        }
    }
}

/// --- Funções de Manipulação da Fila ---

// Inicializa os ponteiros e o contador da fila
void InicializaFila(DFila *lista)
{
    lista->topo = NULL;
    lista->fim = NULL;
    lista->qtde = 0;
}

// Insere um novo item no final da fila (Enqueue)
int IncluiItemFila(DFila *lista, TNo *valor)
{
    TLista *novo = (TLista *)malloc(sizeof(TLista));

    if (novo == NULL)
    {
        puts("Erro fatal: Memoria insuficiente para esta operacao");
        return MEMORY_ERROR;
    }
    novo->valor = valor;
    novo->prox = NULL;

    if (lista->topo == NULL)
    {
        // Se a fila estava vazia, o novo nó é o primeiro e o último
        lista->topo = novo;
        lista->fim = novo;
    }
    else
    {
        // Senão, insere no fim e atualiza o ponteiro fim
        lista->fim->prox = novo;
        lista->fim = novo;
    }
    lista->qtde++;
    return TRUE;
}

// Remove o item do início da fila e retorna o valor (Dequeue)
TNo *DesemFilar(DFila *lista)
{
    if (lista->topo == NULL)
        return NULL;

    TLista *temp = lista->topo;
    TNo *valor = temp->valor;

    // Avança o ponteiro de início para o próximo nó
    lista->topo = lista->topo->prox;

    // Se a fila ficou vazia, ajusta o ponteiro fim também
    if (lista->topo == NULL)
        lista->fim = NULL;

    // Libera a memória do nó da lista (não da árvore)
    free(temp);
    lista->qtde--;

    return valor;
}