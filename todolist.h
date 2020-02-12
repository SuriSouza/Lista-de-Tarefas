
typedef struct tdata{
  int dia;
  int mes;
  int ano;
} TData;

typedef struct Tarefas
{
	char descricao[50];
	TData data;
	bool estado;
}Tarefas;

typedef struct Lista
{
	char nome[20];
	TLista tarefa;
}Lista;

void menuInicial();
void criarLista();
void adicionarLista();
