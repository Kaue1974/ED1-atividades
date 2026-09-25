#include <stdio.h>
#include <stdlib.h>

int main() {

    int capacidade = 5;
    int nova_capacidade;

    int *catalogo = calloc(capacidade, sizeof(int));

    if (catalogo == NULL) {
        printf("Erro ao alocar memoria.\n");
        return 1;
    }

    printf("Capacidade inicial: %d\n\n", capacidade);
    printf("Posicoes inicialmente zeradas:\n");

    for (int i = 0; i < capacidade; i++) {
        printf("catalogo[%d] = %d\n", i, catalogo[i]);
    }

    printf("Digite a nova capacidade: ");
    scanf("%d", &nova_capacidade);

    if (nova_capacidade <= 0) {
        printf("Capacidade invalida.\n");
        free(catalogo);
        return 1;
    }

    int capacidade_anterior = capacidade;
    int *temporario = realloc(catalogo, nova_capacidade * sizeof(int));

    if (temporario == NULL) {
        printf("Erro ao redimensionar o catalogo.\n");
        printf("A capacidade continua sendo: %d\n", capacidade_anterior);

        free(catalogo);
        return 1;
    }

    catalogo = temporario;
    capacidade = nova_capacidade;

    if (capacidade > capacidade_anterior) {
        for (int i = capacidade_anterior; i < capacidade; i++) {
            catalogo[i] = 0;
        }
    }

    printf("Capacidade anterior: %d\n", capacidade_anterior);
    printf("Nova capacidade: %d\n", capacidade);

    printf("Posicoes do catalogo:\n");

    for (int i = 0; i < capacidade; i++) {
        printf("catalogo[%d] = %d\n", i, catalogo[i]);
    }

    free(catalogo);

    return 0;
}