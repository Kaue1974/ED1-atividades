#ifndef AGENDA_H
#define AGENDA_H

#define TAM_TITULO 40

typedef struct {
    int id;
    char titulo[TAM_TITULO];
    int prioridade;
} Missao;

typedef struct Lista Lista;

Missao criarMissao(int id, char titulo[], int prioridade);
void exibirMissao(Missao m);

Lista *criarLista();
void destruirLista(Lista *lista);
int inserirInicio(Lista *lista, Missao m);
int tamanhoLista(Lista *lista);
void exibirLista(Lista *lista);

#endif