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

/* ATIVIDADE 33 */

void inserirEmPrefixoOrdenado(int v[], int tamPrefixo, int *comparacoes, int *deslocamentos) {
    int valor = v[tamPrefixo];   
    int j = tamPrefixo - 1;     

    while (j >= 0) {
        (*comparacoes)++;

        if (v[j] > valor) {
            v[j + 1] = v[j];     
            (*deslocamentos)++;
            j--;
        } else {
            break;              
        }
    }

    v[j + 1] = valor;            
}

void insertionSortNumeros(int v[], int n, int *comparacoes, int *deslocamentos) {
    int i;

    for (i = 1; i < n; i++) {
        inserirEmPrefixoOrdenado(v, i, comparacoes, deslocamentos);
    }
}

void inserirJogadorEmPrefixoOrdenado(Jogador v[], int tamPrefixo, int *comparacoes, int *deslocamentos) {
    Jogador valor = v[tamPrefixo];   
    int j = tamPrefixo - 1;

    while (j >= 0) {
        (*comparacoes)++;

        if (jogadorMenor(valor, v[j])) {
            v[j + 1] = v[j];        
            (*deslocamentos)++;
            j--;
        } else {
            break;
        }
    }

    v[j + 1] = valor;
}

void insertionSortJogadores(Jogador v[], int n, int *comparacoes, int *deslocamentos) {
    int i;

    for (i = 1; i < n; i++) {
        inserirJogadorEmPrefixoOrdenado(v, i, comparacoes, deslocamentos);
    }
}

int estaOrdenadoNumeros(int v[], int n) {
    int i;

    for (i = 1; i < n; i++) {
        if (v[i] < v[i - 1]) {
            return 0;
        }
    }
    return 1;
}

int estaOrdenadoJogadores(Jogador v[], int n) {
    int i;

    for (i = 1; i < n; i++) {
        if (jogadorMenor(v[i], v[i - 1])) {
            return 0;
        }
    }
    return 1;
}

int vetoresIguais(int a[], int b[], int n) {
    int i;

    for (i = 0; i < n; i++) {
        if (a[i] != b[i]) {
            return 0;
        }
    }
    return 1;
}

int jogadoresIguais(Jogador a[], Jogador b[], int n) {
    int i;

    for (i = 0; i < n; i++) {
        if (a[i].id != b[i].id) {
            return 0;
        }
    }
    return 1;
}

void mostrarValidacao(int ok) {
    if (ok) {
        printf("OK\n");
    } else {
        printf("ERRO\n");
    }
}

int main() {
    int pontosOriginal[MAX_JOGADORES] = {75, 40, 90, 55, 40, 100};
    int pontosTrabalho[MAX_JOGADORES];
    int pontosInsertion[MAX_JOGADORES];

    Jogador jogadoresOriginal[MAX_JOGADORES];
    Jogador jogadoresTrabalho[MAX_JOGADORES];
    Jogador jogadoresInsertion[MAX_JOGADORES];

    int i, opcao;
    int comparacoes, trocas, deslocamentos;

    jogadoresOriginal[0] = criarJogador(1, "Carlos", 75);
    jogadoresOriginal[1] = criarJogador(2, "Bia", 40);
    jogadoresOriginal[2] = criarJogador(3, "Ana", 90);
    jogadoresOriginal[3] = criarJogador(4, "Diego", 55);
    jogadoresOriginal[4] = criarJogador(5, "Kaue", 40);
    jogadoresOriginal[5] = criarJogador(6, "Daniel", 100);

    for (i = 0; i < MAX_JOGADORES; i++) {
        pontosTrabalho[i] = pontosOriginal[i];
        pontosInsertion[i] = pontosOriginal[i];

        jogadoresTrabalho[i] = jogadoresOriginal[i];
        jogadoresInsertion[i] = jogadoresOriginal[i];
    }

    do {
        printf("\n========== MENU ==========\n");
        printf("1 - Selection Sort\n");
        printf("2 - Insertion Sort\n");
        printf("0 - Sair\n");
        printf("==========================\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {

            case 1:
                printf("\n=== SELECTION SORT - PONTUACOES ===\n");

                comparacoes = 0;
                trocas = 0;

                imprimirPontuacoes(pontosTrabalho, MAX_JOGADORES);
                selectionSortNumeros(pontosTrabalho, MAX_JOGADORES, &comparacoes, &trocas);
                imprimirPontuacoes(pontosTrabalho, MAX_JOGADORES);

                printf("Comparacoes: %d | Trocas: %d\n", comparacoes, trocas);

                printf("\n=== SELECTION SORT - JOGADORES ===\n");

                comparacoes = 0;
                trocas = 0;

                selectionSortJogadores(jogadoresTrabalho, MAX_JOGADORES, &comparacoes, &trocas);
                imprimirJogadores(jogadoresTrabalho, MAX_JOGADORES);

                printf("Comparacoes: %d | Trocas: %d\n", comparacoes, trocas);

                break;

            case 2:
                printf("\n=== INSERTION SORT - PONTUACOES ===\n");

                comparacoes = 0;
                deslocamentos = 0;

                imprimirPontuacoes(pontosInsertion, MAX_JOGADORES);
                insertionSortNumeros(pontosInsertion, MAX_JOGADORES, &comparacoes, &deslocamentos);
                imprimirPontuacoes(pontosInsertion, MAX_JOGADORES);

                printf("Comparacoes: %d | Deslocamentos: %d\n", comparacoes, deslocamentos);

                printf("Vetor ordenado? ");
                mostrarValidacao(estaOrdenadoNumeros (pontosInsertion, MAX_JOGADORES));

                printf("\n=== INSERTION SORT - JOGADORES ===\n");

                comparacoes = 0;
                deslocamentos = 0;

                insertionSortJogadores(jogadoresInsertion, MAX_JOGADORES, &comparacoes, &deslocamentos);

                imprimirJogadores(jogadoresInsertion, MAX_JOGADORES);

                printf("Comparacoes: %d | Deslocamentos: %d\n", comparacoes, deslocamentos);

                printf("Jogadores ordenados? ");
                mostrarValidacao(estaOrdenadoJogadores (jogadoresInsertion, MAX_JOGADORES));

                break;

            case 0:
                printf("\nEncerrando o programa...\n");
                break;

            default:
                printf("\nOpcao invalida!\n");
        }

    } while (opcao != 0);

    return 0;
}