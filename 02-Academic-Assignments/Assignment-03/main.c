
#include "Q1-lista.h"

int main(void) {
    TLista lista;
    char operacao;
    char nomeProduto[26]; 
    float quantidade;
    char sentido;

    InicializaLista(&lista);

    while(operacao != '*') {
		scanf(" %c", &operacao);

		if(operacao != '*') {
			scanf("%24s", nomeProduto);
			if(operacao == 'I')
				scanf("%f", &quantidade);
		}
		switch(operacao) {

		case 'I':
			if (IncluiItem(&lista, nomeProduto, quantidade))
			    printf("Incluiu %s \n", nomeProduto);
			quantidade = 0;
			break;
		case 'P':
			if(strcmp("R", nomeProduto))
				ImprimeListaReversa(&lista);
			else if(strcmp("F", nomeProduto))
				ImprimeListaInicio(&lista);
			break;
		case 'A':
			if(AtualizacaoItem(&lista, nomeProduto))
				printf("Comprou %s \n", nomeProduto);
			break;
		case 'X':
			if (ExcluiItem(&lista, nomeProduto))
				printf("Excluiu %s\n", nomeProduto);
			break;
		case '*':
			printf("Fim do programa ( %d itens sem comprar)\n", lista.qtde - lista.comprado);
			break;
		default:
			printf("Operacao invalida.\n");
		}
	}
	return EXEC_SUCCESS;
}
