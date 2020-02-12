#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

#include "list.h"
#include "todolist.h"

int main(int argc, char const *argv[])
{
	char resposta;

	do{
		menuInicial();

		printf("Deseja continuar navegando pelo seu bloco de notas? S/N: ");
		scanf("%s", &resposta);
		printf("\n");
	}
	while(resposta == 's' || resposta == 'S');

	return 0;
}
