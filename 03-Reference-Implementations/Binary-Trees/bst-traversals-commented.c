#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Definição de constantes para valores booleanos
#define FALSE 0
#define TRUE 1

// Estrutura do Nó da Árvore Binária
struct regNo
{
    struct regNo *esq; // Ponteiro para o filho à esquerda (menores)
    int valor;         // Valor inteiro armazenado no nó
    struct regNo *mae; // Ponteiro para o nó pai (facilita a remoção)
    struct regNo *dir; // Ponteiro para o filho à direita (maiores)
};
typedef struct regNo TNo;

// Protótipos das funções
int PesquisaValor(TNo *, int);              // Pesquisa se um valor existe na árvore
TNo *Remove(TNo *, int);                    // Remove um nó específico
TNo *AchaPai(TNo *, int);                   // Encontra o nó pai para inserção
void ImprimeArvorePre(TNo *r, int *primeiro); // Impressão Pré-ordem (Raiz, Esq, Dir)
void ImprimeArvoreIn(TNo *r, int *primeiro);  // Impressão Em-ordem/Infixa (Esq, Raiz, Dir)
void ImprimeArvorePost(TNo *r, int *primeiro);// Impressão Pós-ordem (Esq, Dir, Raiz)
int IncluiItem(TNo **, int);                // Insere um novo valor
void DestroiLista(TNo *r);                  // Libera memória da árvore

int main(void)
{
    // Ponteiro para a raiz da árvore, iniciando vazia
    TNo *raiz = NULL;
    char e[8]; // String para armazenar o comando lido (ex: INFIXA, I 10)
    int num;

    // Loop principal que lê comandos até o fim do arquivo (EOF)
    while (scanf(" %s", e) != EOF)
    {
        // Comando: INFIXA (Imprimir em ordem)
        if (strcmp("INFIXA", e) == 0)
        {
            int primeiro = 0;
            ImprimeArvoreIn(raiz, &primeiro);
            printf("\n");
        }
        // Comando: I (Inserir - I <valor>)
        else if ('I' == e[0])
        {
            scanf(" %d", &num);
            if (IncluiItem(&raiz, num) == FALSE)
            {
                puts("Memoria insuficiente para inclusao");
                return 2;
            }
        }
        // Comando: PREFIXA (Imprimir pré-ordem)
        if (strcmp("PREFIXA", e) == 0)
        {
            int primeiro = 0;
            ImprimeArvorePre(raiz, &primeiro);
            printf("\n");
        }
        // Comando: POSFIXA (Imprimir pós-ordem)
        else if (strcmp("POSFIXA", e) == 0)
        {
            int primeiro = 0;
            ImprimeArvorePost(raiz, &primeiro);
            printf("\n");
        }
        // Comando: P (Pesquisar - P <valor>)
        else if (e[0] == 'P')
        {
            scanf(" %d", &num);
            if (PesquisaValor(raiz, num) != FALSE)
                printf("%d existe\n", num);
            else
                printf("%d nao existe\n", num);
        }
        // Comando: R (Remover - R <valor>)
        if (e[0] == 'R')
        {
            TNo *pai = NULL;
            scanf(" %d", &num);
            // A função Remove pode alterar a raiz, por isso atribuímos o retorno a 'raiz'
            raiz = Remove(raiz, num);
        }
    }

    // Libera toda a memória alocada ao final do programa
    DestroiLista(raiz);
    raiz = NULL;
    return 0;
}

// Função para incluir um novo número na árvore binária de busca
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

    /* Fazendo o encadeamento do novo noh */
    pai = AchaPai(*r, n);
    
    // Se pai é NULL, a árvore estava vazia. O novo nó é a raiz.
    if (pai == NULL)
    {
        *r = aux;
        aux->mae = NULL;
    }
    else
    {
        // Se o valor for menor ou igual, insere à esquerda
        if (n <= pai->valor)
            pai->esq = aux;
        // Senão, insere à direita
        else
            pai->dir = aux;
        // Atualiza o ponteiro 'mae' (pai) do novo nó
        aux->mae = pai;
    }
    return TRUE;
}

// Função recursiva para encontrar onde o novo nó deve ser inserido
TNo *AchaPai(TNo *r, int n)
{
    if (r == NULL)
        return NULL;
    else if (n <= r->valor)
        /* Se o valor é menor ou igual, deve ir para a esquerda */
        if (r->esq == NULL)
            return r; // Encontrou o lugar vazio
        else
            return AchaPai(r->esq, n);
    else
        /* Se o valor é maior, deve ir para a direita */
        if (r->dir == NULL)
            return r; // Encontrou o lugar vazio
        else
            return AchaPai(r->dir, n);
}

