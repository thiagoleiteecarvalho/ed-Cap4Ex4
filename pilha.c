/*
 * main.c
 * Classe de implemantação da ED Pilha.
 * Author: Thiago Leite
 */

#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"

Pilha* iniciar() {

	Pilha *p = malloc(sizeof(Pilha));
	p->topo = NULL;
	p->tamanho = 0;

	return p;
}

void push(Pilha *p, int caractere) {

	Elemento *e = malloc(sizeof(Elemento));
	e->valor = caractere;
	e->proximo = p->topo;
	p->topo = e;

	p->tamanho = p->tamanho + 1;
}

int pop(Pilha *p) {

	Elemento *e;
	int i;

	if (!empty(p)) {

		e = p->topo;
		i = e->valor;
		p->topo = p->topo->proximo;

		p->tamanho = p->tamanho - 1;

		free(e);

		return i;
	} else {
		return 0;
	}

}

void exibir(Pilha *p) {

	if (empty(p)) {

		printf("Pilha vazia!\n");
		return;
	}

	Elemento *e;
	e = p->topo;
	printf("Pilha:\n");

	while (e != NULL) {

		printf(" %d\n", e->valor);
		e = e->proximo;
	}

	printf("\n\n");
}

int empty(Pilha *p) {
	return p->tamanho == 0;
}


int top(Pilha *p) {

	if (empty(p)) {

		printf("Pilha vazia!\n");
		return 0;
	}

	return p->topo->valor;
}
