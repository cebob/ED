#include <stdio.h>
#include <stdlib.h>

typedef struct no{
	int valor;
	struct no * prox;
} NO;

NO * inicio = NULL;
NO * fim = NULL;
int tam = 0;


void adicionar(int valor){
	if(pos>=0 && pos<=tam){
		NO * novo = (NO*) malloc(sizeof(NO));
		novo->valor = valor;
		novo->prox = NULL;
		if(inicio==NULL){
			inicio = novo;
			fim = inicio;
		}else if(valor < inicio->valor){//Se o valor dado for menor que o valor do primeiro nó
			novo->prox = inicio;
			inicio = novo;
		}else if(valor > fim->valor){//Se o valor dado for menor que o valor do último nó
			fim->prox = novo;
			fim = novo;
		}else{
			NO * aux = inicio;
			int i;
			while(valor > aux->prox->valor){
				aux->prox;
			}
			novo->prox = aux->prox;
			aux->prox = novo;
		}
		tam++;		
	}
}

int remover(int valor){
	int retorno = -1;
	
	if(tam == 1 && inicio->valor == valor){
		NO * lixo = inicio;
		retorno = inicio->valor;
		inicio = NULL;
		fim = NULL;
		free(lixo);
	}else if(valor == inicio->valor){
		NO * aux;
		aux = inicio;
		retorno = aux->valor;
		inicio = inicio->prox;
		free(aux);
	}else if(valor == fim->valor){
		NO * aux;
		aux = inicio;
		int i;
		for(i=0;i<tam-2; i++){//"tam-2": parar antes do último nó
			aux = aux->prox;
		}
		NO * lixo = fim; //armazenando último nó para eliminá-lo
		retorno = lixo->valor;
		aux->prox = NULL;
		fim = aux;
		free(lixo);
	}else{
		NO * aux = inicio;
		int i;
		while(valor > aux->prox->valor){
			aux = aux->prox;
		}
		if(aux->prox->valor == valor){
			NO * lixo = aux->prox;
			retorno = lixo->valor;
			aux->prox = aux->prox->prox;
			free(lixo);
		}	
	}
	
	return retorno;
	tam--;
	
}

void imprimir(){
	NO *aux = inicio;
	int i;
	printf("|| LISTA ||\n");
	for(i=0;i<tam;i++){
		printf("%d    ", aux->valor);
		aux = aux->prox;
	}
}

int main(){
	adicionar(2,0);
	adicionar(4,1);
	adicionar(7,2);
	adicionar(7,3);
	adicionar(10,0);
	adicionar(20,1);
	imprimir();
	remover(0);
	imprimir();
	
	return 0;
}
