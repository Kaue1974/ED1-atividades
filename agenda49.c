#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "agenda49.h"

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

/* ATIVIDADE 44 */

static No *buscarNo(Lista *lista, int id) {
    No *atual;

    if (lista == NULL) {
        return NULL;
    }

    atual = lista->inicio;

    while (atual != NULL) {
        if (atual->dado.id == id) {
            return atual;
        }
        atual = atual->proximo;
    }

    return NULL;
}

int buscarMissao(Lista *lista, int id) {
    if (buscarNo(lista, id) != NULL) {
        return 1;
    }

    return 0;
}

int inserirApos(Lista *lista, int idReferencia, Missao m) {
    No *referencia;
    No *novo;

    referencia = buscarNo(lista, idReferencia);

    if (referencia == NULL) {
        return 0;
    }

    novo = (No *) malloc(sizeof(No));

    if (novo == NULL) {
        return 0;
    }

    novo->dado = m;
    novo->proximo = referencia->proximo;
    referencia->proximo = novo;

    lista->tamanho++;

    return 1;
}

/* ATIVIDADE 45 */

int inserirAntes(Lista *lista, int idReferencia, Missao m) {
    No *anterior;
    No *atual;
    No *novo;

    if (lista == NULL) {
        return 0;
    }

    anterior = NULL;
    atual = lista->inicio;

    while (atual != NULL && atual->dado.id != idReferencia) {
        anterior = atual;
        atual = atual->proximo;
    }

    if (atual == NULL) {
        return 0;
    }

    novo = (No *) malloc(sizeof(No));

    if (novo == NULL) {
        return 0;
    }

    novo->dado = m;
    novo->proximo = atual;

    if (anterior == NULL) {
        lista->inicio = novo;
    } else {
        anterior->proximo = novo;
    }

    lista->tamanho++;

    return 1;
}

int removerInicio(Lista *lista, Missao *removida) {
    No *primeiro;

    if (lista == NULL || lista->inicio == NULL) {
        return 0;
    }

    primeiro = lista->inicio;

    *removida = primeiro->dado;
    lista->inicio = primeiro->proximo;

    free(primeiro);
    lista->tamanho--;

    return 1;
}

/* ATIVIDADE 46 */

int removerFim(Lista *lista, Missao *removida) {
    No *anterior;
    No *atual;

    if (lista == NULL || lista->inicio == NULL) {
        return 0;
    }

    anterior = NULL;
    atual = lista->inicio;

    while (atual->proximo != NULL) {
        anterior = atual;
        atual = atual->proximo;
    }

    *removida = atual->dado;

    if (anterior == NULL) {
        lista->inicio = NULL;
    } else {
        anterior->proximo = NULL;
    }

    free(atual);
    lista->tamanho--;

    return 1;
}

int removerPorId(Lista *lista, int id, Missao *removida) {
    No *anterior;
    No *atual;

    if (lista == NULL || lista->inicio == NULL) {
        return 0;
    }

    anterior = NULL;
    atual = lista->inicio;

    while (atual != NULL && atual->dado.id != id) {
        anterior = atual;
        atual = atual->proximo;
    }

    if (atual == NULL) {
        return 0;
    }

    *removida = atual->dado;

    if (anterior == NULL) {
        lista->inicio = atual->proximo;
    } else {
        anterior->proximo = atual->proximo;
    }

    free(atual);
    lista->tamanho--;

    return 1;
}

int verificarIntegridade(Lista *lista) {
    No *atual;
    int contagem = 0;

    if (lista == NULL) {
        return 0;
    }

    atual = lista->inicio;

    while (atual != NULL) {
        contagem++;
        atual = atual->proximo;
    }

    if (contagem == lista->tamanho) {
        return 1;
    }

    return 0;
}

/* ATIVIDADE 47 */

int removerDepois(Lista *lista, int idReferencia, Missao *removida) {
    No *referencia;
    No *alvo;

    referencia = buscarNo(lista, idReferencia);

    if (referencia == NULL) {
        return -1;
    }

    alvo = referencia->proximo;

    if (alvo == NULL) {
        return 0;
    }

    *removida = alvo->dado;
    referencia->proximo = alvo->proximo;

    free(alvo);
    lista->tamanho--;

    return 1;
}

int removerAntes(Lista *lista, int idReferencia, Missao *removida) {
    No *anteriorAoAnterior;
    No *anterior;
    No *atual;

    if (lista == NULL) {
        return -1;
    }

    anteriorAoAnterior = NULL;
    anterior = NULL;
    atual = lista->inicio;

    while (atual != NULL && atual->dado.id != idReferencia) {
        anteriorAoAnterior = anterior;
        anterior = atual;
        atual = atual->proximo;
    }

    if (atual == NULL) {
        return -1;
    }

    if (anterior == NULL) {
        return 0;
    }

    *removida = anterior->dado;

    if (anteriorAoAnterior == NULL) {
        lista->inicio = atual;
    } else {
        anteriorAoAnterior->proximo = atual;
    }

    free(anterior);
    lista->tamanho--;

    return 1;
}

/* ATIVIDADE 48 */

void limparLista(Lista *lista) {
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

    lista->inicio = NULL;
    lista->tamanho = 0;
}

int alterarMissao(Lista *lista, int id, char novoTitulo[], int novaPrioridade) {
    No *alvo;

    if (novoTitulo == NULL || strlen(novoTitulo) == 0 || strlen(novoTitulo) >= TAM_TITULO) {
        return -1;
    }

    if (novaPrioridade < 1 || novaPrioridade > 5) {
        return -1;
    }

    alvo = buscarNo(lista, id);

    if (alvo == NULL) {
        return 0;
    }

    strcpy(alvo->dado.titulo, novoTitulo);
    alvo->dado.prioridade = novaPrioridade;

    return 1;
}

/* ATIVIDADE 49 */

int contarMissoes(Lista *lista) {
    No *atual;
    int contagem = 0;

    if (lista == NULL) {
        return 0;  
    }

    atual = lista->inicio;   

    while (atual != NULL) {
        contagem++;
        atual = atual->proximo;
    }

    return contagem;
}

int inserirLote(Lista *lista, Missao lote[], int quantidade) {
    int i;
    int inseridas = 0;

    if (lista == NULL || lote == NULL) {
        return -1;
    }

    if (quantidade < 1 || quantidade > MAX_LOTE) {
        return -1;
    }

    for (i = 0; i < quantidade; i++) {
        if (!inserirFim(lista, lote[i])) {
            break;   
        }
        inseridas++;
    }

    return inseridas;
}