#include <stdlib.h>
#include <stdio_ext.h>
#include <stdbool.h>

#include "todolist.h"

int main(int argc, char const *argv[])
{
	char resposta = 's';
	int opcao;
	TLista lista01;
	TDado dado01;

	do{
		MenuInicial();
		scanf("%d", &opcao);

		switch (opcao) {
			case 1:
				FLVazia(&lista01);
				printf("Dê um nome para sua lista de tarefas:\n");
				scanf("%s", &lista01.nome);
				InserirLista(&lista01, dado01);
			break;

			case 2:
				//ImprimirLista(lista01, dado01);
				//ExcluirLista(&lista01, dado01);
			break;

			case 3:
				MenuOpcao03(&lista01, &dado01);
			break;

			case 5:
				resposta = 'n';
			break;
		}
	}
	while(resposta == 's');

	return 0;
}
