typedef struct Tarefas
{
	char nome;
	char descricao;
	bool estado;
}Tarefas

typedef struct Lista
{
	Tarefas *tarefa;
}Lista;


void menuInicial();
void criarLista();