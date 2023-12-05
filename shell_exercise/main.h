#include <stdlib.h>
#include <stdio.h>
#ifndef MAIN_H
#define MAIN_H
typedef struct Node {
	char *data;
	struct Node *next;
} Node;

typedef struct {
	Node *head;
	int size;
} list_l;

int getLine(char **lineptr, size_t *bufferSize, FILE *stream);
char **strTok(char *str, char *delim);
char **tokenize(char *str, char *delim);
int shellHelper(char **argv);
char *getEnv(const char *varName);
void printPath(void);
int print_list(list_l *list);
int add_node(list_l *list, char *item);
list_l *createList(void);

#endif
