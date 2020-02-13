#include <stdlib.h>
#include <stdio_ext.h>
#include <stdbool.h>
#include <string.h>

#include "todolist.h"

// Primeira interação com o usuário: Menu Inicial
void MenuInicial()
{
	int opcao;

	printf("1 - Adicionar Lista de Tarefas\n");
	printf("2 - Imprimir nomes das listas\n");
	printf("3 - Remover Lista de Tarefas\n");
	printf("4 - Abrir Lista de Tarefas\n");
	printf("5 - Listar Tarefas de um Período\n");
	printf("6 - Sair\n\n");
}

//Responsavel por fazer uma lista vazia
void FLVazia(TLista* lista){
	lista->primeiro = (TCelula*) malloc(sizeof(TCelula));
	lista->ultimo = lista->primeiro;
	lista->primeiro->prox = NULL;
	lista->tam = 0;
}

//Responsavel por inserir um elemento na lista
void InserirLista(TLista *lista, TDado item){
	lista->ultimo->prox = (TCelula*)malloc(sizeof(TCelula));
	lista->ultimo = lista->ultimo->prox;
	lista->ultimo->prox = NULL;
	lista->ultimo->item = item;
	lista->tam++;
}

//Responsavel por pesquisar um elemento na lista
TCelula* PesquisarLista(TLista lista, int posicao)
{
	TCelula* aux = lista.primeiro;
	if (posicao >= 0 && posicao < lista.tam){
		while (aux->prox != NULL)
		{
			while (posicao !=0 && aux->prox != NULL){
				aux = aux->prox;
				posicao--;
			}
			return aux;
		}
	}
	printf(">>>>> POSICAO INVALIDA <<<<<\n");
	return NULL;
}

//Responsavel por excluir um elemento da lista (nao utilizei)
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
	printf("\nDigite o dia:  ");
	__fpurge(stdin);
	scanf("%d", &dado->data.dia);
	printf("\nDigite o mes (numero):  ");
	__fpurge(stdin);
	scanf("%d", &dado->data.mes);
	printf("\nDigite o ano:  ");
	__fpurge(stdin);
	scanf("%d", &dado->data.ano);

}

void ImprimirTarefas(TLista *lista){
	int posicao = 1;
	TCelula* aux = lista->primeiro;
	while (aux->prox != NULL){
		printf("\tID tarefa: [%d] --->\t", posicao);
		posicao++;
		printf("%s", aux->prox->item.descricao);
		printf("%s\t\t Data: [ %d / %d / %d ]\n\n", aux->prox->item.estado ? "\t[FEITA]" : "\t[NAO FEITA]", aux->prox->item.data.dia, aux->prox->item.data.mes, aux->prox->item.data.ano);
		aux = aux->prox;
	}
}

void ImprimirTarefa(TLista *lista, int posicao){
	TCelula* endereco = PesquisarLista(*lista, posicao);
	if (endereco != NULL){
		printf("\tID tarefa: [%d] --->\t%s\n", posicao, endereco->item.descricao);
		printf("%s\t\t Data: [ %d / %d / %d ]\n\n", endereco->item.estado ? "\t[NAO FEITA]" : "\t[FEITA]", endereco->prox->item.data.dia, endereco->prox->item.data.mes, endereco->prox->item.data.ano);
	}
}

void alterarEstadoPFeita(TLista *lista, int posicao){
	TCelula* endereco = PesquisarLista(*lista, posicao);
	if (endereco != NULL)
	endereco->item.estado = true;
}

void alterarEstadoPNaoFeita(TLista *lista, int posicao){
	TCelula* endereco = PesquisarLista(*lista, posicao);
	if (endereco != NULL)
	endereco->item.estado = false;
}

void ImprimeElemento(TDado item){
	// printf("\tID tarefa: [%d] --->\t", posicao);
	// posicao++;
	printf("\tID tarefa: [] --->\t");
	printf("%s", item.descricao);
	printf("%s\t\t Data: [ %d / %d / %d ]\n\n", item.estado ? "\t[FEITA]" : "\t[NAO FEITA]", item.data.dia, item.data.mes, item.data.ano);
}

