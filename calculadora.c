#include <stdio.h>
#include <stdlib.h>

char vetor[] = {'1','2','-','4','5','+','*'};

typedef struct no{
    int valor;
    struct no * prox;
}NO;

NO *inicio = NULL;
int tam = 0;


void adicionar(int valor){
    NO *novo =(NO*) malloc (sizeof(NO));
    novo->valor = valor;
    novo->prox = NULL;
    novo->prox = inicio;
    inicio = novo;
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
	int retorno = inicio->valor;
    NO* lixo = inicio;
    inicio = inicio->prox;
    free(lixo);
    tam--;
    return retorno;
    
}

void percorrer(){
	
	int i, aux;
	for(i=0;i<7;i++){
		aux = vetor[i];
		if(aux>=48 && aux<=57){
			
		}
	}
	
}


int main(){
	
	percorrer();
	
	return 0;
}
