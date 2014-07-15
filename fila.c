#include<stdio.h>
#include<stdlib.h>
#include"./fila.h"

void parartela(){
	char wait;	
	printf("\n\nPressione qualquer caractere + Enter para voltar ao MENU... ");
	scanf(" %c",&wait);
}

void enqueue( fila **ini, float elem, int prio ){ 
	fila *posicao, *ant = NULL, *atu = NULL;
	posicao=( fila* ) malloc( sizeof( fila ) );
	posicao->prox = NULL;
	posicao->elem = elem;	
	posicao->prio = prio;
	if(*ini == NULL)
		*ini = posicao;
	else{
		atu = *ini;
		while((atu != NULL) && ((atu->prio) <= (posicao->prio))){
			ant = atu;
			atu = atu->prox;
		}	
		posicao->prox = atu;
		if(ant == NULL)
			*ini = posicao;
		else
			ant->prox = posicao;
	}	
	printf("\nElemento %.2f foi inserido na fila.",elem);
}

float dequeue(fila **cab){
	float e;
	fila *atu;
	atu = *cab; 
	e = atu->elem;
	*cab = atu->prox;
	free(atu);
	atu = NULL;
	return  e;
}

void situacaofila(fila **I){
	fila *aux;
	printf("SITUACAO DA FILA\n\nFILA-> ");
	if(*I == NULL)
		printf("null");
	else{ 
		aux = *I;
		printf("INICIO__");
		while(aux != NULL){
			printf("(%.2f,%d)__",aux->elem,aux->prio);
			aux = aux->prox;
		}
		printf("FIM");	
	}
}
int prioridade(){
	char prior;
	printf("\nPRIORIDADE\n\n");
	printf("[1]Premium - idosos, portadores de necessidades especiais e gestante\n");
	printf("[2]Premium\n");
	printf("[3]Correntista - idosos, portadores de necessidades especiais e gestante\n");
	printf("[4]Correntista\n");
	printf("[5]Nao correntista\n\n");	
	printf("Prioridade: ");
	scanf(" %c",&prior);
	while(prior<'1' || prior>'5'){
		printf("Nao existe prioridade %c\nDigite prioridade de 1-5: ",prior);
		scanf(" %c",&prior);
	}
	if(prior == '1')
		return 1;
	else if(prior == '2')
		return 2;
	else if(prior == '3')
		return 3;
	else if(prior == '4')
		return 4;
	return 5;
}
void desistir(fila **D){
	fila *ant = NULL,*atu = *D;
	float f;
	printf("Digite o numero do elemento que deseja sair da fila: ");
	scanf("%f",&f);
	while(atu != NULL && f != atu->elem){
		ant = atu;		
		atu = atu->prox;
	}
	if(atu != NULL){
		if(ant != NULL)
			ant->prox = atu->prox;
		else
			*D = atu->prox;
		free(atu);
		printf("\nO elemento %f cansou de esperar e saiu da fila.",f);
	}else
		printf("\nO elemento %f nao esta na fila.",f);
}
void salvar(fila **L){
	fila *aux;				
	FILE *line;
	line = fopen("fila.txt","w");
	if(*L != NULL){
		aux = *L;	
		while(aux != NULL){
			fprintf(line,"%f %d\n",aux->elem,aux->prio);
			aux = aux->prox;
		}
	}else 		
		printf("Nao exite nenhum elemento na fila.\n\n");		
	fclose(line);
	printf("Fila salva.");
	parartela();
}
void importar(fila **L){
	FILE *line;
	int prio,cont;
	float elem;
	line = fopen("fila.txt","r");
	if(line != NULL){
		cont=0;
		while(fscanf(line,"%f",&elem)!=EOF){
			fscanf(line,"%d",&prio);
			enqueue(&(*L),elem,prio);
			cont++;
		}
		if(cont>0)
			printf("\n\nForam importados %d elementos para fila.",cont);
		else
			printf("Arquivo vazio.");
		fclose(line);
	}else
		printf("O arquivo fila.txt nao existe! Adicione o arquivo na mesma pasta do programa.");
	parartela();
}

