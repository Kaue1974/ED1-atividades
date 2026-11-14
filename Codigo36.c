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

/* ATIVIDADE 34 */

int jogadorAntesPorNome(Jogador a, Jogador b) {
    int cmp = strcmp(a.nome, b.nome);

    if (cmp != 0) {
        return cmp < 0;
    }

    return a.id < b.id;
}

void inserirJogadorPorNome(Jogador v[], int tamPrefixo, int *comparacoes, int *deslocamentos) {
    Jogador valor = v[tamPrefixo];
    int j = tamPrefixo - 1;

    while (j >= 0) {
        (*comparacoes)++;

        if (jogadorAntesPorNome(valor, v[j])) {
            v[j + 1] = v[j];
            (*deslocamentos)++;
            j--;
        } else {
            break;
        }
    }

    v[j + 1] = valor;
}

void insertionSortPorNome(Jogador v[], int n, int *comparacoes, int *deslocamentos) {
    int i;

    for (i = 1; i < n; i++) {
        inserirJogadorPorNome(v, i, comparacoes, deslocamentos);
    }
}

int estaOrdenadoPorNome(Jogador v[], int n) {
    int i;

    for (i = 1; i < n; i++) {
        if (jogadorAntesPorNome(v[i], v[i - 1])) {
            return 0;
        }
    }
    return 1;
}

int camposAssociados(Jogador original[], Jogador ordenado[], int n) {
    int i, k;

    for (i = 0; i < n; i++) {
        for (k = 0; k < n; k++) {
            if (original[k].id == ordenado[i].id) {
                if (strcmp(original[k].nome, ordenado[i].nome) != 0) {
                    return 0;
                }
                if (original[k].pontuacao != ordenado[i].pontuacao) {
                    return 0;
                }
            }
        }
    }
    return 1;
}

/* ATIVIDADE 35 */

void bubbleSortNumeros(int v[], int n, int *comparacoes, int *trocas, int *passagens) {
    int i, j, aux;
    int trocou;

    for (i = 0; i < n - 1; i++) {
        trocou = 0;
        (*passagens)++;

        for (j = 0; j < n - 1 - i; j++) {
            (*comparacoes)++;

            if (v[j] > v[j + 1]) {
                aux = v[j];
                v[j] = v[j + 1];
                v[j + 1] = aux;

                (*trocas)++;
                trocou = 1;
            }
        }

        if (trocou == 0) {
            break;
        }
    }
}

void copiarVetor(int origem[], int destino[], int n) {
    int i;

    for (i = 0; i < n; i++) {
        destino[i] = origem[i];
    }
}

void testarBubbleSort(char titulo[], int original[], int n) {
    int copia[MAX_JOGADORES];
    int comparacoes = 0;
    int trocas = 0;
    int passagens = 0;

    copiarVetor(original, copia, n);

    printf("--- %s ---\n", titulo);
    printf("Antes : ");
    imprimirPontuacoes(copia, n);

    bubbleSortNumeros(copia, n, &comparacoes, &trocas, &passagens);

    printf("Depois: ");
    imprimirPontuacoes(copia, n);
    printf("Passagens: %d | Comparacoes: %d | Trocas: %d\n", passagens, comparacoes, trocas);
    printf("Vetor ordenado? ");
    mostrarValidacao(estaOrdenadoNumeros(copia, n));
    printf("\n");
}

/* ATIVIDADE 36 */

typedef enum {
    CAMPO_ID,
    CAMPO_NOME,
    CAMPO_PONTUACAO
} Campo;

typedef enum {
    CRESCENTE,
    DECRESCENTE
} Direcao;

int compararJogadores(Jogador a, Jogador b, Campo campo) {
    switch (campo) {
        case CAMPO_ID:
            return a.id - b.id;
        case CAMPO_NOME:
            return strcmp(a.nome, b.nome);
        case CAMPO_PONTUACAO:
            return a.pontuacao - b.pontuacao;
    }
    return 0;
}

int deveTrocar(Jogador a, Jogador b, Campo campo, Direcao direcao) {
    int resultado = compararJogadores(a, b, campo);

    if (direcao == DECRESCENTE) {
        return resultado < 0;
    }
    return resultado > 0;
}

void bubbleSortJogadores(Jogador v[], int n, Campo campo, Direcao direcao,
                         int *comparacoes, int *trocas, int *passagens) {
    int i, j;
    int trocou;
    Jogador aux;

    for (i = 0; i < n - 1; i++) {
        trocou = 0;
        (*passagens)++;

        for (j = 0; j < n - 1 - i; j++) {
            (*comparacoes)++;

            if (deveTrocar(v[j], v[j + 1], campo, direcao)) {
                aux = v[j];
                v[j] = v[j + 1];
                v[j + 1] = aux;

                (*trocas)++;
                trocou = 1;
            }
        }

        if (trocou == 0) {
            break;
        }
    }
}

int estaOrdenadoPorCriterio(Jogador v[], int n, Campo campo, Direcao direcao) {
    int i;

    for (i = 1; i < n; i++) {
        if (deveTrocar(v[i - 1], v[i], campo, direcao)) {
            return 0;
        }
    }
    return 1;
}

void imprimirCriterio(Campo campo, Direcao direcao) {
    printf("Campo selecionado  : ");
    if (campo == CAMPO_ID) {
        printf("ID\n");
    } else if (campo == CAMPO_NOME) {
        printf("NOME\n");
    } else {
        printf("PONTUACAO\n");
    }

    printf("Direcao selecionada: ");
    if (direcao == CRESCENTE) {
        printf("CRESCENTE\n");
    } else {
        printf("DECRESCENTE\n");
    }
}

