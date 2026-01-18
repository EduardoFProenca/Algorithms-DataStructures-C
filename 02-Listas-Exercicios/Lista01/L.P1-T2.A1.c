#include <stdio.h>
#include <math.h>

// Protótipo da função que realiza o cálculo do IAC (Índice de Adiposidade Corporal)
double calculaIAC(double circunferenciaIAC, double  alturaIAC);
// Protótipo da função que determina a categoria baseada no resultado do IAC e no sexo
int resultado(double IACRes, char sexoRes);

int main()
{
    // Variáveis para armazenar entrada de dados e resultados
    char sexo = 'i';
    double  altura, circunferencia, IAC;
    // Array de strings contendo as classificações possíveis (índices de 0 a 5)
    char Classificacao[6][25] = {"Excesso de gordura", "Moderada", "Ideal", "Baixa", "Excepcionalmente baixa", "inválido"};
    
    // Loop principal que continua executando até que o usuário digite 'X'
    while(sexo !='X') {
        // Solicita entrada dos dados ao usuário
        printf("Qual o sexo(M/F),circunferencia  e  altura : \n");
        // Lê o caractere referente ao sexo
        scanf(" %c",&sexo);
        
        // Verifica se o usuário deseja sair antes de processar os números
        if (sexo!='X') {
            // Lê os valores de circunferência e altura (ponto flutuante / double)
            scanf(" %lf %lf",&circunferencia,&altura);
            
            // Chama a função de cálculo e armazena o resultado na variável IAC
            IAC =  calculaIAC(circunferencia, altura);
            
            // (Linha comentada no código original: impressão de depuração do valor bruto)
            //printf ("%d \n",IAC);
            
            // Imprime a classificação correspondente.
            // A função 'resultado' retorna um índice (0 a 5), usado para acessar o array 'Classificacao'
            printf(" %s\n", Classificacao[resultado(IAC, sexo)]);
        }
    }
    return 0;
}

// Função que implementa a fórmula matemática do IAC
double calculaIAC(double circunferenciaIAC, double alturaIAC) {
    
   // Fórmula: (Circunferência / (Altura * Raiz Quadrada da Altura)) - 18
   return (circunferenciaIAC / (alturaIAC * sqrt(alturaIAC))) - 18;

}

// Função que verifica em qual faixa o IAC se enquadra, de acordo com o sexo
int resultado(double IACRes, char sexoRes) {
    // Lógica para o sexo Masculino
    if (sexoRes == 'M') {
        // Compara o valor do IAC com os limites e retorna o índice da classificação
        if (IACRes > 25) return 0;      // Excesso de gordura
        else if (IACRes >= 19) return 1; // Moderada
        else if (IACRes >= 15) return 2; // Ideal
        else if (IACRes >= 11) return 3; // Baixa
        else if (IACRes >= 6) return 4;  // Excepcionalmente baixa
        else return 5;                   // valor inválido (muito baixo)
    }
    
    // Lógica para o sexo Feminino
    if (sexoRes == 'F') {
        // Compara o valor do IAC com os limites e retorna o índice da classificação
        if (IACRes > 30) return 0;      // Excesso de gordura
        else if (IACRes >= 26) return 1; // Moderada
        else if (IACRes >= 20) return 2; // Ideal
        else if (IACRes >= 16) return 3; // Baixa
        else if (IACRes >= 10) return 4;  // Excepcionalmente baixa
        else return 5;                    // valor inválido (muito baixo)
    }
    // Caso o sexo não seja 'M' nem 'F', retorna "inválido"
    return 5;
}