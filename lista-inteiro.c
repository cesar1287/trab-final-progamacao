#include <stdlib.h>
#include <stdio.h>

typedef struct zezin {
	int info;
	struct zezin *prox;
} noLista;

void inserir(noLista **l, int dado) {
	noLista *novo,*aux;

	novo=(noLista*)malloc(sizeof(noLista));
	novo->prox = NULL;
	novo->info = dado;

	if ((*l) == NULL)
		(*l) = novo;
	else {
		aux = (*l);
		while (aux->prox != NULL)
			aux = aux->prox;
		aux->prox = novo;
	}
}

void percorrer(noLista *l) {
	noLista *aux;

	if (l == NULL)
		printf("Agenda vazia.\n");
	else {
		aux = l;
		while(aux != NULL) {
			printf("Elemento: %d\n", aux->info);
			aux = aux->prox;
		}
	}
}

int main(int narg, char *argv[]) {
	noLista *agenda = NULL;

	inserir(&agenda, 13);
	inserir(&agenda, 14);
	inserir(&agenda, 15);
	inserir(&agenda, 16);

	percorrer(agenda);

	return EXIT_SUCCESS;
}










