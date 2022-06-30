#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct NO {
	int dado;
	struct NO *prox;
};

typedef struct NO lista;

lista * criaLista(int dado){
	lista *p;
	p = (lista *) malloc(sizeof(lista *));
	p->dado = dado;
	p->prox = NULL;
	return p;
} 


void push (lista *p, int dado){
	lista * newData, *aux;
	
	newData = criaLista(dado);
	aux = p;
	
	while (aux->prox != NULL){
		aux = aux->prox;
	}
		
	aux->prox = newData;
	

}

void imprimePosNeg (lista *p){
	lista *aux = p;
	int pos = 0, negativos = 0;
	
	while(aux != NULL){
		if(aux->dado < 0){
			negativos++;
		}else{
			pos++;
			
		}
	aux = aux->prox;
	}
	printf("\nQuantidade de positivos: %d\nQuantidade de negativos: %d", pos, negativos);
}

void imprimeLista(lista *p){
	
	printf("\n\n");
	lista * aux;
	
	aux = p;
	
	while(aux != NULL){
		printf("%d - ", aux->dado);
		aux = aux->prox;
	}
		

	while(aux != NULL){
		printf("%d - ", aux->dado);
		aux = aux->prox;
	}
	printf("\n\n");
}


void sortDecres(lista *p){
	lista *aux = p;
	
	while (aux->prox != NULL){
		lista *menor = aux;
		lista *secAux = aux;
		
		while(secAux != NULL){
			if (menor->dado < secAux->dado){
				menor = secAux;
			}
			secAux = secAux->prox;
		}
		int tercAux = menor->dado;
		menor->dado = aux->dado;
		aux->dado = tercAux;
		aux = aux->prox;
	}
	imprimeLista(p);
}


void sortCresc(lista *p){
	lista *aux = p;
	
	while (aux->prox != NULL){
		lista *menor = aux;
		lista *secAux = aux;
		
		while(secAux != NULL){
			if (menor->dado > secAux->dado){
				menor = secAux;
			}
			secAux = secAux->prox;
		}
		int tercAux = menor->dado;
		menor->dado = aux->dado;
		aux->dado = tercAux;
		aux = aux->prox;
	}
	imprimeLista(p);
}


int main () {
	
	lista *p = NULL;
	int escolha = 0, cLista = 0, size = 0, numeros, teste=0;
	
	printf("Digite Quantos Numeros deseja inserir?\n");
  	scanf("%d", &size);
  
  	printf("Numero %d: ", escolha+1);
  	scanf("%d", &cLista);
  
  	p = criaLista(cLista);
  	
  	do {

 		printf("Numero %d: ", escolha+2);
  		scanf("%d", &numeros);
  		push(p, numeros);
  		escolha++;

  		
	  }while (escolha < size-1);
	  
	  printf("\nQuantidade de numeros inseridos: %d", escolha + 1);
	  
	  printf("\n\nLista desordenada \n");
	  imprimeLista(p);
	  printf("Lista decrescente \n");
	  sortDecres(p);
	  printf("Lista cecrescente \n");
	  sortCresc(p);
	  imprimePosNeg(p);
	  
	  
	
}
