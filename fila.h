#ifndef Pilha_pilha_h
#define Pilha_pilha_h

typedef struct fila{
	float elem;
	int prio;
	struct fila *prox;
}fila;

void parartela();
void enqueue( fila**, float, int );
float dequeue( fila** );
void situacaofila( fila** );
int prioridade();
void desistir( fila** );
void salvar( fila** );
void importar( fila** );

#endif
