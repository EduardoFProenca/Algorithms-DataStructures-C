/*
Beecrowd : 2674 - Super Primos - Ativar!
https://judge.beecrowd.com/pt/problems/view/2674

**Explicação do Código:**
Este programa lê números inteiros e classifica cada um em três categorias baseadas em primalidade:
1. **Nada**: O número não é primo.
2. **Primo**: O número é primo, mas possui ao menos um dígito que não é primo (como 0, 1, 4, 6, 8 ou 9).
3. **Super**: O número é primo E todos os seus dígitos também são primos (2, 3, 5, 7).

A lógica utiliza a mesma função de verificação de primalidade tanto para o número inteiro
quanto para cada um dos seus dígitos individuais.
*/

#include <stdio.h>
#include <math.h>

#define TRUE  1
#define FALSE 0

// Protótipo da função
char IsPrime(int n);

int main()
{
    int number, temp;

    while( scanf(" %d", &number) != EOF) {

        if (IsPrime(number) ) {
            // Se o número é primo, verificamos cada dígito
            temp = number;
            while(temp > 0) {
                // Verifica se o último dígito (temp % 10) é primo
                if (IsPrime(temp % 10)) {
                    temp = temp / 10; // Remove o último dígito e continua
                } else {
                    // Se encontrar um dígito não primo, o número é apenas "Primo"
                    printf("Primo\n");
                    break;
                }
            }
            // Se o loop terminou e temp virou 0, todos os dígitos eram primos
            if (temp == 0)
                printf("Super\n");

        } else {
            // Se o próprio número não é primo
            printf("Nada\n");
        }
    }
    return 0;
}

char IsPrime(int n)
/* Retorna TRUE se n for um número primo */
{	
    int i, limit = sqrt(n) + 2;

    if (n < 0) return IsPrime(-n);
    if (n < 5 || !(n % 2) || !(n % 3)) return (n == 2 || n == 3);

    // Otimização: verificando divisores de 6k ± 1
    for (i = 5; i < limit; i += 6)
        if ((!(n % i)) || (!(n % (i + 2)))) return FALSE;

    return TRUE;
}