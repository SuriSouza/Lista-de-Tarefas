#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

#include "todolist.h"

// Primeira interação com o usuário: Menu Inicial
void menuInicial()
{
	int opcao;

	printf("1 - Adicionar Lista de Tarefas\n");
	printf("2 - Remover Lista de Tarefas\n");
	printf("3 - Abrir Lista de Tarefas\n");
	printf("4 - Listar Tarefas de um Período\n\n");
	scanf("%d", &opcao);

	if (opcao == 1)
	{
		criarLista();
	}
	
	else
	{
		printf("Opcao inválida!\n");
	}
}


void criarLista()
{
	Tarefas *lista = (Tarefas*) malloc(sizeof(Tarefas));

	if(lista == NULL)
	{
		printf("\nFalha ao alocar memoria!\n");
	}

	printf("\nNome da lista: ");
	scanf("%s", lista->nome);

	fflush(stdin);
	printf("Descricao da lista: ");
	for (int i = 0; lista->descricao[i] != '\0'; ++i)
	{
		scanf("%c", &lista->descricao[i]);	
	}
	

	adicionarLista(lista->nome);
}


// Função que vai adicionar as Listas no arquivo
void adicionarLista(char nome[])
{
	Tarefas *lista = (Tarefas*) malloc(sizeof(Tarefas));

	if(lista == NULL)
	{
		printf("\nFalha ao alocar memoria!\n");
	}

}
