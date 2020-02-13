
typedef struct tdata{
  int dia;
  int mes;
  int ano;
} TData;

typedef struct Dado
{
	char descricao[50];
	TData data;
	bool estado;
}TDado;

typedef struct celula {
  TDado item;
  struct celula* prox;
} TCelula;

typedef struct lista {
	char nome[20];
  TCelula* primeiro;
  TCelula* ultimo;
  int tam;
} TLista;

typedef struct listaDeListas {
  TLista lista;
  struct listaDeListas* prox;
} TListadeListas;

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
void MenuOpcao03(TLista *lista);
void criaLista(TListadeListas* listaDeListas);
void ImprimirListas (TListadeListas* listaDeListas);
TListadeListas *buscaListas (char nome[], TListadeListas* listaDeListas);
void removerLista(TListadeListas* listaDeListas);
