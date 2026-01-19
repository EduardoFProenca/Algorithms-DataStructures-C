#include <stdio.h>
#include <stdbool.h>

// Protótipos das funções utilizadas no programa
int ValidacaoAno(int ano);
int ValidacaoMes(int mes);  
int ValidacaoDia(int dia, int mes);
int ValidacaoBissextos(int dia, int ano);
int ValidacaoExiste( int dia, int mes);
int DiaSemana(int dia, int mes, int ano);

int main()
{
    // Definição da estrutura 'regData' para armazenar dia, mês e ano
    // Criação do tipo 'TData' para facilitar o uso da estrutura
    struct regData {int dia, mes, ano;}; 
    typedef struct regData TData; 
    TData data;
    
    // Variáveis para armazenar o resultado das validações (0 = válido, 1 = inválido)
    int invalidaAno, invalidaMes, invalidaDia, invalidaBissextos, invalidaExiste ;
    int Semana;
    bool  invalida;
    
    // Array de strings com os dias da semana para impressão formatada
    char resultados [7][15] = {"Domingo", "Segunda-Feira", "Terça-Feira", "Quarta-Feira", "Quinta-Feira", "Sexta-Feira", "Sábado"}; 
    
    do{
        // Solicita a entrada da data ao usuário
		printf(" Data: ");
        scanf("%d %d %d", &data.dia, &data.mes, &data.ano);
        
        // Executa as validações específicas para cada campo da data
        invalidaAno =  ValidacaoAno(data.ano);
        invalidaMes =  ValidacaoMes(data.mes); 
        invalidaDia =  ValidacaoDia(data.dia,data.mes);
        
        // Validação condicional: Se o mês for Fevereiro (2), checa regra de ano bissexto
        invalidaBissextos = 2 == data.mes ? ValidacaoBissextos(data.dia,data.ano) : 0;
        
        // Validação condicional: Se o ano for 1582, checa a data histórica da transição do calendário
        invalidaExiste = 1582 == data.ano ? ValidacaoExiste(data.dia,data.mes) : 0;
        
        // Verifica se a data é geralmente válida (soma das validações deve ser 0)
        invalida =(invalidaAno + invalidaMes + invalidaDia + invalidaBissextos + invalidaExiste)== 0 ? true : false;
    
		// Se a data não for 0/0/0 (condição de parada) e for considerada válida
		if(data.dia != 0 && data.mes != 0 && data.ano != 0  && invalida ){
		    // Calcula qual o dia da semana corresponde à data
		    Semana = DiaSemana(data.dia,data.mes,data.ano);
		    
            // Imprime a data formatada e o nome do dia da semana encontrado
            printf("%02d/%02d/%04d : %s \n", data.dia, data.mes, data.ano, resultados [Semana]);
		}
	// Repete o loop enquanto o usuário não digitar 0 0 0
	}while(data.dia != 0 && data.mes != 0 && data.ano != 0);
	return 0;
}

// Verifica se o ano está dentro do intervalo permitido (1 a 9999)
int ValidacaoAno(int ano){
    if( ano > 0  && ano < 10000)
        return 0; // Retorna 0 se for válido
    else
        return 1; // Retorna 1 se for inválido
}

// Verifica se o mês está entre 1 e 12
int ValidacaoMes(int mes){
    if(mes > 0 && mes < 13)
        return 0; // Retorna 0 se for válido
    else
        return 1; // Retorna 1 se for inválido
} 

// Verifica regras básicas para os dias (máximo 30 ou 31 dependendo do mês)
// Nota: Fevereiro é tratado parcialmente aqui e totalmente na função ValidacaoBissextos
int ValidacaoDia(int dia, int mes){
    // Se o dia for de 1 a 30, considera válido aqui (validação extra para fev acontece depois)
    if( dia <=30 && dia > 0){
            return 0;
    }else{ 
        // Se for dia 31, verifica se o mês não é um dos meses que têm apenas 30 dias
        if( dia <= 31 && dia > 0 && (mes != 4 && mes != 6 && mes != 9 && mes != 11))
            return 0;
    return 1; // Retorna 1 se o dia for inválido
    }
}

// Validação específica para Fevereiro, considerando anos bissextos
int ValidacaoBissextos(int dia,int ano){
       // Dias de 1 a 28 são sempre válidos em Fevereiro
       if(dia <= 28 && dia > 0)
        return 0;
    
    // Se for dia 29, verifica se o ano é bissexto
    if(dia == 29){
        // Regra: Divisível por 4, exceto centenários não divisíveis por 400
        if((ano % 4 == 0 && ano % 100 != 0) || (ano % 400 == 0))
            return 0; // Válido (ano bissexto)
        else
            return 1; // Inválido (dia 29 em ano comum)
    }
    
    return 1; // Inválido (dias maiores que 29 em Fevereiro)
}

// Validação histórica para o ano de 1582 (Início do calendário Gregoriano)
// Os dias de 5 a 14 de outubro de 1582 não existiram.
int ValidacaoExiste( int dia, int mes){
    if(mes == 10 && dia >= 5 && dia <= 14){
        return 1; // Retorna 1 (inválido) pois a data não existe
    }
    return 0; // Retorna 0 (válida)
}

// Função que calcula o dia da semana usando um algoritmo matemático (similar à Congruência de Zeller)
int DiaSemana(int dia, int mes, int ano){
    int  M, D, A, S;
    
    // Ajuste de mês e ano para o algoritmo: Janeiro e Fevereiro são tratados 
    // como meses 13 e 14 do ano anterior.
    if(mes <= 2){
        M = mes + 10;  
        ano--;         
    } else {
        M = mes - 2;  
    }
    
    D = dia;
    A = ano %100; // Ano dentro do século
    S = ano / 100; // Século
    
    // Cálculo da soma total para determinar o índice do dia
    int soma = (int)(2.6 * M - 0.1) + D + A + (A/4) + (S/4) - 2 * S;

     // O resto da divisão por 7 retorna o índice (0 a 6) para o array de dias da semana
     return soma % 7; 

}
