#include <stdio.h>
#include <math.h>

// Protótipo da função recursiva de Ackermann
int Ackerman( int m , int n);

int main()
{
    // Variáveis inteiras para armazenar os argumentos m e n
    int  m , n;

    // Loop 'do-while' que continua executando até que ambos m e n sejam 0
    do{
        // Solicita ao usuário os valores de m e n
        printf("Ackerman m e n? \n");
        scanf(" %d %d",&m,&n);
        
        // Verifica se o usuário não digitou 0 0 (condição de saída do programa)
        if(m != 0 || n != 0){
            // Chama a função Ackerman com os valores fornecidos e imprime o resultado
            printf("Ackerman: %d\n", Ackerman(m,n));
        }
    // O loop repete enquanto m ou n forem diferentes de 0
    }while(m != 0 || n != 0);
    return 0;
}

// Implementação da Função de Ackermann
// É uma função matemática recursiva que cresce muito rapidamente
int Ackerman( int m , int n){
    // Caso base: Se m é 0, retorna n + 1
    if (m == 0 ){
        return   n+1;
    // Se m é maior que 0 e n é 0, chama a função recursivamente para (m-1, 1)
    }else if( n == 0){
        return  Ackerman(m-1, 1);
    // Se m e n são maiores que 0, faz a chamada recursiva dupla (recursão aninhada)
    }else {
        return  Ackerman(m-1,Ackerman(m,n-1));
    }
}