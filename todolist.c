#include <stdlib.h>
#include <stdio.h>

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
	Lista *lista = (Lista*) malloc(sizeof(Lista));

	if(lista == NULL)
	{
		printf("\nFalha ao alocar memoria!\n");
	}

	printf("\nNome da lista: ");
	scanf("%s", &lista->nome);
	
	printf("%s\n", lista->nome);

	lista->prox = NULL;

	adicionarLista(lista->nome);
}


// Função que vai adicionar as Listas no arquivo
void adicionarLista(char nome[])
{
	Lista *lista = (Lista*) malloc(sizeof(Lista));

	if(lista == NULL)
	{
		printf("\nFalha ao alocar memoria!\n");
	}

	lista->nome = nome;
	lista->prox = NULL;

	atual->prox = lista;
	atual = lista;

	print(lista);
}
