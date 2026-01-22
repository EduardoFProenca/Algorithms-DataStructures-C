/*
 * Este programa realiza o controle financeiro da produção de uma fábrica.
 * O objetivo é calcular o Custo Total e o Lucro Total mensais baseando-se na
 * quantidade de peças produzidas e nos valores unitários de custo e lucro.
 *
 * ESTRUTURA DE DADOS:
 * 1. Matriz `PartMonthProduction` (3x3):
 *    - Linhas representam os Meses (1, 2, 3).
 *    - Colunas representam as Peças (P1, P2, P3).
 *    - Armazena a quantidade produzida de cada peça em cada mês.
 *
 * 2. Matriz `PartFinancials` (3x2):
 *    - Linhas representam as Peças (P1, P2, P3).
 *    - Colunas representam: [0] = Custo Unitário, [1] = Lucro Unitário.
 *
 * 3. Matriz `MonthFinancials` (3x2):
 *    - Linhas representam os Meses.
 *    - Colunas representam: [0] = Custo Total do Mês, [1] = Lucro Total do Mês.
 *    - Inicializada com zero para acumular os somatórios.
 *
 * LÓGICA DE CÁLCULO:
 * Para cada mês, o programa itera sobre as 3 peças. O cálculo é:
 * Total Custo do Mês += (Qtd Produzida * Custo Unitário da Peça)
 * Total Lucro do Mês += (Qtd Produzida * Lucro Unitário da Peça)
 */

#include <stdio.h>

int main()
{
    // Matriz para armazenar a produção de 3 peças ao longo de 3 meses
    double PartMonthProduction[3][3];
    
    // Matriz para armazenar o Custo (coluna 0) e Lucro (coluna 1) de cada peça
    double PartFinancials[3][2];
    
    // Matriz para armazenar o resultado acumulado: Custo Total e Lucro Total por mês
    // A sintaxe {{0}} garante que todos os elementos sejam inicializados em 0.0
    double MonthFinancials[3][2] = {{0}}; 

    // --- BLOCO 1: Entrada da Produção ---
    for(int month = 0; month < 3; month++){
        printf("\nProdução das peças do próximo mês %i.\n", month + 1);
        for(int part = 0; part < 3; part++){
            printf("  P%i :", part + 1);
            // Lê a quantidade produzida da peça 'part' no mês 'month'
            scanf("%lf", &PartMonthProduction[month][part]);
        }
    }

    // --- BLOCO 2: Entrada dos Dados Financeiros (Custo e Lucro por peça) ---
    printf("\nCusto e lucro\n");
    for(int part = 0; part < 3; part++){
        for(int type = 0; type < 2; type++){
            // O prompt repete o ID da peça para custo e depois para lucro (ex: P1, P1)
            printf("P%i ", part + 1);
            // Lê o custo (type 0) e o lucro (type 1) da peça 'part'
            scanf("%lf", &PartFinancials[part][type]);
        }
    }
    
    // --- BLOCO 3: Cálculo dos Totais Mensais ---
    for(int month = 0; month < 3; month++) {
        for(int part = 0; part < 3; part++){
            // Acumula o custo: Quantidade * Custo Unitário
            MonthFinancials[month][0] += PartMonthProduction[month][part] * PartFinancials[part][0];
            
            // Acumula o lucro: Quantidade * Lucro Unitário
            MonthFinancials[month][1] += PartMonthProduction[month][part] * PartFinancials[part][1];
        }
    }
    
    // --- BLOCO 4: Exibição dos Resultados ---
    printf("\n        CUSTO    LUCRO");
    for(int month = 0; month < 3; month++){
        printf("\nMês%i |", month + 1);
        for(int col = 0; col < 2; col++){
            // Imprime o valor formatado com 2 casas decimais
            printf("  %.2f  ", MonthFinancials[month][col]);
        }
    }
    
    return 0;
}