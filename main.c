/*
 * main.c
 * Resposta do exercício 4 do capítulo 4.
 * Author: Thiago Leite
 */

#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"

int main(void) {

	Pilha *pilha_principal = iniciar();
	Pilha *pilha_auxiliar = iniciar();

	if (!pilha_principal || !pilha_auxiliar) {

		printf("Sem memória disponivel!\n");

		exit(1);
	} else {

		push(pilha_principal, 30);
		push(pilha_principal, 10);
		push(pilha_principal, 20);
		push(pilha_principal, 50);
		push(pilha_principal, 40);

		exibir(pilha_principal);

		int maior;
		int menor;
		int valor;

		maior = menor = top(pilha_principal);

		while (!empty(pilha_principal)) {

			valor = pop(pilha_principal);
			if (valor > maior) {
				maior = valor;
			} else if (valor < menor) {
				menor = valor;
			}

			push(pilha_auxiliar, valor);
		}

		while (!empty(pilha_auxiliar)) {

			valor = pop(pilha_auxiliar);
			if (valor != maior && valor != menor)
				push(pilha_principal, valor);
		}

		exibir(pilha_principal);

		free(pilha_principal);
		pilha_principal = NULL;

		free(pilha_auxiliar);
		pilha_auxiliar = NULL;

		return 0;
	}
}
