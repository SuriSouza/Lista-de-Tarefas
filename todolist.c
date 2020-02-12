#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

#include "todolist.h"

// Primeira interação com o usuário: Menu Inicial
/*void menuInicial()
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
*/
/*
// void criarLista()
// {
// 	Tarefas *lista = (Tarefas*) malloc(sizeof(Tarefas));
//
// 	if(lista == NULL)
// 	{
// 		printf("\nFalha ao alocar memoria!\n");
// 	}
//
// 	printf("\nNome da lista: ");
// 	scanf("%s", lista->nome);
//
// 	fflush(stdin);
// 	printf("Descricao da lista: ");
// 	for (int i = 0; lista->descricao[i] != '\0'; ++i)
// 	{
// 		scanf("%c", &lista->descricao[i]);
// 	}
//
//
// 	adicionarLista(lista->nome);
// }
//
//
// // Função que vai adicionar as Listas no arquivo
// void adicionarLista(char nome[])
// {
// 	Tarefas *lista = (Tarefas*) malloc(sizeof(Tarefas));
//
// 	if(lista == NULL)
// 	{
// 		printf("\nFalha ao alocar memoria!\n");
// 	}
//
// }
*/

void FLVazia(TLista* lista){
  lista->primeiro = (TCelula*) malloc(sizeof(TCelula));
  lista->ultimo = lista->primeiro;
  lista->primeiro->prox = NULL;
  lista->tam = 0;
}

void InserirLista(TLista *lista, TDado item){
  lista->ultimo->prox = (TCelula*)malloc(sizeof(TCelula));
  lista->ultimo = lista->ultimo->prox;
  lista->ultimo->prox = NULL;
  lista->ultimo->item = item;
  lista->tam++;
}

/*TCelula* PesquisarLista(TLista lista, TDado item){
  TCelula* aux = lista.primeiro;
  while (aux->prox != NULL){
    if(aux->prox->item.id == item.id) return aux;
    else aux = aux->prox;
  }
  return NULL;
}*/

/*void ExcluirLista(TLista *lista, TDado item){
  TCelula* endereco = PesquisarLista(*(lista), item);
  if(endereco != NULL){
    TCelula* aux;
    aux = endereco->prox->prox;
    free(endereco->prox);
    endereco->prox = aux;
    lista->tam--;

    if(endereco->prox == NULL)
    lista->ultimo = endereco;
  }
}
*/
