#include <stdio.h>
#include <stdlib.h>

typedef struct no{
    int valor;
    struct no * prox;
}NO;

NO *inicio = NULL;
NO *fim = NULL;
int tam = 0;


void adicionar(int valor){
    NO *novo =(NO*) malloc (sizeof(NO));
    novo->valor = valor;
    novo->prox = NULL;
    if(fim == NULL){
    	fim = novo;
    	inicio = novo;
	}else{
		fim->prox = novo;
		inicio = fim;
    	fim = novo;
	}
    tam++;
}


void imprimir(){
    NO *aux = inicio;
    int i;
    printf("Imprimindo a lista :D\n");
    for(i=0; i< tam; i++){
        printf("%d ", aux->valor);
        aux = aux->prox;
    }
}

int remover(){
	NO* lixo = inicio;
    inicio = inicio->prox;
    free(lixo);
}


int main(){
    adicionar(20);
    adicionar(20);
    adicionar(20);
    adicionar(20);
    imprimir();
    return 0;
}

