/*
 * 
 * ARQUIVO: main.c
 * 
 * Parte cliente da aplicação.
 * Gerencia o menu de opções (Incluir, Imprimir, Atualizar, Excluir, Sair)
 * e interage com o usuário através da entrada padrão (scanf).
 * 
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lista.h"

int main(void)
{
    TList list;
    char operation = '.';
    char productName[25];
    float productQty;
    TItem *aux;

    // Inicializa a lista antes de usar
    InitializeList(&list);

    // Loop principal que continua até o usuário digitar '*'
    while(operation != '*') {
        scanf(" %c", &operation);

        // Lê o nome do produto, exceto para o comando de saída
        if(operation != '*') {
            scanf("%24s", productName);
            // Se for inclusão, também lê a quantidade
            if(operation == 'I')
                scanf("%f", &productQty);
        }
        
        switch(operation) {

        case 'I': // Incluir
            InsertItem(&list, productName, productQty);
            printf("Incluiu %s \n", productName);
            productQty = 0;
            break;
            
        case 'P': // Imprimir
            // Verifica se é para imprimir reverso ("R") ou normal ("F")
            if(strcmp("R", productName) == 0)
                PrintListBackward(&list);
            else if(strcmp("F", productName) == 0)
                PrintListForward(&list);
            break;
            
        case 'A': // Atualizar (Marcar como comprado)
            if(UpdateItemStatus(&list, productName))
                printf("Comprou %s \n", productName);
            break;
            
        case 'X': // Excluir
            if (RemoveItem(&list, productName))
                printf("Excluiu %s\n", productName);
            break;
            
        case '*': // Sair
            printf("Fim do programa ( %d itens sem comprar)\n", list.count - list.boughtCount);
            break;
            
        default:
            printf("Operacao invalida.\n");
        }
    }
    return EXEC_SUCCESS;
}