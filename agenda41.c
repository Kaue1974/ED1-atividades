#include <stdio.h>
#include <string.h>
#include "agenda41.h"

Missao criarMissao(int id, char titulo[], int prioridade) {
    Missao m;

    m.id = id;
    strcpy(m.titulo, titulo);
    m.prioridade = prioridade;

    return m;
}

void exibirMissao(Missao m) {
    printf("ID: %d | Titulo: %s | Prioridade: %d\n", m.id, m.titulo, m.prioridade);
}