void testarBubbleJogadores(char titulo[], Jogador original[], int n, Campo campo, Direcao direcao) {
    Jogador copia[MAX_JOGADORES];
    int i;
    int comparacoes = 0;
    int trocas = 0;
    int passagens = 0;

    for (i = 0; i < n; i++) {
        copia[i] = original[i];
    }

    printf("--- %s ---\n", titulo);
    imprimirCriterio(campo, direcao);
    printf("Antes:\n");
    imprimirJogadores(copia, n);

    bubbleSortJogadores(copia, n, campo, direcao, &comparacoes, &trocas, &passagens);

    printf("\nDepois:\n");
    imprimirJogadores(copia, n);
    printf("Passagens: %d | Comparacoes: %d | Trocas: %d\n", passagens, comparacoes, trocas);
    printf("Ordem final correta? ");
    mostrarValidacao(estaOrdenadoPorCriterio(copia, n, campo, direcao));
    printf("Campos continuam associados? ");
    mostrarValidacao(camposAssociados(original, copia, n));
    printf("\n");
}

int main() {
    int pontosOriginal[MAX_JOGADORES] = {75, 40, 90, 55, 40, 100};
    int pontosTrabalho[MAX_JOGADORES];
    int pontosInsertion[MAX_JOGADORES];

    int entradaOrdenada[MAX_JOGADORES] = {30, 40, 55, 75, 90, 100};
    int entradaInversa[MAX_JOGADORES] = {100, 90, 75, 55, 40, 30};

    Jogador jogadoresOriginal[MAX_JOGADORES];
    Jogador jogadoresTrabalho[MAX_JOGADORES];
    Jogador jogadoresInsertion[MAX_JOGADORES];
    Jogador catalogoOriginal[MAX_JOGADORES];
    Jogador catalogoTrabalho[MAX_JOGADORES];

    int i, opcao;
    int comparacoes, trocas, deslocamentos;

    jogadoresOriginal[0] = criarJogador(1, "Carlos", 75);
    jogadoresOriginal[1] = criarJogador(2, "Bia", 40);
    jogadoresOriginal[2] = criarJogador(3, "Ana", 90);
    jogadoresOriginal[3] = criarJogador(4, "Diego", 55);
    jogadoresOriginal[4] = criarJogador(5, "Kaue", 40);
    jogadoresOriginal[5] = criarJogador(6, "Daniel", 100);

    catalogoOriginal[0] = criarJogador(5, "Ana", 40);
    catalogoOriginal[1] = criarJogador(2, "Bia", 40);
    catalogoOriginal[2] = criarJogador(3, "Ana", 90);
    catalogoOriginal[3] = criarJogador(4, "Bia", 55);
    catalogoOriginal[4] = criarJogador(1, "Carlos", 75);
    catalogoOriginal[5] = criarJogador(6, "Daniel", 100);

    for (i = 0; i < MAX_JOGADORES; i++) {
        pontosTrabalho[i] = pontosOriginal[i];
        pontosInsertion[i] = pontosOriginal[i];

        jogadoresTrabalho[i] = jogadoresOriginal[i];
        jogadoresInsertion[i] = jogadoresOriginal[i];

        catalogoTrabalho[i] = catalogoOriginal[i];
    }

    do {
        printf("\n========== MENU ==========\n");
        printf("1 - Selection Sort\n");
        printf("2 - Insertion Sort\n");
        printf("3 - Insertion Sort por Nome\n");
        printf("4 - Bubble Sort\n");
        printf("5 - Bubble Sort de Jogadores\n");
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

            case 3:
                comparacoes = 0;
                deslocamentos = 0;

                printf("\n=== INSERTION SORT POR NOME ===\n");

                printf("Antes:\n");
                imprimirJogadores(catalogoTrabalho, MAX_JOGADORES);

                insertionSortPorNome(catalogoTrabalho, MAX_JOGADORES, &comparacoes, &deslocamentos);

                printf("\nDepois (por nome, desempate por ID):\n");
                imprimirJogadores(catalogoTrabalho, MAX_JOGADORES);

                printf("Comparacoes: %d | Deslocamentos: %d\n", comparacoes, deslocamentos);

                printf("Catalogo ordenado por nome? ");
                mostrarValidacao(estaOrdenadoPorNome (catalogoTrabalho, MAX_JOGADORES));

                printf("ID, nome e pontuacao continuam associados? ");
                mostrarValidacao(camposAssociados (catalogoOriginal, catalogoTrabalho, MAX_JOGADORES));

                break;

            case 4:
                printf("\n=== BUBBLE SORT COM PARADA ANTECIPADA ===\n");

                testarBubbleSort("Entrada ja ordenada", entradaOrdenada, MAX_JOGADORES);
                testarBubbleSort("Entrada em ordem inversa", entradaInversa, MAX_JOGADORES);
                testarBubbleSort("Entrada aleatoria", pontosOriginal, MAX_JOGADORES);

                break;

            case 5:
                printf("\n=== BUBBLE SORT DE JOGADORES ===\n");

                testarBubbleJogadores("Catalogo por ID crescente", catalogoOriginal, MAX_JOGADORES, CAMPO_ID, CRESCENTE);
                testarBubbleJogadores("Catalogo por ID decrescente", catalogoOriginal, MAX_JOGADORES, CAMPO_ID, DECRESCENTE);
                testarBubbleJogadores("Entrada ja ordenada por ID", jogadoresOriginal, MAX_JOGADORES, CAMPO_ID, CRESCENTE);

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