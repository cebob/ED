#include <stdio.h>
#include <stdlib.h>

typedef struct no{
	int valor;
	struct no * prox;
} NO;

NO * inicio = NULL;
NO * fim = NULL;
int tam = 0;


void adicionar(int valor, int pos){
	if(pos>=0 && pos<=tam){
		NO * novo = (NO*) malloc(sizeof(NO));
		novo->valor = valor;
		novo->prox = NULL;
		if(inicio==NULL){
			inicio = novo;
			fim = inicio;
		}else if(pos==0){
			novo->prox = inicio;
			inicio = novo;
		}else if(pos==tam){
			fim->prox = novo;
			fim = novo;
		}else{
			NO * aux = inicio;
			int i;
			for(i=0;i<pos-1;i++){
				aux = aux->prox;
			}
			novo->prox = aux->prox;
			aux->prox = novo;
		}
		tam++;		
	}
}

int remover(int pos){
	
	if(pos>=0 && pos<tam){
		if(pos == 0){
			NO * aux;
			aux = inicio;
			inicio = inicio->prox;
			free(aux);
		}else if(pos == tam-1){
			NO * aux;
			aux = inicio;
			int i;
			for(i=0;i<tam-2; i++){//"tam-2": parar antes do último nó
				aux = aux->prox;
			}
			NO * lixo = fim; //armazenando último nó para eliminá-lo
			aux->prox = NULL;
			fim = aux;
			free(lixo);
		}else{
			
		}
	}
	
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
	
	return 0;
}
