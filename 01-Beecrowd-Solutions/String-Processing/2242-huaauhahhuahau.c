/*
Beecrowd : 2242 - Huaauhahhuahau
https://judge.beecrowd.com/pt/problems/view/2242

**Explicação do Código:**
Este programa verifica se uma risada é considerada "engraçada" ou não.
O critério definido pelo problema é: se tirarmos todas as consoantes da risada e ficarmos apenas com as vogais,
a sequência resultante deve ser um palíndromo (lê-se da mesma forma de frente para trás e de trás para frente).

O fluxo do algoritmo é:
1. Lê a string original de entrada.
2. Percorre a string e cria uma nova string contendo apenas as vogais (a, e, i, o, u).
3. Verifica se essa nova string de vogais é um palíndromo, comparando o primeiro com o último caractere,
   o segundo com o penúltimo, e assim sucessivamente.
4. Se for um palíndromo, imprime "S". Caso contrário, imprime "N".
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    char character;
    int i = 0, j = 0;
    char inputString[51], vowelsSequence[51] ;

    scanf(" %s", inputString);

    // Loop para filtrar apenas as vogais e armazená-las em uma nova string
    for (i = 0; i < strlen(inputString); i++)
    {

        character = inputString[i];

        switch(character) {
        case 'a':
        case 'e':
        case 'i':
        case 'o':
        case 'u':
            vowelsSequence[j] = character;
            j++;
            break;
        default:
            break;
        }
    }
    // Adiciona o terminador nulo ao final da string de vogais
    vowelsSequence[j] = '\0';

    // Índice que percorre do final para o começo na verificação de palíndromo
    int endIndex = strlen(vowelsSequence) - 1 ;
    int startIndex;

    // Loop que verifica se a string de vogais é um palíndromo
    for( startIndex = 0; startIndex < (strlen(vowelsSequence) / 2); startIndex++) {

        // Se os caracteres correspondentes (início e fim) forem diferentes, não é palíndromo
        if(vowelsSequence[startIndex] != vowelsSequence[endIndex] ) {
            printf("N\n");
            return 0;
        }
        endIndex--;
    }

    // Se o loop terminar sem erros, é palíndromo
    printf("S\n");

    return 0;
}