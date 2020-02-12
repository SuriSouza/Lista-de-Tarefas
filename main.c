#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

#include "todolist.h"

int main(int argc, char const *argv[])
{
	char resposta;
	TLista lista01;
	TDado dado01;

	scanf("%s", dado01.descricao);

	do{
		//menuInicial();
		FLVazia(&lista01);
		InserirLista(&lista01, dado01);
		printf("Deseja continuar navegando pelo seu bloco de notas? S/N: ");
		scanf("%s", &resposta);
		printf("teste\n");
		printf("%s\n", lista01.primeiro->prox->item.descricao);
		printf("\n");
	}
	while(resposta == 's' || resposta == 'S');

	return 0;
}
