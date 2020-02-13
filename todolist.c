#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#include "todolist.h"

// Primeira interação com o usuário: Menu Inicial

void MenuInicial()
{
	int opcao;

	printf("1 - Adicionar Lista de Tarefas\n");
	printf("2 - Remover Lista de Tarefas\n");
	printf("3 - Abrir Lista de Tarefas\n");
	printf("4 - Listar Tarefas de um Período\n");
	printf("5 - Sair\n\n");
}


void FLVazia(TLista* lista)
{
  lista->primeiro = (TCelula*) malloc(sizeof(TCelula));
  lista->ultimo = lista->primeiro;
  lista->primeiro->prox = NULL;
  lista->tam = 0;
}

void InserirLista(TLista *lista, TDado item)
{
  lista->ultimo->prox = (TCelula*)malloc(sizeof(TCelula));
  lista->ultimo = lista->ultimo->prox;
  lista->ultimo->prox = NULL;
  lista->ultimo->item = item;
  lista->tam++;
}

/*void ImprimirLista(TLista lista, TDado item)
{
  printf("%s\n", lista.nome);
}*/

TCelula* PesquisarLista(TLista lista, int posicao)
{
  TCelula* aux = lista.primeiro;
	if (posicao >= 0 && posicao < lista.tam){
  while (aux->prox != NULL)
  {
		while (posicao !=-1 && aux->prox != NULL){
    		aux = aux->prox;
				posicao--;
			}
			return aux;
		}
	}
	printf(">>>>> POSICAO INVALIDA <<<<<\n");
  return NULL;
}

void ExcluirLista(TLista *lista, int posicao)
{
	posicao--;
  TCelula* endereco = PesquisarLista(*lista, posicao);
  if(endereco != NULL)
  {
    TCelula* aux;
    aux = endereco->prox->prox;
    free(endereco->prox);
    endereco->prox = aux;
    lista->tam--;

    if(endereco->prox == NULL)
    lista->ultimo = endereco;
  }
}

void alterarPrioridade(TLista *lista, int posicaoAtual, int posicaoDesejada)
{
	posicaoAtual--;
	posicaoDesejada--;
  TCelula* enderecoAtual = PesquisarLista(*lista, posicaoAtual);
	TCelula* enderecoDesejado = PesquisarLista(*lista, posicaoDesejada);
  if(enderecoAtual != NULL && posicaoDesejada > 0 && posicaoDesejada < lista->tam)
  {
    TCelula* aux;
		TCelula* aux2;
		TCelula* aux3;
    aux = enderecoAtual->prox->prox;
		aux3 = enderecoAtual->prox;
    enderecoAtual->prox = aux;
		aux2 = enderecoDesejado->prox;
		enderecoDesejado->prox = aux3;
		enderecoDesejado->prox->prox = aux2;

    if(enderecoAtual->prox == NULL)
    lista->ultimo = enderecoAtual;
  }
}

void LerDados(TDado *dado)
{
	printf("Adicione uma descricao de ate 50 caracteres:\n");
	__fpurge(stdin);
	fgets(dado->descricao, 50, stdin);
}

void ImprimirTarefas(TLista lista){
	int posicao = 1;
  TCelula* aux = lista.primeiro->prox;
  while (aux->prox != NULL){
		printf("\tID tarefa: [%d] --->\t", posicao);
		posicao++;
    printf("%s", aux->prox->item.descricao);
		printf("%s\n\n", aux->prox->item.estado ? "\t[NAO FEITA]" : "\t[FEITA]");
    aux = aux->prox;
  }
}

void ImprimirTarefa(TLista *lista, int posicao){
	TCelula* endereco = PesquisarLista(*lista, posicao);
	if (endereco != NULL){
		printf("\tID tarefa: [%d] --->\t%s\n", posicao, endereco->item.descricao);
		printf("%s\n\n", endereco->item.estado ? "\t[NAO FEITA]" : "\t[FEITA]");
	}
}

void alterarEstadoPFeita(TLista *lista, int posicao){
	TCelula* endereco = PesquisarLista(*lista, posicao);
	if (endereco != NULL)
		endereco->item.estado = false;
}

void alterarEstadoPNaoFeita(TLista *lista, int posicao){
	TCelula* endereco = PesquisarLista(*lista, posicao);
	if (endereco != NULL)
		endereco->item.estado = true;
}

void MenuOpcao03(TLista *lista, TDado *dado){
	int opcao, id, posicaoAtual, posicaoDesejada;

	printf("1 - Adicionar Tarefas\n");
	printf("2 - Imprimir tarefas\n");
	printf("3 - Remover Tarefas\n");
	printf("4 - Marcar como 'FEITA'\n");
	printf("5 - Marcar como 'NAO FEITA'\n");
	printf("6 - Mudar prioridade de item\n");

	scanf("%d", &opcao);

	switch (opcao) {
		case 1:
		  LerDados(dado);
		  InserirLista(lista, *dado);
		break;
		case 2:
		  ImprimirTarefas(*lista);
		break;
		case 3:
			ImprimirTarefas(*lista);
			printf("Digite o ID da tarefa que deseja remover:");
			__fpurge(stdin);
			scanf("%d", &id);
			ExcluirLista(lista, id);
			break;
		case 4:
			ImprimirTarefas(*lista);
			printf("Digite o ID da tarefa que deseja marcar como 'FEITA':");
			__fpurge(stdin);
			scanf("%d", &id);
			alterarEstadoPFeita(lista, id);
			break;
		case 5:
			ImprimirTarefas(*lista);
			printf("Digite o ID da tarefa que deseja marcar como 'NAO FEITA':");
			__fpurge(stdin);
			scanf("%d", &id);
			alterarEstadoPNaoFeita(lista, id);
			break;
		case 6:
			ImprimirTarefas(*lista);
			printf("Digite a tarefa em que deseja mudar de prioridade:  \n");
			__fpurge(stdin);
			scanf("%d", &posicaoAtual);
			printf("Digite a posicao desejada:  \n");
			__fpurge(stdin);
			scanf("%d", &posicaoDesejada);
			alterarPrioridade(lista, posicaoAtual, posicaoDesejada);
			break;
			default:
				printf(">>>>> OPCAO INVALIDA <<<<<\n");
	}
}
