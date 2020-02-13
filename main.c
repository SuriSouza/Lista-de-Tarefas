#include <stdlib.h>
#include <stdio_ext.h>
#include <stdbool.h>
#include <string.h>
#include "todolist.h"

int main(int argc, char const *argv[])
{
	char resposta = 's';
	char nomeaux[20];
	int opcao;
	TListadeListas *listaDeListas;
	TListadeListas *listaAux;
	listaDeListas->prox = NULL;
	do{
		MenuInicial();
		scanf("%d", &opcao);

		switch (opcao) {
			case 1:
			criaLista(listaDeListas);
				break;

			case 2:
				ImprimirListas(listaDeListas);
			break;

			case 3:
				printf("Digite o nome da lista que deseja remover: \n");
				__fpurge(stdin);
				fgets(nomeaux,20,stdin);
				listaAux = buscaListas(nomeaux, listaDeListas);
					if (listaAux != NULL){
					if (listaDeListas->prox != NULL && strcmp(listaDeListas->prox->lista.nome, nomeaux) == 0)
					removerLista(listaDeListas);
					else removerLista(listaAux);
				}
				else printf(">>>>> NÃO ENCONTRADO <<<<<\n");
			break;

			case 6:
				resposta = 'n';
			break;
		}
	}
	while(resposta == 's');

	return 0;
}
