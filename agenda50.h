#ifndef AGENDA_H
#define AGENDA_H

#define TAM_TITULO 40

#define MAX_LOTE 5

#define NOME_ARQUIVO "agenda.bin"

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

int inserirFim(Lista *lista, Missao m);

int buscarMissao(Lista *lista, int id);
int inserirApos(Lista *lista, int idReferencia, Missao m);

int inserirAntes(Lista *lista, int idReferencia, Missao m);
int removerInicio(Lista *lista, Missao *removida);

int removerFim(Lista *lista, Missao *removida);
int removerPorId(Lista *lista, int id, Missao *removida);
int verificarIntegridade(Lista *lista);

int removerDepois(Lista *lista, int idReferencia, Missao *removida);
int removerAntes(Lista *lista, int idReferencia, Missao *removida);

void limparLista(Lista *lista);
int alterarMissao(Lista *lista, int id, char novoTitulo[], int novaPrioridade);

int contarMissoes(Lista *lista);
int inserirLote(Lista *lista, Missao lote[], int quantidade);

int ordenarLista(Lista *lista);
int salvarLista(Lista *lista, char nomeArquivo[]);

#endif