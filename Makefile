all:TAREFAS
	gcc main.c todolist.o -o todolist
TAREFAS:
	gcc -c todolist.c