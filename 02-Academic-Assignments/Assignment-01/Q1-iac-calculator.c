/*
 * 
 * Este programa calcula o Índice de Adiposidade Corporal (IAC) de uma pessoa
 * e classifica o nível de gordura corporal baseado no resultado e no sexo biológico.
 *
 * FÓRMULA UTILIZADA:
 * IAC = (Circunferência do Quadril / (Altura * sqrt(Altura))) - 18
 *
 * FLUXO DO PROGRAMA:
 * 1. O programa entra em um loop solicitando dados ao usuário (Sexo, Circunferência, Altura).
 * 2. A condição de saída do loop é digitar 'X' no campo do sexo.
 * 3. Se os dados forem válidos, a função `calculateIAC` aplica a fórmula matemática.
 * 4. A função `getCategoryIndex` recebe o IAC calculado e o sexo, verificando
 *    em qual faixa de valores o resultado se encaixa.
 * 5. A função retorna um índice numérico (0 a 5) que é utilizado para acessar
 *    um array de strings e imprimir a classificação correspondente (ex: "Ideal").
 *
 * OBS: As strings de saída (ex: "Baixa", "Moderada") são mantidas em português
 * para o usuário final, enquanto o código interno está em inglês.
 * 
 */

#include <stdio.h>
#include <math.h>

// Protótipo da função que realiza o cálculo do IAC (Índice de Adiposidade Corporal)
double calculateIAC(double hipCircumference, double height);

// Protótipo da função que determina o índice da categoria baseada no IAC e no sexo
int getCategoryIndex(double iacValue, char gender);

int main()
{
    // Variáveis para armazenar entrada de dados e resultados
    char gender = 'i';
    double height, circumference, iacValue;
    
    // Array de strings contendo as classificações possíveis (índices de 0 a 5)
    // Mapeamento: 0=Excesso, 1=Moderada, 2=Ideal, 3=Baixa, 4=Excepcionalmente baixa, 5=Inválido
    char categories[6][25] = {
        "Excesso de gordura", 
        "Moderada", 
        "Ideal", 
        "Baixa", 
        "Excepcionalmente baixa", 
        "inválido"
    };
    
    // Loop principal que continua executando até que o usuário digite 'X'
    while(gender != 'X') {
        // Solicita entrada dos dados ao usuário
        printf("Qual o sexo(M/F),circunferencia  e  altura : \n");
        
        // Lê o caractere referente ao sexo
        // O espaço antes de %c é importante para consumir o 'Enter' anterior
        scanf(" %c", &gender);
        
        // Verifica se o usuário deseja sair antes de processar os números
        if (gender != 'X') {
            // Lê os valores de circunferência e altura (ponto flutuante / double)
            scanf(" %lf %lf", &circumference, &height);
            
            // Chama a função de cálculo e armazena o resultado na variável iacValue
            iacValue = calculateIAC(circumference, height);
            
            // Imprime a classificação correspondente.
            // A função 'getCategoryIndex' retorna um índice (0 a 5), 
            // usado para acessar o array 'categories'
            printf(" %s\n", categories[getCategoryIndex(iacValue, gender)]);
        }
    }
    return 0;
}

// Função que implementa a fórmula matemática do IAC
double calculateIAC(double hipCircumference, double height) {
    
    // Fórmula: (Circunferência / (Altura * Raiz Quadrada da Altura)) - 18
    return (hipCircumference / (height * sqrt(height))) - 18;
}

// Função que verifica em qual faixa o IAC se enquadra, de acordo com o sexo
// Retorna um índice inteiro para ser usado na array de classificações
int getCategoryIndex(double iacValue, char gender) {
    
    // Lógica para o sexo Masculino ('M')
    if (gender == 'M') {
        // Compara o valor do IAC com os limites e retorna o índice da classificação
        if (iacValue > 25) return 0;      // Excesso de gordura
        else if (iacValue >= 19) return 1; // Moderada
        else if (iacValue >= 15) return 2; // Ideal
        else if (iacValue >= 11) return 3; // Baixa
        else if (iacValue >= 6) return 4;  // Excepcionalmente baixa
        else return 5;                     // valor inválido (muito baixo)
    }
    
    // Lógica para o sexo Feminino ('F')
    if (gender == 'F') {
        // Compara o valor do IAC com os limites e retorna o índice da classificação
        if (iacValue > 30) return 0;      // Excesso de gordura
        else if (iacValue >= 26) return 1; // Moderada
        else if (iacValue >= 20) return 2; // Ideal
        else if (iacValue >= 16) return 3; // Baixa
        else if (iacValue >= 10) return 4;  // Excepcionalmente baixa
        else return 5;                      // valor inválido (muito baixo)
    }
    
    // Caso o sexo não seja 'M' nem 'F', retorna o índice 5 ("inválido")
    return 5;
}