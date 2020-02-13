
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

void MenuInicial();
void FLVazia(TLista* lista);
void InserirLista(TLista *lista, TDado item);
void ImprimirLista(TLista lista, TDado item);
TCelula* PesquisarLista(TLista lista, int posicao);
void ExcluirLista(TLista *lista, int posicao);
void MenuOpcao03(TLista *lista, TDado *dado);
