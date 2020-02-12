#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

#include "todolist.h"

// Primeira interação com o usuário: Menu Inicial

void lerDados(TDado *dado){
	printf("Adicione uma descricao de ate 50 caracteres:\n");
	__fpurge(stdin);
	fgets(dado->descricao, 50, stdin);
}

void imprimirTarefas(TLista lista){
  TCelula* aux = lista.primeiro;
  while (aux->prox != NULL){
    printf("%s\n", aux->prox->item.descricao);
    aux = aux->prox;
  }
}

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

void menuInicial()
{
	int opcao;

	printf("1 - Adicionar Lista de Tarefas\n");
	printf("2 - Remover Lista de Tarefas\n");
	printf("3 - Abrir Lista de Tarefas\n");
	printf("4 - Listar Tarefas de um Período\n");
	printf("5 - Sair\n\n");
}

void menuOpcao03(TLista *lista, TDado *dado){
	int opcao;

	printf("1 - Adicionar Tarefas\n");
	printf("2 - Imprimir tarefas\n");
	printf("3 - Remover Tarefas\n");
	printf("4 - Marcar como 'FEITA'\n");
	printf("5 - Marcar como 'NAO FEITA'\n");
	printf("6 - Mudar prioridade de item\n");
	printf("7 - Voltar ao menu anterior\n");

	scanf("%d", &opcao);

	switch (opcao) {
		case 1:
		lerDados(dado);
		InserirLista(lista, *dado);
		break;
		case 2:
		imprimirTarefas(*lista);
	}
}