// Impressão em PRÉ-ORDEM (Raiz -> Esq -> Dir)
void ImprimeArvorePre(TNo *r, int *primeiro)
{

    if (r != NULL)
    {
        // Controle de espaçamento: o primeiro não tem espaço antes, os outros sim
        if (*primeiro == 0)
        {
            printf("%d", r->valor);
            *primeiro = 1;
        }
        else
            printf(" %d", r->valor);

        ImprimeArvorePre(r->esq, primeiro);
        ImprimeArvorePre(r->dir, primeiro);
    }
}

// Impressão em EM-ORDEM ou INFIXA (Esq -> Raiz -> Dir)
void ImprimeArvoreIn(TNo *r, int *primeiro)
{

    if (r != NULL)
    {
        ImprimeArvoreIn(r->esq, primeiro);

        if (*primeiro == 0)
        {
            printf("%d", r->valor);
            *primeiro = 1;
        }
        else
            printf(" %d", r->valor);

        ImprimeArvoreIn(r->dir, primeiro);
    }
}

// Impressão em PÓS-ORDEM (Esq -> Dir -> Raiz)
void ImprimeArvorePost(TNo *r, int *primeiro)
{

    if (r != NULL)
    {
        ImprimeArvorePost(r->esq, primeiro);
        ImprimeArvorePost(r->dir, primeiro);

        if (*primeiro == 0)
        {
            printf("%d", r->valor);
            *primeiro = 1;
        }
        else
            printf(" %d", r->valor);
    }
}

// Libera memória recursivamente
void DestroiLista(TNo *r)
{

    if (r != NULL)
    {
        DestroiLista(r->esq);
        DestroiLista(r->dir);
        free(r);
    }
}

// Função recursiva de busca. Retorna TRUE (1) se encontrar, FALSE (0) se não.
int PesquisaValor(TNo *r, int n)
{
    if (r == NULL)
        return FALSE;
    else if (r->valor == n)
        return TRUE;
    else if (r->valor > n)
        return PesquisaValor(r->esq, n);
    else
        return PesquisaValor(r->dir, n);
}

// Função complexa para remover um nó da árvore mantendo as propriedades de BST
TNo *Remove(TNo *r, int n)
{
    // Caso base: árvore vazia ou valor não encontrado
    if (r == NULL)
        return NULL;

    // Encontrou o nó a ser removido
    if (r->valor == n)
    {
        /* Caso 1: Nó sem filhos (Folha) */
        if (r->esq == NULL && r->dir == NULL)
        {
            // Se tiver um pai, remove o link do pai apontando para este nó
            if (r->mae != NULL)
            {
                if (r->mae->esq == r)
                    r->mae->esq = NULL;
                else
                    r->mae->dir = NULL;
            }
            free(r);
            return NULL; // Retorna NULL para atualizar o ponteiro do pai (ou raiz)
        }
        /* Caso 2: Nó com apenas um filho */
        else if (r->esq == NULL || r->dir == NULL)
        {
            TNo *filho ;
            // Identifica qual filho existe (esq ou dir)
            filho = (r->esq != NULL) ? r->esq : r->dir;
            
            // Atualiza o pai para apontar para o neto
            if (r->mae != NULL)
            {
                if (r->mae->esq == r)
                    r->mae->esq = filho;
                else
                    r->mae->dir = filho;
                filho->mae = r->mae; // Atualiza o 'mae' do neto
            }
            else
            {
                // Se não tem pai (era raiz), o filho vira a nova raiz e não tem pai
                filho->mae = NULL;
            }
            free(r);
            return filho; // Retorna o filho para substituir o nó removido
        }
        /* Caso 3: Nó com dois filhos */
        else
        {
            // Estratégia: Trocar o valor pelo maior valor da subárvore esquerda (ANTECESSOR)
            TNo *antecessor ;
            antecessor = r->esq;

            // Navega até o último elemento à direita da subárvore esquerda
            while (antecessor->dir != NULL)
            {
                antecessor = antecessor->dir;
            }
            
            // Copia o valor do antecessor para o nó atual
            r->valor = antecessor->valor;
            
            // Remove recursivamente o antecessor (que agora está duplicado na subárvore esquerda)
            // Nota: O antecessor nunca terá filho direito (por definição), logo entrará no Caso 1 ou 2
            r->esq = Remove(r->esq, antecessor->valor);
            return r;
        }
    }
    else
    {
        // Se o valor a remover é menor, busca na esquerda
        if (n < r->valor)
            r->esq = Remove(r->esq, n);
        // Se é maior, busca na direita
        else
            r->dir = Remove(r->dir, n);
        return r;
    }
}