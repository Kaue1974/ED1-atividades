#ifndef AGENDA_H
#define AGENDA_H

#define TAM_TITULO 40

typedef struct {
    int id;
    char titulo[TAM_TITULO];
    int prioridade;
} Missao;

Missao criarMissao(int id, char titulo[], int prioridade);
void exibirMissao(Missao m);

#endif