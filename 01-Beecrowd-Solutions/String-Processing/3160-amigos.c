/*
Beecrowd : 3160 - Amigos
https://judge.beecrowd.com/pt/problems/view/3160

**Explicação do Código:**
Este programa simula a inserção de um novo amigo em uma lista de amigos existente.
A lista pode ser composta por vários nomes separados por espaço.

A regra de inclusão é dada por uma terceira entrada:
1. Se a entrada for "nao", o novo amigo é simplesmente adicionado ao final da lista.
2. Se a entrada for um nome existente na lista, o novo amigo deve ser inserido **antes** desse amigo específico.

O fluxo do algoritmo é:
1. Lê a lista de amigos atual e o nome do novo amigo usando `fgets` (para permitir espaços nos nomes).
2. Remove o caractere de nova linha (`\n`) ao final das strings.
3. Lê a instrução ("nao" ou o nome de um amigo existente).
4. Se for "nao", imprime a lista original mais o novo amigo.
5. Caso contrário, encontra a posição do nome indicado na lista original usando `strstr`.
6. Calcula onde começar a impressão:
   - Imprime a parte da lista antes do amigo indicado.
   - Imprime o novo amigo.
   - Imprime o restante da lista começando pelo amigo indicado (substituindo a posição dele).
*/

#include <stdio.h>
#include <string.h>

int main() {
    char friends[10000];      // Lista de amigos atual
    char newFriend[10000];    // Nome do novo amigo
    char indication[30];     // Comando: "nao" ou o nome de um amigo existente

    // Lê as linhas completas (incluindo espaços)
    fgets(friends, sizeof(friends), stdin);
    fgets(newFriend, sizeof(newFriend), stdin);
    
    // Remove o caractere de nova linha do final das strings
    friends[strcspn(friends, "\n")] = '\0';
    newFriend[strcspn(newFriend, "\n")] = '\0';
     
    // Lê o comando de inserção
    scanf("%s", indication);

    // Se o comando for "nao", apenas anexa o novo amigo
    if (strcmp(indication, "nao") == 0) {
        printf("%s %s\n", friends, newFriend);
        return 0;
    }
    
    // Busca o nome indicado dentro da lista de amigos
    char *foundPtr = strstr(friends, indication);
    
    // Calcula a posição (índice) onde o nome foi encontrado
    int index;
    index = foundPtr - friends; 
    
    // Imprime a parte da lista que vem antes do amigo encontrado
    for (int i = 0; i < index; i++) 
        printf("%c", friends[i]);

    // Imprime o novo amigo e o restante da lista começando pelo amigo encontrado
    // Isso insere o novo amigo 'antes' do amigo 'foundPtr'
    printf("%s %s\n", newFriend, foundPtr);
    

    return 0;
}