/*
 * 
 * Este programa atua como um validador e calculador avançado de datas. Ele recebe
 * uma data do usuário, verifica se ela é válida de acordo com as regras do
 * Calendário Gregoriano e, se válida, calcula em qual dia da semana a data cai.
 *
 * 1. REGRAS DE VALIDAÇÃO:
 *    - Ano: Deve ser maior que 0 e menor que 10000.
 *    - Mês: Deve estar entre 1 e 12.
 *    - Dia: Deve respeitar o número de dias de cada mês (30 ou 31).
 *    - Fevereiro (Ano Bissexto): Fevereiro tem regra especial.
 *      O ano é bissexto se for divisível por 4, exceto centenários não divisíveis por 400.
 *      Se for bissexto, Fevereiro tem 29 dias; caso contrário, 28.
 *
 * 2. EXCEÇÃO HISTÓRICA (Ano de 1582):
 *    - O programa valida a transição do Calendário Juliano para o Gregoriano.
 *    - Em 1582, o Papa Gregório XIII decretou que os dias 5 a 14 de outubro
 *      não existiriam (para corrigir o atraso acumulado). O programa rejeita
 *      essas datas específicas.
 *
 * 3. CÁLCULO DO DIA DA SEMANA:
 *    - Utiliza uma variação do Algoritmo da Congruência de Zeller.
 *    - Ajusta os meses de Janeiro e Fevereiro para serem tratados como
 *      meses 13 e 14 do ano anterior para fins de cálculo.
 *    - Retorna um índice (0 a 6) que corresponde aos dias da semana (Domingo a Sábado).
 *
 * 4. CONDIÇÃO DE PARADA:
 *    - O loop encerra quando o usuário digita 0 0 0.
 * 
 */

#include <stdio.h>
#include <stdbool.h>

// Protótipos das funções utilizadas no programa
int ValidateYear(int year);
int ValidateMonth(int month);  
int ValidateDay(int day, int month);
int ValidateLeapYear(int day, int year);
int ValidateDateExists(int day, int month);
int CalculateDayOfWeek(int day, int month, int year);

int main()
{
    // Definição da estrutura 'DateReg' para armazenar dia, mês e ano
    // Criação do tipo 'TDate' para facilitar o uso da estrutura
    struct DateReg { int day, month, year; }; 
    typedef struct DateReg TDate; 
    
    TDate date;
    
    // Variáveis para armazenar o resultado das validações (0 = válido, 1 = inválido)
    int invalidYear, invalidMonth, invalidDay, invalidLeapYear, invalidDateExists;
    int weekDayIndex;
    bool isValid;
    
    // Array de strings com os dias da semana para impressão formatada
    char weekDays[7][15] = {
        "Domingo", "Segunda-Feira", "Terça-Feira", "Quarta-Feira", 
        "Quinta-Feira", "Sexta-Feira", "Sábado"
    }; 
    
    do{
        // Solicita a entrada da data ao usuário
        printf(" Data: ");
        scanf("%d %d %d", &date.day, &date.month, &date.year);
        
        // Executa as validações específicas para cada campo da data
        invalidYear = ValidateYear(date.year);
        invalidMonth = ValidateMonth(date.month); 
        invalidDay = ValidateDay(date.day, date.month);
        
        // Validação condicional: Se o mês for Fevereiro (2), checa regra de ano bissexto
        invalidLeapYear = (2 == date.month) ? ValidateLeapYear(date.day, date.year) : 0;
        
        // Validação condicional: Se o ano for 1582, checa a data histórica da transição do calendário
        invalidDateExists = (1582 == date.year) ? ValidateDateExists(date.day, date.month) : 0;
        
        // Verifica se a data é geralmente válida (soma das validações deve ser 0)
        isValid = (invalidYear + invalidMonth + invalidDay + invalidLeapYear + invalidDateExists) == 0 ? true : false;
    
        // Se a data não for 0/0/0 (condição de parada) e for considerada válida
        if(date.day != 0 && date.month != 0 && date.year != 0 && isValid){
            // Calcula qual o dia da semana corresponde à data
            weekDayIndex = CalculateDayOfWeek(date.day, date.month, date.year);
            
            // Imprime a data formatada e o nome do dia da semana encontrado
            printf("%02d/%02d/%04d : %s \n", date.day, date.month, date.year, weekDays[weekDayIndex]);
        }
    // Repete o loop enquanto o usuário não digitar 0 0 0
    } while(date.day != 0 && date.month != 0 && date.year != 0);
    
    return 0;
}

// Verifica se o ano está dentro do intervalo permitido (1 a 9999)
int ValidateYear(int year){
    if(year > 0 && year < 10000)
        return 0; // Retorna 0 se for válido
    else
        return 1; // Retorna 1 se for inválido
}

// Verifica se o mês está entre 1 e 12
int ValidateMonth(int month){
    if(month > 0 && month < 13)
        return 0; // Retorna 0 se for válido
    else
        return 1; // Retorna 1 se for inválido
} 

// Verifica regras básicas para os dias (máximo 30 ou 31 dependendo do mês)
// Nota: Fevereiro é tratado parcialmente aqui e totalmente na função ValidateLeapYear
int ValidateDay(int day, int month){
    // Se o dia for de 1 a 30, considera válido aqui (validação extra para fev acontece depois)
    if(day <= 30 && day > 0){
        return 0;
    } else { 
        // Se for dia 31, verifica se o mês não é um dos meses que têm apenas 30 dias
        // Meses com 30 dias: Abril(4), Junho(6), Setembro(9), Novembro(11)
        if(day <= 31 && day > 0 && (month != 4 && month != 6 && month != 9 && month != 11))
            return 0;
    return 1; // Retorna 1 se o dia for inválido
    }
}

// Validação específica para Fevereiro, considerando anos bissextos
int ValidateLeapYear(int day, int year){
    // Dias de 1 a 28 são sempre válidos em Fevereiro
    if(day <= 28 && day > 0)
        return 0;
    
    // Se for dia 29, verifica se o ano é bissexto
    if(day == 29){
        // Regra: Divisível por 4, exceto centenários não divisíveis por 400
        if((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
            return 0; // Válido (ano bissexto)
        else
            return 1; // Inválido (dia 29 em ano comum)
    }
    
    return 1; // Inválido (dias maiores que 29 em Fevereiro)
}

// Validação histórica para o ano de 1582 (Início do calendário Gregoriano)
// Os dias de 5 a 14 de outubro de 1582 não existiram.
int ValidateDateExists(int day, int month){
    if(month == 10 && day >= 5 && day <= 14){
        return 1; // Retorna 1 (inválido) pois a data não existe
    }
    return 0; // Retorna 0 (válida)
}

// Função que calcula o dia da semana usando um algoritmo matemático (similar à Congruência de Zeller)
int CalculateDayOfWeek(int day, int month, int year){
    int M, D, A, S;
    
    // Ajuste de mês e ano para o algoritmo: Janeiro e Fevereiro são tratados 
    // como meses 13 e 14 do ano anterior.
    if(month <= 2){
        M = month + 10;  
        year--;         
    } else {
        M = month - 2;  
    }
    
    D = day;
    A = year % 100; // Ano dentro do século
    S = year / 100; // Século
    
    // Cálculo da soma total para determinar o índice do dia
    int sum = (int)(2.6 * M - 0.1) + D + A + (A/4) + (S/4) - 2 * S;

    // O resto da divisão por 7 retorna o índice (0 a 6) para o array de dias da semana
    return sum % 7; 
}