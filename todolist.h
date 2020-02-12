typedef struct Tarefas
{
	char nome[20];
	char descricao[50];
	bool estado;
}Tarefas;

typedef struct Lista
{
	char nome[20];
	Tarefas *tarefa;
}Lista;

void menuInicial();
void criarLista();
void adicionarLista();