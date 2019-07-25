#include <conio.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#include "pq.h"

void error(char* str) {
	printf("Error - %s \n", str);
}

void test() {
	PQ* p = pq_create();
	char *result;
	int i;
	
	if (NULL == p) {
		error("Cola de prioridad null");
		exit(-1);
	}

	printf("\n==================================\n");
	for (i = 1; i <= 100; i++) {
		int random = rand() % 50;
		if (!pq_add(p, "test", random)) {
			error("no se pudo agregar");
			exit(-1);
		}
		printf("\n===================================\n");
		printf("Tamanho: %d \n", p->size);
		display(p);
		printf("===================================\n");
	}

	printf("\n==================================\n");
	printf("Sacando elementos");

	for (i = 1; i <= 100; i++) {
		if (!pq_remove(p, &result)) {
			error("no se pudo sacar");
			exit(-1);
		}
		printf("\n===================================\n");
		printf("Tamanho: %d \n", p->size);
		display(p);
		printf("===================================\n");
	}

	if (!pq_destroy(p)) {
		error("no se pudo destruir");
		exit(-1);
	}
}

int main(int argc, char* argv[]) {
	test();
	system("PAUSE");
	return 0;
}