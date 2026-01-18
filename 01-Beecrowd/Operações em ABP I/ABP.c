#include <stdio.h>
#include <stdlib.h>
#include <string.h>


// Definição de constantes para valores booleanos
#define FALSE	0
#define TRUE	1

// Estrutura do Nó da Árvore Binária
struct regNo
{	struct regNo *esq; // Ponteiro para o filho à esquerda (menores)
    char valor;         // Valor armazenado (um caractere)
    struct regNo *dir; // Ponteiro para o filho à direita (maiores)
};
typedef struct regNo TNo;

// Protótipos das funções
TNo *Pesquisa(TNo *, char);                 // Busca um caractere na árvore
TNo *AchaPai(TNo *, char);                  // Encontra o nó pai para inserção
void ImprimeArvorePre(TNo *r,int *primeiro);// Imprime em Pré-ordem (Raiz, Esq, Dir)
void ImprimeArvoreIn(TNo *r, int *primeiro );// Imprime em Em-ordem (Esq, Raiz, Dir)
void ImprimeArvorePost(TNo *r,int *primeiro);// Imprime em Pós-ordem (Esq, Dir, Raiz)
int IncluiItem(TNo **, char);               // Insere um novo caractere
void DestroiLista(TNo *r);                  // Libera a memória da árvore


int main(void)
{	TNo *raiz = NULL;
    char e[8];   // String para ler o comando (ex: INFIXA, I A)
    char letra;

    // Loop principal que lê comandos até o fim do arquivo (EOF)
    while(scanf(" %s", e) != EOF ) {

        // Verifica se o comando é INFIXA (impressão em ordem)
        if(strcmp("INFIXA", e) == 0 ) {
            int primeiro = 0;
            ImprimeArvoreIn(raiz, &primeiro);
            printf("\n");
        } 
        // Verifica se o comando começa com 'I' (Inserção: I <letra>)
        else if('I' == e[0]) {
            scanf(" %c", &letra) ;
            if (IncluiItem(&raiz, letra) == FALSE)
            {	puts("Memoria insuficiente para inclusao");
                return 2;
            }
        } 
        // Verifica se o comando é PREFIXA (impressão pré-ordem)
        if(strcmp("PREFIXA",e) == 0) {
            int primeiro = 0;
            ImprimeArvorePre(raiz,&primeiro);
            printf("\n");
        }
        // Verifica se o comando é POSFIXA (impressão pós-ordem)
        else if (strcmp("POSFIXA", e) == 0) {
            int primeiro = 0;
            ImprimeArvorePost(raiz,&primeiro);
            printf("\n");
        }
        // Verifica se o comando começa com 'P' (Pesquisa: P <letra>)
        else if (e[0] == 'P') {
            scanf(" %c", &letra);
            if (Pesquisa(raiz, letra) != NULL)
                printf("%c existe\n", letra);
            else
                printf("%c nao existe\n", letra);
    }
        

    }
    // Libera toda a memória alocada para a árvore antes de encerrar
    DestroiLista(raiz);
    raiz = NULL;
    return 0;
}

// Função para incluir um novo caractere na árvore (ordenação por valor ASCII)
int IncluiItem(TNo **r, char n)
{	TNo *aux, *pai;

    // Aloca memória para o novo nó
    aux = (TNo *) malloc(sizeof(TNo));
    if (aux == NULL)
        return FALSE;

    aux->valor = n;
    aux->dir = NULL;
    aux->esq = NULL;

    /* Fazendo o encadeamento do novo noh */
    pai = AchaPai(*r, n);
    
    // Se não achou pai, a árvore estava vazia. O novo nó é a raiz.
    if (pai == NULL)
        *r = aux;
    else if (n <= pai->valor)
        // Se o valor é menor ou igual, insere à esquerda
        pai->esq = aux;
    else
        // Se o valor é maior, insere à direita
        pai->dir = aux;

    return TRUE;
}

// Função recursiva para encontrar o nó pai adequado para o valor 'n'
TNo *AchaPai(TNo *r, char n)
{	if (r == NULL)
        return NULL;
    else if (n <= r->valor)
        /* Se n é menor ou igual, deve ir para a subárvore esquerda */
        if (r->esq == NULL)
            return r; // Encontrou o lugar (espaço vazio à esquerda)
        else
            return AchaPai(r->esq, n);
    else
        /* Se n é maior, deve ir para a subárvore direita */
        if (r->dir == NULL)
            return r; // Encontrou o lugar (espaço vazio à direita)
        else
            return AchaPai(r->dir, n);
}

// Imprime a árvore em PRÉ-ORDEM (Raiz -> Esquerda -> Direita)
// O ponteiro 'primeiro' controla se deve haver um espaço antes do número (formatação)
void ImprimeArvorePre(TNo *r, int *primeiro)
{	

    if (r != NULL)
    {

        // Se for o primeiro elemento impresso, não imprime espaço antes
        if(*primeiro == 0){
            printf("%c", r->valor);
            *primeiro = 1; // Marca que o próximo precisa de espaço
        }else
            printf(" %c", r->valor);

        // Chamadas recursivas para esquerda e direita
        ImprimeArvorePre(r->esq,primeiro);
        ImprimeArvorePre(r->dir, primeiro);
    }
}

// Imprime a árvore em EM-ORDEM ou INFIXA (Esquerda -> Raiz -> Direita)
void ImprimeArvoreIn(TNo *r, int *primeiro)
{	

    if (r != NULL)
    {
        // Primeiro imprime a subárvore esquerda
        ImprimeArvoreIn(r->esq, primeiro );

        // Depois imprime a raiz atual (tratamento do espaço igual aos outros)
        if(*primeiro == 0){
            printf("%c", r->valor);
            *primeiro = 1;
        }else
            printf(" %c", r->valor);;

        // Por fim imprime a subárvore direita
        ImprimeArvoreIn(r->dir, primeiro);

    }
}

// Imprime a árvore em PÓS-ORDEM (Esquerda -> Direita -> Raiz)
void ImprimeArvorePost(TNo *r, int *primeiro)
{	


    if (r != NULL)
    {
        // Primeiro imprime os filhos
        ImprimeArvorePost(r->esq, primeiro);
        ImprimeArvorePost(r->dir, primeiro);

        // Imprime a raiz por último (tratamento do espaço igual aos outros)
        if(*primeiro == 0){
            printf("%c", r->valor);
            *primeiro = 1;
        }else
            printf(" %c", r->valor);

    }
}




// Libera a memória da árvore recursivamente (Pós-ordem)
void DestroiLista(TNo *r)
{


    if(r != NULL)
    {

        DestroiLista(r->esq);
        DestroiLista(r->dir);

        free(r);
    }

}

// Função recursiva para pesquisar se um caractere existe na árvore
TNo *Pesquisa(TNo *r, char n){
    if (r != NULL){
         // Se o valor buscado é maior, desce à direita
         if( n > r->valor )
            return Pesquisa(r->dir, n);
        // Se é menor, desce à esquerda
        else if( n < r->valor )
            return Pesquisa(r->esq, n);
        // Se igual, encontrou o nó
        else if (n == r->valor)
            return r;
    }
    // Se chegar em NULL, o valor não existe
    return NULL; 
}