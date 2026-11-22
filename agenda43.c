#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "agenda43.h"

typedef struct No {
    Missao dado;
    struct No *proximo;
} No;

struct Lista {
    No *inicio;
    int tamanho;
};

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

/* ATIVIDADE 42 */

Lista *criarLista() {
    Lista *lista = (Lista *) malloc(sizeof(Lista));

    if (lista == NULL) {
        return NULL;
    }

    lista->inicio = NULL;
    lista->tamanho = 0;

    return lista;
}

void destruirLista(Lista *lista) {
    No *atual;
    No *proximo;

    if (lista == NULL) {
        return;
    }

    atual = lista->inicio;

    while (atual != NULL) {
        proximo = atual->proximo;
        free(atual);
        atual = proximo;
    }

    free(lista);
}

int inserirInicio(Lista *lista, Missao m) {
    No *novo;

    if (lista == NULL) {
        return 0;
    }

    novo = (No *) malloc(sizeof(No));

    if (novo == NULL) {
        return 0;
    }

    novo->dado = m;
    novo->proximo = lista->inicio;

    lista->inicio = novo;
    lista->tamanho++;

    return 1;
}

int tamanhoLista(Lista *lista) {
    if (lista == NULL) {
        return 0;
    }

    return lista->tamanho;
}

void exibirLista(Lista *lista) {
    No *atual;

    if (lista == NULL || lista->inicio == NULL) {
        printf("A agenda esta vazia.\n");
        return;
    }

    atual = lista->inicio;

    while (atual != NULL) {
        exibirMissao(atual->dado);
        atual = atual->proximo;
    }
}

/* ATIVIDADE 43 */

int inserirFim(Lista *lista, Missao m) {
    No *novo;
    No *atual;

    if (lista == NULL) {
        return 0;
    }

    novo = (No *) malloc(sizeof(No));

    if (novo == NULL) {
        return 0;
    }

    novo->dado = m;
    novo->proximo = NULL;      

    if (lista->inicio == NULL) {
        lista->inicio = novo;
    } else {
        atual = lista->inicio;

        while (atual->proximo != NULL) {
            atual = atual->proximo;
        }

        atual->proximo = novo;
    }

    lista->tamanho++;

    return 1;
}