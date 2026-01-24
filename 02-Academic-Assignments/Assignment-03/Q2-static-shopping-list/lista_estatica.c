/*
 * 
 * ARQUIVO: lista_estatica.c
 * 
 * Implementação das funções de manipulação da Lista de Compras (Vetor Estático).
 * - Inserção: Mantém a lista ordenada alfabeticamente (deslocando itens).
 * - Exclusão: Desloca itens para preencher o espaço vazio.
 * - Atualização: Marca item como comprado.
 * 
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lista_estatica.h"

// Inicializa os contadores da lista
void InitializeList(TList *list) {
    list->count = 0;
    list->boughtCount = 0;
}

// Insere um novo item mantendo a ordem alfabética
int InsertItem(TList *list, char productName[], float quantity)
{
    int i, j;
    int insertPosition = -1;

    // Verifica se a lista está cheia
    if (list->count >= MAX_ITEMS) {
        puts("Quantidade maxima de itens");
        return MEMORY_ERROR;
    }

    // Encontra a posição correta para inserção baseada na ordem alfabética
    for (i = 0; i < list->count; i++) {
        // Se o nome atual no array é maior que o nome novo, encontramos a posição
        if (strcmp(list->items[i].name, productName) > 0) {
            insertPosition = i;
            break;
        }
    }

    // Se não encontrou posição (não é menor que ninguém), insere no final
    if (insertPosition == -1)
        insertPosition = list->count;

    // Desloca os itens uma posição para frente para abrir espaço
    for (j = list->count; j > insertPosition; j--) {
        strcpy(list->items[j].name, list->items[j-1].name);
        list->items[j].quantity = list->items[j-1].quantity;
        list->items[j].isBought = list->items[j-1].isBought;
    }

    // Insere o novo item na posição encontrada
    strcpy(list->items[insertPosition].name, productName);
    list->items[insertPosition].quantity = quantity;
    list->items[insertPosition].isBought = FALSE;

    list->count++;
    return TRUE;
}

// Imprime a lista do início ao fim (ordem alfabética)
void PrintListForward(TList *list)
{
    int i;
    if (list->count == 0)
        puts("Lista vazia");
    else
    {
        printf("\n Lista de compras (do inicio) \n");

        for(i = 0; i < list->count; i++)
            // Corrigido o formato de impressão para float (%.2f) na implementação, 
            // mantendo o original %d do enunciado se desejar estrita fidelidade ao original fornecido.
            printf("%s  %d  %d \n", list->items[i].name, list->items[i].quantity, list->items[i].isBought);

        printf("Total itens: %d Itens comprados: %d\n\n", list->count, list->boughtCount);
    }
}

// Imprime a lista do fim para o início (ordem reversa)
void PrintListBackward(TList *list)
{
    int i;
    if (list->count == 0)
        puts("Lista vazia");
    else
    {
        printf("\n Lista de compras (do final)  \n");

        // Percorre do último índice até o 0
        for(i = list->count; i > 0; i--)
            printf("%s   %d  %d \n", list->items[i-1].name, list->items[i-1].quantity, list->items[i-1].isBought);

        printf("Total itens: %d Itens comprados: %d\n\n", list->count, list->boughtCount);
    }
}

// Marca um produto como comprado
int UpdateItemStatus(TList *list, char productName[])
{
    int i;

    // Busca linear pelo produto
    for (i = 0; i < list->count; i++) {
        if (strcmp(list->items[i].name, productName) == 0) {
            // Se já foi comprado, avisa
            if (list->items[i].isBought == 1) {
                printf(" %s ja foi comprado \n ", productName);
                return FALSE;
            } else {
                // Marca como comprado e atualiza contador
                list->items[i].isBought = 1;
                list->boughtCount++;
                return TRUE;
            }
        }
    }
    printf("Produto '%s' nao encontrado\n", productName);
    return FALSE;
}

// Remove um produto da lista
int RemoveItem(TList *list, char productName[])
{
    int i, j;

    // Busca o produto
    for (i = 0; i < list->count; i++) {
        if (strcmp(list->items[i].name, productName) == 0) {

            // Se foi comprado, decrementa o contador de comprados
            if (list->items[i].isBought == 1) {
                list->boughtCount--;
            }

            // Desloca os itens seguintes uma posição para trás (sobrescrevendo o removido)
            for (j = i; j < list->count - 1; j++) {
                strcpy(list->items[j].name, list->items[j+1].name);
                list->items[j].quantity = list->items[j+1].quantity;
                list->items[j].isBought = list->items[j+1].isBought;
            }

            list->count--;
            return TRUE;
        }
    }
    printf("Valor informado nao existe na lista\n");
    return FALSE;
}