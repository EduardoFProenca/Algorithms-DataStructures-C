/*
 * Este programa tem como função validar uma senha com base em regras 
 * específicas de segurança. O fluxo de execução é o seguinte:
 *
 * 1. ENTRADA DE DADOS:
 *    - O usuário é solicitado a inserir uma "Senha" (atual) e uma "Nova Senha".
 *    - Ambas as lidas são limitadas a 12 caracteres para evitar estouros de buffer (buffer overflow).
 *
 * 2. VALIDAÇÃO INICIAL:
 *    - O programa verifica se a "Nova Senha" é estritamente igual à "Senha" digitada anteriormente.
 *      *Nota: Lógica original preservada (strcmp == 0).*
 *    - Verifica se o tamanho da senha é de pelo menos 6 caracteres.
 *
 * 3. ANÁLISE DE COMPLEXIDADE:
 *    - Caso a validação inicial passe, o programa percorre cada caractere da senha
 *      para contar quantos números, letras maiúsculas e letras minúsculas existem.
 *
 * 4. CRITÉRIO DE SUCESSO:
 *    - Para ser considerada "ok", a senha deve possuir:
 *      a) Pelo menos uma letra minúscula.
 *      b) Pelo menos uma letra maiúscula.
 *      c) Pelo menos um dígito numérico.
 *
 * 5. SAÍDA:
 *    - Se tudo estiver correto, imprime "Nova senha ok".
 *    - Se qualquer regra falhar (igualdade, tamanho ou tipos de caracteres),
 *      imprime "Nova senha invalida".
 */

#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main()
{
    // Variáveis para armazenar as senhas
    // Tamanho definido como 13 para acomodar até 12 caracteres + o terminador nulo (\0)
    char newPassword[13], password[13];
    
    // Contadores para os tipos de caracteres encontrados na senha
    int numbers = 0, uppercase = 0, lowercase = 0; 
    
    // Solicita e lê a senha atual (limitada a 12 caracteres)
    printf("\nDigite a Senha: ");
    scanf("%12s", password); 
    
    // Solicita e lê a nova senha (limitada a 12 caracteres)
    printf("Digite a Nova Senha: ");
    scanf("%12s", newPassword);
    
    // Verifica se a nova senha é idêntica à anterior E se o tamanho é maior ou igual a 6
    // Nota: A lógica original (strcmp == 0) exige que sejam iguais.
    if(strcmp(newPassword, password) == 0 && strlen(password) >= 6){
        
        // Loop que percorre a string caractere por caractere
        for(int i = 0; i < strlen(password); i++){
            
            // Verifica se o caractere atual é um dígito (0-9)
            if(isdigit(password[i]) != 0)
                numbers++; // Incrementa o contador de números
            // Se não for número, verifica se é letra maiúscula (A-Z)
            else if(isupper(password[i]) != 0)
                uppercase++; // Incrementa o contador de maiúsculas
            // Se não for maiúscula, verifica se é letra minúscula (a-z)
            else if(islower(password[i]) != 0)
                lowercase++; // Incrementa o contador de minúsculas
        }
        
        // Validação final: A senha só será aceita se tiver pelo menos
        // um de cada tipo (maiúscula, minúscula e número)
        if(lowercase > 0 && uppercase > 0 && numbers > 0)
            printf("Nova senha ok");
        else
            printf("Nova senha invalida");
    }
    else{
        // Caso as senhas não sejam iguais ou o tamanho seja insuficiente
        printf("Nova senha invalida");
    }
    
    return 0;
}