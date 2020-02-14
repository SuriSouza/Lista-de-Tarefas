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
	TListadeListas listaDeListas;
	TListadeListas *listaAux;
	
	FLVazia(&listaDeListas.lista);
	listaDeListas.prox = NULL;
	
	do{
		MenuInicial();
		scanf("%d", &opcao);

		switch (opcao) {
			case 1:
				criaLista(&listaDeListas);
			break;

			case 2:
				ImprimirListas(&listaDeListas);
			break;

			case 3:
				ImprimirListas(&listaDeListas);
				printf("\nDigite o nome da lista que deseja remover: ");
				__fpurge(stdin);
				fgets(nomeaux,20,stdin);
				listaAux = buscaListas(nomeaux, &listaDeListas);
				
				if (listaAux != NULL){
					if (listaDeListas.prox != NULL && strcmp(listaDeListas.prox->lista.nome, nomeaux) == 0)
						removerLista(&listaDeListas);
					else 
						removerLista(listaAux);
				}
				else printf(">>>>> NÃO ENCONTRADO <<<<<\n");
			break;

			case 4:
				ImprimirListas(&listaDeListas);
				printf("\nDigite o nome da lista que deseja modificar: ");
				__fpurge(stdin);
				fgets(nomeaux,20,stdin);
				listaAux = buscaListas(nomeaux, &listaDeListas);
				
				if (listaAux != NULL){
					if (listaDeListas.prox != NULL && strcmp(listaDeListas.prox->lista.nome, nomeaux) == 0)
						MenuOpcao04(&listaDeListas.prox->lista);
					else 
						MenuOpcao04(&listaAux->prox->lista);
				}
				else printf(">>>>> NÃO ENCONTRADO <<<<<\n");
			break;

			case 5:
				imprimirPorPeriodo(&listaDeListas);
			break;

			case 6:
				resposta = 'n';
			break;
		}
	}
	while(resposta == 's');

	return 0;
}
