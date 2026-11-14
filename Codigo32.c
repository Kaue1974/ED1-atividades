#include <stdio.h>
#include <string.h>

#define MAX_JOGADORES 6
#define TAM_NOME 30

typedef struct {
    int id;
    char nome[TAM_NOME];
    int pontuacao;
} Jogador;

void imprimirPontuacoes(int v[], int n) {
    int i;

    for (i = 0; i < n; i++) {
        printf("%d ", v[i]);
    }
    printf("\n");
}

void imprimirJogadores(Jogador v[], int n) {
    int i;

    printf("ID  | Nome       | Pontos\n");
    
    for (i = 0; i < n; i++) {
        printf("%-3d | %-10s | %d\n", v[i].id, v[i].nome, v[i].pontuacao);
    }
}

int posicaoMenor(int v[], int n, int inicio, int *comparacoes) {
    int i;
    int posMenor = inicio;

    for (i = inicio + 1; i < n; i++) {
        (*comparacoes)++;  
      
        if (v[i] < v[posMenor]) {
            posMenor = i;
        }
    }

    return posMenor;
}

void selectionSortNumeros(int v[], int n, int *comparacoes, int *trocas) {
    int i, posMenor, aux;

    for (i = 0; i < n - 1; i++) {
        posMenor = posicaoMenor(v, n, i, comparacoes);

        if (posMenor != i) {
            aux = v[i];
            v[i] = v[posMenor];
            v[posMenor] = aux;

            (*trocas)++;
        }
    }
}

int jogadorMenor(Jogador a, Jogador b) {
    int cmp;

    if (a.pontuacao != b.pontuacao) {
        return a.pontuacao < b.pontuacao;
    }

    cmp = strcmp(a.nome, b.nome);

    if (cmp != 0) {
        return cmp < 0;
    }

    return a.id < b.id;
}

int posicaoMenorJogador(Jogador v[], int n, int inicio, int *comparacoes) {
    int i;
    int posMenor = inicio;

    for (i = inicio + 1; i < n; i++) {
        (*comparacoes)++;

        if (jogadorMenor(v[i], v[posMenor])) {
            posMenor = i;
        }
    }

    return posMenor;
}

void selectionSortJogadores(Jogador v[], int n, int *comparacoes, int *trocas) {
    int i, posMenor;
    Jogador aux;

    for (i = 0; i < n - 1; i++) {
        posMenor = posicaoMenorJogador(v, n, i, comparacoes);

        if (posMenor != i) {
            aux = v[i];
            v[i] = v[posMenor];
            v[posMenor] = aux;
            (*trocas)++;
        }
    }
}

Jogador criarJogador(int id, char nome[], int pontuacao) {
    Jogador j;
    j.id = id;
    strcpy(j.nome, nome);
    j.pontuacao = pontuacao;
    return j;
}

int main() {
    int pontosOriginal[MAX_JOGADORES] = {75, 40, 90, 55, 40, 100};
    int pontosTrabalho[MAX_JOGADORES];

    Jogador jogadoresOriginal[MAX_JOGADORES];
    Jogador jogadoresTrabalho[MAX_JOGADORES];

    int i;
    int comparacoes, trocas;

    jogadoresOriginal[0] = criarJogador(1, "Carlos", 75);
    jogadoresOriginal[1] = criarJogador(2, "Bia", 40);
    jogadoresOriginal[2] = criarJogador(3, "Ana", 90);
    jogadoresOriginal[3] = criarJogador(4, "Diego", 55);
    jogadoresOriginal[4] = criarJogador(5, "Kauê", 40);
    jogadoresOriginal[5] = criarJogador(6, "Daniel", 100);

    for (i = 0; i < MAX_JOGADORES; i++) {
        pontosTrabalho[i] = pontosOriginal[i];
        jogadoresTrabalho[i] = jogadoresOriginal[i];
    }

    comparacoes = 0;
    trocas = 0;

    printf("=== SELECTION SORT - PONTUACOES ===\n");
    printf("Antes : ");
    imprimirPontuacoes(pontosTrabalho, MAX_JOGADORES);

    selectionSortNumeros(pontosTrabalho, MAX_JOGADORES, &comparacoes, &trocas);

    printf("Depois: ");
    imprimirPontuacoes(pontosTrabalho, MAX_JOGADORES);
    printf("Comparacoes: %d | Trocas: %d\n\n", comparacoes, trocas);

    comparacoes = 0;
    trocas = 0;

    printf("=== SELECTION SORT - JOGADORES ===\n");
    printf("Antes:\n");
    imprimirJogadores(jogadoresTrabalho, MAX_JOGADORES);

    selectionSortJogadores(jogadoresTrabalho, MAX_JOGADORES, &comparacoes, &trocas);

    printf("\nDepois (por pontuacao, desempate por nome):\n");
    imprimirJogadores(jogadoresTrabalho, MAX_JOGADORES);
    printf("Comparacoes: %d | Trocas: %d\n\n", comparacoes, trocas);

    printf("=== ORIGINAIS PRESERVADOS ===\n");
    imprimirPontuacoes(pontosOriginal, MAX_JOGADORES);
    imprimirJogadores(jogadoresOriginal, MAX_JOGADORES);

    return 0;
}