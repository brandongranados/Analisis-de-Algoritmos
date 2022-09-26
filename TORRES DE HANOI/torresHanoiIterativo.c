/* Implementación de las torres de Hanoi de manera iterativa */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define TAMPILA 10
struct pila {
	int item[TAMPILA];
	int tope;
};
typedef struct pila TDA_PILA;
int push(TDA_PILA *, int);
int pop(TDA_PILA *p, int *e);
int stacktop(TDA_PILA p, int *e);
int empty(TDA_PILA p);
void startpila(TDA_PILA *p);
void t_Hanoi(int, TDA_PILA *, TDA_PILA *, TDA_PILA *,TDA_PILA *, TDA_PILA *, TDA_PILA *);
void mostrar(TDA_PILA C);
int main() {
	clock_t start_t=clock(), end_t;
	int n;
	TDA_PILA A, B, C;
	startpila(&A);
	startpila(&B);
	startpila(&C);
	TDA_PILA* a = &A;
	TDA_PILA* b = &B;
	TDA_PILA* c = &C;
	printf("******\tTORRE DE HANOI\t******");
	printf("\nIngrese la cantidad de disco(s): ");
	scanf("%d", &n);
	printf("\nInicializando la Torre A con disco(s) del 1 al %d", n);
	for (int i = n; i > 0; i--)
		push(&A, i);
	printf("\n\tTorre llena exitosamente");
	printf("\nLos elementos de la Torre A son: ");
	mostrar(A);
	printf("\n\t");
	t_Hanoi(n, &A, &B, &C, a, b, c);
	printf("\n\tDiscos movidos exitosamente");
	printf("\nLos elementos de la Torre C son: ");
	mostrar(C);
	printf("\n\t");
	end_t=clock();
	float final = (float)(((end_t-start_t)/CLOCKS_PER_SEC)*1000);
	printf("%f milisegundos\n", final);
	system("pause");
	return 0;
}
int push(TDA_PILA *p, int e) {
	if (p->tope == TAMPILA - 1)
		return 0;
	p->item[++(*p).tope] = e;
	return 1;
}
int pop(TDA_PILA *p, int *e) {
	if (empty(*p))
		return 0;
	*e = p->item[(*p).tope--];
	return 1;
}
int stacktop(TDA_PILA p, int *e) {
	if (empty(p))
		return 0;
	*e = p.item[p.tope];
	return 1;
}
int empty(TDA_PILA p) {
	if (p.tope == -1)
		return 1;
	return 0;
}
void startpila(TDA_PILA *p) {
	p->tope = -1;
}
void t_Hanoi(int n, TDA_PILA *A, TDA_PILA *B, TDA_PILA *C,TDA_PILA *a, TDA_PILA *b, TDA_PILA *c) {
	int e;
	char aux, aux1;
	if (a == A)
		aux = 'A';
	else if (b == A)
		aux = 'B';
	else if (c == A)
		aux = 'C';
	if (a == C)
		aux1 = 'A';
	else if (b == C)
		aux1 = 'B';
	else if (c == C)
		aux1 = 'C';
	if (n == 1) {
		pop(A, &e);
		push(C, e);
		printf("\nDisco %d movido de la Torre %c a la Torre %c", n, aux, aux1);
	}
	else {
		t_Hanoi(n - 1, A, C, B, a, b, c);
		pop(A, &e);
		push(C, e);
		printf("\nDisco %d movido de la Torre %c a la Torre %c", n, aux, aux1);
		t_Hanoi(n - 1, B, A, C, a, b, c);
	}
}
void mostrar(TDA_PILA C) {
	int e;
	while (pop(&C, &e))
		printf("%d", e);
}