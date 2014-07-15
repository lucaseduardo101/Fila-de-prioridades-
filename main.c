#include<stdio.h>
#include<stdlib.h>
#include"fila.h"
/*
Programa desenvolvido por Lucas Eduardo para a disciplina de programação da Universidade
Federal do Ceará

Criar uma fila de prioridade

*/
int main(){
	fila *P = NULL;
	int prio;
	float elem;
	char op;
	do {
		system( "clear" );
		printf( "FILA COM PRIORIDADE\n\n" );
		situacaofila( &P );
		printf( "\n\nMENU\n\n[1]enqueue\n[2]dequeue\n[3]Desistir\n[4]Salvar fila\n[5]Importar fila\n*Digite qualquer caractere + Enter para sair\n\nOpcao: " );
		scanf(" %c", &op);
		system( "clear" );
		if ( op == '1' ){
			printf( "ENQUEUE\n\nElemento: " );
			scanf( "%f",&elem );
			prio = prioridade();
			enqueue( &P,elem,prio );
			parartela();
		} else if( op == '2' ){
			printf( "DEQUEUE\n\n" );
			if( P != NULL ){
				elem = dequeue( &P );
				printf( "%.2f\n",elem );
			}
			else
				printf("null\n");
			parartela();
		}else if(op == '3'){
			printf("DESISTIR\n\n");
			if( P != NULL ){
				desistir(&P);
				}
			else{
				printf("A fila ainda esta vazia, portanto nao tem como haver desistencias!");
				}
			parartela();
		}else if(op == '4'){
			salvar(&P);
		}else if(op == '5'){
			importar(&P);
		}
	}while(op == '1' || op == '2' || op == '3' || op == '4' || op == '5');
	printf("Programa encerrado\n\n");
	return EXIT_SUCCESS;
}