void imprimirPorPeriodo(TListadeListas *listaDeListas){
	int posicao = 1;
	int sinaliza01;
	int sinaliza02;
	TData dataAuxInferior, dataAuxSuperior;
	TListadeListas *listaDeListasAuxiliar = listaDeListas;

	printf("Primeiramente, a data que sera o limite inferior (data inicial de busca):\n");
	printf("\nDigite o dia:  ");
	__fpurge(stdin);
	scanf("%d", &dataAuxInferior.dia);
	printf("\nDigite o mes (numero):  ");
	__fpurge(stdin);
	scanf("%d", &dataAuxInferior.mes);
	printf("\nDigite o ano:  ");
	__fpurge(stdin);
	scanf("%d", &dataAuxInferior.ano);

	printf("Agora, a data que sera o limite superior (data final de busca):\n");
	printf("\nDigite o dia:  ");
	__fpurge(stdin);
	scanf("%d", &dataAuxSuperior.dia);
	printf("\nDigite o mes (numero):  ");
	__fpurge(stdin);
	scanf("%d", &dataAuxSuperior.mes);
	printf("\nDigite o ano:  ");
	__fpurge(stdin);
	scanf("%d", &dataAuxSuperior.ano);

	while(listaDeListasAuxiliar->prox != NULL){
		TCelula* aux = listaDeListasAuxiliar->prox->lista.primeiro;
		while (aux->prox != NULL){
			sinaliza01 = 0;
			sinaliza02 = 0;
			if (aux->prox->item.data.ano >= dataAuxInferior.ano){
				if (aux->prox->item.data.mes >= dataAuxInferior.mes){
					if (aux->prox->item.data.dia >= dataAuxInferior.dia){
						sinaliza01 = 1;
					}
				}
			}
			if (aux->prox->item.data.ano <= dataAuxSuperior.ano){
				if (aux->prox->item.data.mes <= dataAuxSuperior.mes){
					if (aux->prox->item.data.dia <= dataAuxSuperior.dia){
						sinaliza02 = 1;
					}
				}
			}
			if (sinaliza01 == 1 && sinaliza02 == 1)
				ImprimeElemento(aux->prox->item);
			aux = aux->prox;
		}
		listaDeListasAuxiliar = listaDeListasAuxiliar->prox;
	}

}

void MenuOpcao03(TLista *lista){
	int opcao, id, posicaoAtual, posicaoDesejada;
	TDado dado;

	printf("1 - Adicionar Tarefas\n");
	printf("2 - Imprimir tarefas\n");
	printf("3 - Remover Tarefas\n");
	printf("4 - Marcar como 'FEITA'\n");
	printf("5 - Marcar como 'NAO FEITA'\n");
	printf("6 - Mudar prioridade de item\n");

	scanf("%d", &opcao);

	switch (opcao) {
		case 1:
		LerDados(&dado);
		InserirLista(lista, dado);
		break;
		case 2:
		ImprimirTarefas(lista);
		break;
		case 3:
		ImprimirTarefas(lista);
		printf("Digite o ID da tarefa que deseja remover:");
		__fpurge(stdin);
		scanf("%d", &id);
		ExcluirLista(lista, id);
		break;
		case 4:
		ImprimirTarefas(lista);
		printf("Digite o ID da tarefa que deseja marcar como 'FEITA':");
		__fpurge(stdin);
		scanf("%d", &id);
		alterarEstadoPFeita(lista, id);
		break;
		case 5:
		ImprimirTarefas(lista);
		printf("Digite o ID da tarefa que deseja marcar como 'NAO FEITA':");
		__fpurge(stdin);
		scanf("%d", &id);
		alterarEstadoPNaoFeita(lista, id);
		break;
		case 6:
		ImprimirTarefas(lista);
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

void criaLista(TListadeListas* listaDeListas){
	TListadeListas* listadl = (TListadeListas*)malloc(sizeof(TListadeListas));
	FLVazia(&listadl->lista);
	printf("Digite o nome da lista:  ");
	__fpurge(stdin);
	fgets(listadl->lista.nome,20,stdin);
	listadl -> prox = listaDeListas -> prox;
	listaDeListas -> prox = listadl;
}

void ImprimirListas (TListadeListas* listaDeListas){
	int posicao = 1;
	TListadeListas* ldlaux = listaDeListas;
	while (ldlaux->prox != NULL){
		printf("\tlista [%d] : --->\t", posicao);
		printf("%s", ldlaux->prox->lista.nome);
		ldlaux = ldlaux->prox;
		posicao++;
	}
}

TListadeListas *buscaListas (char nome[], TListadeListas* listaDeListas){
	TListadeListas* listadl = listaDeListas;
	while(listadl->prox != NULL){
		if (strcmp(listadl->prox->lista.nome, nome)==0)	return listadl;
		listadl = listadl->prox;
	}
	return NULL;
}

void removerLista(TListadeListas* listaDeListas){
	TListadeListas* aux = listaDeListas->prox;
	listaDeListas->prox = listaDeListas->prox->prox;
	free(aux);
}
