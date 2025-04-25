all:
	gcc -g -Wall main.c operations.c project.c task.h -o main -lncurses
