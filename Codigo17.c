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

    if (catalogo[0].vida >= 0 && catalogo[0].vida <= 100) {
        catalogo[0].vida -= 20;
    }

    if (catalogo[0].pontuacao >= 0) {
        catalogo[0].pontuacao += 50;
    }

    if (catalogo[0].posicao >= 0) {
        catalogo[0].posicao += 10;
    }

    if (catalogo[0].vida < 0) {
        catalogo[0].vida = 0;
    }

    if (catalogo[0].vida > 100) {
        catalogo[0].vida = 100;
    }

    getchar();

    alterar_nome(&catalogo[0]);

    printf("======= ESTADO DEPOIS DAS ALTERACOES ===\n");
    printf("Identificador: %d\n", catalogo[0].identificador);
    printf("Nome: %s\n", catalogo[0].nome);
    printf("Vida: %d\n", catalogo[0].vida);
    printf("Pontuacao: %d\n", catalogo[0].pontuacao);
    printf("Posicao: %d\n", catalogo[0].posicao);

    mostrar_personagem(catalogo[0]);

    demonstrar_copia(catalogo[0]);

    printf("\n--- FORA DA FUNCAO ---\n");
    printf("Vida do personagem original: %d\n", catalogo[0].vida);

    free(catalogo);

    return 0;
}