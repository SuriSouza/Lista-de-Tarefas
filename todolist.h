/*
 * Arquivo header responsável pela declaração de todas
 * as estruturas e funções do software
 */ 

// Estrutura do tipo TData que contém as datas das tarefas
typedef struct tdata{
  int dia;
  int mes;
  int ano;
} TData;

// Estrutura do tipo TDado que contém as informações de cada tarefa
typedef struct Dado
{
	char descricao[50];
	TData data;
	bool estado;
}TDado;

// Estrutura do tipo TCelula que contém tarefas e aponta para suas posições 
typedef struct celula {
  TDado item;
  struct celula* prox;
} TCelula;

// Estrutura que contém as informações de cada lista de tarefas
typedef struct lista {
	char nome[20];
  TCelula* primeiro;
  TCelula* ultimo;
  int tam;
} TLista;

// Estrutura que contém a lista de listas
typedef struct listaDeListas {
  TLista lista;
  struct listaDeListas* prox;
} TListadeListas;

/* 
 * Todas as funções que são executadas no software
 * Mais detalhadas no arquivo .c
 */

void MenuInicial();
void FLVazia(TLista* lista);
void InserirLista(TLista *lista, TDado item);
TCelula* PesquisarLista(TLista lista, int posicao);
void ExcluirLista(TLista *lista, int posicao);
void alterarPrioridade(TLista *lista, int posicaoAtual, int posicaoDesejada);
void LerDados(TDado *dado);
void ImprimirTarefas(TLista *lista);
void ImprimirTarefa(TLista *lista, int posicao);
void alterarEstadoPFeita(TLista *lista, int posicao);
void alterarEstadoPNaoFeita(TLista *lista, int posicao);
void ImprimeElemento(TDado item);
void imprimirPorPeriodo(TListadeListas *listaDeListas);
void MenuOpcao04(TLista *lista);
void criaLista(TListadeListas* listaDeListas);
void ImprimirListas (TListadeListas* listaDeListas);
TListadeListas *buscaListas (char nome[], TListadeListas* listaDeListas);
void removerLista(TListadeListas* listaDeListas);