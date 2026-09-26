#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int identificador;
    char nome[50];
    int vida;
    int pontuacao;
    int posicao;
} Personagem;

Personagem criar_personagem(int identificador, const char nome[], int vida, int pontuacao, int posicao) {
    
    Personagem personagem = {.identificador = identificador, .nome = "", .vida = vida, .pontuacao = pontuacao, .posicao = posicao};

    strncpy(personagem.nome, nome, sizeof(personagem.nome) - 1);
    personagem.nome[sizeof(personagem.nome) - 1] = '\0';

    return personagem;
}

void alterar_nome(Personagem *personagem) {
    if (personagem == NULL) {
        printf("Erro: ponteiro nulo.\n");
        return;
    }

    char novo_nome[50];

    printf("Digite o novo nome: ");
    fgets(novo_nome, sizeof(novo_nome), stdin);

    novo_nome[strcspn(novo_nome, "\n")] = '\0';

    if (strlen(novo_nome) == 0) {
    printf ("Nome invalido");
        return;
    }

    strncpy(personagem->nome, novo_nome, sizeof(personagem->nome) - 1);
    
    personagem->nome[sizeof(personagem->nome) - 1] = '\0';
}

void mostrar_personagem(Personagem personagem) {
    printf("==== CONSULTA DO PERSONAGEM ====\n");
    printf("Identificador: %d\n", personagem.identificador);
    printf("Nome: %s\n", personagem.nome);
    printf("Vida: %d\n", personagem.vida);
    printf("Pontuacao: %d\n", personagem.pontuacao);
    printf("Posicao: %d\n", personagem.posicao);
}

void demonstrar_copia(Personagem personagem) {
    printf("==== DENTRO DA FUNCAO ====\n");
    printf("Vida antes da alteracao da copia: %d\n", personagem.vida);

    personagem.vida = 0;

    printf("Vida depois da alteracao da copia: %d\n", personagem.vida);
}

void alterar_vida(Personagem *personagem, int dano) {
    if (personagem == NULL) {
        printf("Erro: ponteiro nulo.\n");
        return;
    }

    if (dano < 0) {
        printf("Dano invalido.\n");
        return;
    }

    personagem->vida -= dano;

    if (personagem->vida < 0) {
        personagem->vida = 0;
    }

    if (personagem->vida > 100) {
        personagem->vida = 100;
    }
}

void alterar_posicao(Personagem *personagem, int nova_posicao) {
    if (personagem == NULL) {
        printf("Erro: ponteiro nulo.\n");
        return;
    }

    if (nova_posicao < 0) {
        printf("Posicao invalida.\n");
        return;
    }

    personagem->posicao = nova_posicao;
}

void alterar_pontuacao(Personagem *personagem, int pontos) {
    if (personagem == NULL) {
        printf("Erro: ponteiro nulo.\n");
        return;
    }

    if (pontos < 0) {
        printf("Pontuacao invalida.\n");
        return;
    }

    personagem->pontuacao += pontos;
}

int main() {

    int capacidade = 5;
    int nova_capacidade;

    Personagem *catalogo = calloc(capacidade, sizeof(Personagem));

    if (catalogo == NULL) {
        printf("Erro ao alocar memoria.\n");
        return 1;
    }

    printf("Capacidade inicial: %d\n\n", capacidade);
    printf("Posicoes inicialmente zeradas:\n");

    for (int i = 0; i < capacidade; i++) {
        printf("catalogo[%d].identificador = %d\n", i, catalogo[i].identificador);
        printf("catalogo[%d].vida = %d\n", i, catalogo[i].vida);
        printf("catalogo[%d].pontuacao = %d\n\n", i, catalogo[i].pontuacao);
    }

    printf("Digite a nova capacidade: ");
    scanf("%d", &nova_capacidade);

    if (nova_capacidade <= 0) {
        printf("Capacidade invalida.\n");
        free(catalogo);
        return 1;
    }

    int capacidade_anterior = capacidade;

    Personagem *temporario = realloc(catalogo, nova_capacidade * sizeof(Personagem));

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
            catalogo[i].identificador = 0;
            catalogo[i].nome[0] = '\0';
            catalogo[i].vida = 0;
            catalogo[i].pontuacao = 0;
            catalogo[i].posicao = 0;
        }
    }

    printf("Capacidade anterior: %d\n", capacidade_anterior);
    printf("Nova capacidade: %d\n", capacidade);

    Personagem personagem = criar_personagem(1, "Kaue", 100, 0, 0);

    catalogo[0] = personagem;

    printf("======= ESTADO ANTES DAS ALTERACOES =====\n");
    printf("Identificador: %d\n", catalogo[0].identificador);
    printf("Nome: %s\n", catalogo[0].nome);
    printf("Vida: %d\n", catalogo[0].vida);
    printf("Pontuacao: %d\n", catalogo[0].pontuacao);
    printf("Posicao: %d\n", catalogo[0].posicao);

    getchar();

    alterar_nome(&catalogo[0]);

    alterar_vida(&catalogo[0], 20);

    alterar_pontuacao(&catalogo[0], 50);

    alterar_posicao(&catalogo[0], 10);

    printf("======= ESTADO DEPOIS DAS ALTERACOES ===\n");
    printf("Identificador: %d\n", catalogo[0].identificador);
    printf("Nome: %s\n", catalogo[0].nome);
    printf("Vida: %d\n", catalogo[0].vida);
    printf("Pontuacao: %d\n", catalogo[0].pontuacao);
    printf("Posicao: %d\n", catalogo[0].posicao);

    printf("\n======= OPERADOR SETA E EQUIVALENCIA =======\n");

    printf("Usando -> : %d\n", catalogo[0].vida);

    printf("Usando (*p).membro: %d\n", (*(&catalogo[0])).vida);

    mostrar_personagem(catalogo[0]);

    demonstrar_copia(catalogo[0]);

    printf("==== FORA DA FUNCAO ====\n");
    printf("Vida do personagem original: %d\n", catalogo[0].vida);

    free(catalogo);

    return 0;
}