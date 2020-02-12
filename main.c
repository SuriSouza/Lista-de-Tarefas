#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

#include "todolist.h"

int main(int argc, char const *argv[])
{
	char resposta;
	TLista lista01;

	do{
		menuInicial();
		FLVazia(&lista01);
		
		printf("Deseja continuar navegando pelo seu bloco de notas? S/N: ");
		scanf("%s", &resposta);
		printf("\n");
	}
	while(resposta == 's' || resposta == 'S');

	return 0;
}
