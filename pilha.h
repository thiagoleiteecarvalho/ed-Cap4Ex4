/*
 * pilha.h
 * Header de definição da ED Pilha.
 * Author: Thiago Leite
 */

#pragma once

typedef struct elemento {
	int valor;
	struct elemento *proximo;
} Elemento;

typedef struct pilha {
	Elemento *topo;
	int tamanho;
} Pilha;

Pilha* iniciar();
void push(Pilha *p, int valor);
int pop(Pilha *p);
int empty(Pilha *p);
void exibir(Pilha *p);
int top(Pilha *p);
