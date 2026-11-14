#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

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

/* ATIVIDADE 37 */

int intercalar(int a[], int na, int b[], int nb, int saida[], int *comparacoes) {
    int i = 0;
    int j = 0;
    int k = 0;

    while (i < na && j < nb) {
        (*comparacoes)++;

        if (a[i] <= b[j]) {
            saida[k] = a[i];
            i++;
        } else {
            saida[k] = b[j];
            j++;
        }
        k++;
    }

    while (i < na) {
        saida[k] = a[i];
        i++;
        k++;
    }

    while (j < nb) {
        saida[k] = b[j];
        j++;
        k++;
    }

    return k;
}

int somaVetor(int v[], int n) {
    int i;
    int soma = 0;

    for (i = 0; i < n; i++) {
        soma = soma + v[i];
    }
    return soma;
}

void testarIntercalacao(char titulo[], int a[], int na, int b[], int nb) {
    int saida[MAX_JOGADORES];
    int comparacoes = 0;
    int total;
    int somaEntradas;

    printf("--- %s ---\n", titulo);
    printf("Vetor A: ");
    imprimirPontuacoes(a, na);
    printf("Vetor B: ");
    imprimirPontuacoes(b, nb);

    total = intercalar(a, na, b, nb, saida, &comparacoes);

    printf("Saida  : ");
    imprimirPontuacoes(saida, total);
    printf("Comparacoes: %d | Elementos na saida: %d\n", comparacoes, total);

    somaEntradas = somaVetor(a, na) + somaVetor(b, nb);

    printf("Saida ordenada? ");
    mostrarValidacao(estaOrdenadoNumeros(saida, total));
    printf("Todos os valores presentes? ");
    mostrarValidacao(total == na + nb && somaVetor(saida, total) == somaEntradas);
    printf("\n");
}

void imprimirIntervalo(int v[], int inicio, int fim) {
    int k;

    printf("[%d..%d] ", inicio, fim);
    for (k = inicio; k <= fim; k++) {
        printf("%d ", v[k]);
    }
}

void dividirIntervalo(int v[], int inicio, int fim, int nivel, int *divisoes) {
    int meio;
    int i;

    for (i = 0; i < nivel; i++) {
        printf("    ");
    }
    imprimirIntervalo(v, inicio, fim);

    /* RESOLVER: intervalo com um elemento ja esta ordenado (caso base) */
    if (inicio >= fim) {
        printf("| caso base\n");
        return;
    }

    /* DIVIDIR: calcula o ponto medio e separa em duas metades */
    meio = inicio + (fim - inicio) / 2;
    (*divisoes)++;
    printf("| meio = %d\n", meio);

    dividirIntervalo(v, inicio, meio, nivel + 1, divisoes);
    dividirIntervalo(v, meio + 1, fim, nivel + 1, divisoes);
}

/* ATIVIDADE 38 */

void mergeSortRecursivo(int v[], int inicio, int fim, int aux[], int *comparacoes) {
    int meio, tamanho, k;

    if (inicio >= fim) {
        return;
    }

    meio = inicio + (fim - inicio) / 2;

    mergeSortRecursivo(v, inicio, meio, aux, comparacoes);
    mergeSortRecursivo(v, meio + 1, fim, aux, comparacoes);

    tamanho = intercalar(&v[inicio], meio - inicio + 1, &v[meio + 1], fim - meio, aux, comparacoes);

    for (k = 0; k < tamanho; k++) {
        v[inicio + k] = aux[k];
    }
}

int mergeSortNumeros(int v[], int n, int *comparacoes) {
    int *aux;

    if (n <= 1) {
        return 1;
    }

    aux = (int *) malloc(n * sizeof(int));
    if (aux == NULL) {
        return 0;
    }

    mergeSortRecursivo(v, 0, n - 1, aux, comparacoes);

    free(aux);
    return 1;
}

void intercalarJogadores(Jogador v[], int inicio, int meio, int fim, Jogador aux[],
                         Campo campo, Direcao direcao, int *comparacoes) {
    int i = inicio;
    int j = meio + 1;
    int k = 0;

    while (i <= meio && j <= fim) {
        (*comparacoes)++;

        if (deveTrocar(v[i], v[j], campo, direcao)) {
            aux[k] = v[j];
            j++;
        } else {
            aux[k] = v[i];
            i++;
        }
        k++;
    }

    while (i <= meio) {
        aux[k] = v[i];
        i++;
        k++;
    }

    while (j <= fim) {
        aux[k] = v[j];
        j++;
        k++;
    }

    for (i = 0; i < k; i++) {
        v[inicio + i] = aux[i];
    }
}

void mergeSortJogadoresRecursivo(Jogador v[], int inicio, int fim, Jogador aux[],
                                 Campo campo, Direcao direcao, int *comparacoes) {
    int meio;

    if (inicio >= fim) {
        return;
    }

    meio = inicio + (fim - inicio) / 2;

    mergeSortJogadoresRecursivo(v, inicio, meio, aux, campo, direcao, comparacoes);
    mergeSortJogadoresRecursivo(v, meio + 1, fim, aux, campo, direcao, comparacoes);

    intercalarJogadores(v, inicio, meio, fim, aux, campo, direcao, comparacoes);
}

int mergeSortJogadores(Jogador v[], int n, Campo campo, Direcao direcao, int *comparacoes) {
    Jogador *aux;

    if (n <= 1) {
        return 1;
    }

    aux = (Jogador *) malloc(n * sizeof(Jogador));
    if (aux == NULL) {
        return 0;
    }

    mergeSortJogadoresRecursivo(v, 0, n - 1, aux, campo, direcao, comparacoes);

    free(aux);
    return 1;
}

int todosPresentes(Jogador original[], Jogador ordenado[], int n) {
    int i, k;
    int achou;

    for (i = 0; i < n; i++) {
        achou = 0;
        for (k = 0; k < n; k++) {
            if (ordenado[k].id == original[i].id) {
                achou = 1;
            }
        }
        if (!achou) {
            return 0;
        }
    }
    return 1;
}

void testarMergeNumeros(char titulo[], int original[], int n) {
    int copia[MAX_JOGADORES];
    int referencia[MAX_JOGADORES];
    int comparacoes = 0;
    int compSelection = 0;
    int trocasSelection = 0;

    copiarVetor(original, copia, n);
    copiarVetor(original, referencia, n);

    printf("--- %s ---\n", titulo);
    printf("Antes : ");
    imprimirPontuacoes(copia, n);

    if (!mergeSortNumeros(copia, n, &comparacoes)) {
        printf("Erro de memoria\n\n");
        return;
    }

    selectionSortNumeros(referencia, n, &compSelection, &trocasSelection);

    printf("Depois: ");
    imprimirPontuacoes(copia, n);
    printf("Comparacoes (Merge Sort): %d | Comparacoes (Selection Sort): %d\n", comparacoes, compSelection);
    printf("Vetor ordenado? ");
    mostrarValidacao(estaOrdenadoNumeros(copia, n));
    printf("Igual ao Selection Sort (repetidos preservados)? ");
    mostrarValidacao(vetoresIguais(copia, referencia, n));
    printf("Soma igual a da entrada? ");
    mostrarValidacao(somaVetor(copia, n) == somaVetor(original, n));
    printf("\n");
}

void testarMergeJogadores(char titulo[], Jogador original[], int n, Campo campo, Direcao direcao) {
    Jogador copia[MAX_JOGADORES];
    int i;
    int comparacoes = 0;

    for (i = 0; i < n; i++) {
        copia[i] = original[i];
    }

    printf("--- %s ---\n", titulo);
    imprimirCriterio(campo, direcao);
    printf("Antes:\n");
    imprimirJogadores(copia, n);

    if (!mergeSortJogadores(copia, n, campo, direcao, &comparacoes)) {
        printf("Erro de memoria\n\n");
        return;
    }

    printf("\nDepois:\n");
    imprimirJogadores(copia, n);
    printf("Comparacoes: %d\n", comparacoes);
    printf("Ordem final correta? ");
    mostrarValidacao(estaOrdenadoPorCriterio(copia, n, campo, direcao));
    printf("Campos continuam associados? ");
    mostrarValidacao(camposAssociados(original, copia, n));
    printf("Todos os jogadores da entrada presentes? ");
    mostrarValidacao(todosPresentes(original, copia, n));
    printf("\n");
}

/* ATIVIDADE 39 */

int particaoAuxiliar(int v[], int n, int saida[], int *comparacoes) {
    int pivo = v[n - 1];
    int esq = 0;
    int dir = n - 1;
    int i;

    for (i = 0; i < n - 1; i++) {
        (*comparacoes)++;

        if (v[i] < pivo) {
            saida[esq] = v[i];
            esq++;
        } else {
            saida[dir] = v[i];
            dir--;
        }
    }

    saida[esq] = pivo;

    return esq;
}

int particaoInPlace(int v[], int inicio, int fim, int *comparacoes, int *trocas) {
    int pivo = v[fim];
    int menor = inicio;
    int j, aux;

    for (j = inicio; j < fim; j++) {
        (*comparacoes)++;

        if (v[j] < pivo) {
            if (j != menor) {
                aux = v[j];
                v[j] = v[menor];
                v[menor] = aux;
                (*trocas)++;
            }
            menor++;
        }
    }

    if (menor != fim) {
        aux = v[menor];
        v[menor] = v[fim];
        v[fim] = aux;
        (*trocas)++;
    }

    return menor;
}

void quickSortRecursivo(int v[], int inicio, int fim, int *comparacoes, int *trocas) {
    int posPivo;

    if (inicio >= fim) {
        return;
    }

    posPivo = particaoInPlace(v, inicio, fim, comparacoes, trocas);

    if (posPivo - 1 > inicio) {
        quickSortRecursivo(v, inicio, posPivo - 1, comparacoes, trocas);
    }

    if (posPivo + 1 < fim) {
        quickSortRecursivo(v, posPivo + 1, fim, comparacoes, trocas);
    }
}

int particaoValida(int v[], int n, int posPivo) {
    int i;

    for (i = 0; i < posPivo; i++) {
        if (v[i] >= v[posPivo]) {
            return 0;
        }
    }

    for (i = posPivo + 1; i < n; i++) {
        if (v[i] < v[posPivo]) {
            return 0;
        }
    }

    return 1;
}

void testarParticoes(char titulo[], int original[], int n) {
    int saida[MAX_JOGADORES];
    int copia[MAX_JOGADORES];
    int comparacoes = 0;
    int trocas = 0;
    int posPivo;

    copiarVetor(original, copia, n);

    printf("--- %s ---\n", titulo);
    printf("Entrada: ");
    imprimirPontuacoes(copia, n);
    printf("Pivo (ultimo elemento): %d\n", copia[n - 1]);

    posPivo = particaoAuxiliar(original, n, saida, &comparacoes);

    printf("Particao auxiliar: ");
    imprimirPontuacoes(saida, n);
    printf("Posicao final do pivo: %d | Comparacoes: %d\n", posPivo, comparacoes);
    printf("Particao valida? ");
    mostrarValidacao(particaoValida(saida, n, posPivo));
    printf("Mesmos elementos (soma)? ");
    mostrarValidacao(somaVetor(saida, n) == somaVetor(original, n));

    comparacoes = 0;
    posPivo = particaoInPlace(copia, 0, n - 1, &comparacoes, &trocas);

    printf("Particao in-place: ");
    imprimirPontuacoes(copia, n);
    printf("Posicao final do pivo: %d | Comparacoes: %d | Trocas: %d\n", posPivo, comparacoes, trocas);
    printf("Particao valida? ");
    mostrarValidacao(particaoValida(copia, n, posPivo));
    printf("Mesmos elementos (soma)? ");
    mostrarValidacao(somaVetor(copia, n) == somaVetor(original, n));
    printf("\n");
}

void testarQuickSort(char titulo[], int original[], int n) {
    int copia[MAX_JOGADORES];
    int referencia[MAX_JOGADORES];
    int comparacoes = 0;
    int trocas = 0;
    int compSelection = 0;
    int trocasSelection = 0;

    copiarVetor(original, copia, n);
    copiarVetor(original, referencia, n);

    printf("--- %s ---\n", titulo);
    printf("Antes : ");
    imprimirPontuacoes(copia, n);

    quickSortRecursivo(copia, 0, n - 1, &comparacoes, &trocas);
    selectionSortNumeros(referencia, n, &compSelection, &trocasSelection);

    printf("Depois: ");
    imprimirPontuacoes(copia, n);
    printf("Comparacoes: %d | Trocas: %d\n", comparacoes, trocas);
    printf("Vetor ordenado? ");
    mostrarValidacao(estaOrdenadoNumeros(copia, n));
    printf("Igual ao Selection Sort (repetidos preservados)? ");
    mostrarValidacao(vetoresIguais(copia, referencia, n));
    printf("Soma igual a da entrada? ");
    mostrarValidacao(somaVetor(copia, n) == somaVetor(original, n));
    printf("\n");
}

/* ATIVIDADE 40 */

typedef enum {
    ALG_SELECTION,
    ALG_INSERTION,
    ALG_BUBBLE,
    ALG_MERGE,
    ALG_QUICK,
    TOTAL_ALGORITMOS
} Algoritmo;

void moverPivoAleatorioParaFim(int v[], int inicio, int fim, int *trocas) {
    int pos = inicio + rand() % (fim - inicio + 1);
    int aux;

    if (pos != fim) {
        aux = v[pos];
        v[pos] = v[fim];
        v[fim] = aux;
        (*trocas)++;
    }
}

void quickSortAleatorio(int v[], int inicio, int fim, int *comparacoes, int *trocas) {
    int posPivo;

    if (inicio >= fim) {
        return;
    }

    moverPivoAleatorioParaFim(v, inicio, fim, trocas);
    posPivo = particaoInPlace(v, inicio, fim, comparacoes, trocas);

    if (posPivo - 1 > inicio) {
        quickSortAleatorio(v, inicio, posPivo - 1, comparacoes, trocas);
    }

    if (posPivo + 1 < fim) {
        quickSortAleatorio(v, posPivo + 1, fim, comparacoes, trocas);
    }
}

int particaoJogadores(Jogador v[], int inicio, int fim, int *comparacoes, int *trocas) {
    Jogador pivo = v[fim];
    Jogador aux;
    int menor = inicio;
    int j;

    for (j = inicio; j < fim; j++) {
        (*comparacoes)++;

        if (jogadorMenor(v[j], pivo)) {
            if (j != menor) {
                aux = v[j];
                v[j] = v[menor];
                v[menor] = aux;
                (*trocas)++;
            }
            menor++;
        }
    }

    if (menor != fim) {
        aux = v[menor];
        v[menor] = v[fim];
        v[fim] = aux;
        (*trocas)++;
    }

    return menor;
}

void quickSortJogadoresAleatorio(Jogador v[], int inicio, int fim, int *comparacoes, int *trocas) {
    int pos, posPivo;
    Jogador aux;

    if (inicio >= fim) {
        return;
    }

    pos = inicio + rand() % (fim - inicio + 1);

    if (pos != fim) {
        aux = v[pos];
        v[pos] = v[fim];
        v[fim] = aux;
        (*trocas)++;
    }

    posPivo = particaoJogadores(v, inicio, fim, comparacoes, trocas);

    if (posPivo - 1 > inicio) {
        quickSortJogadoresAleatorio(v, inicio, posPivo - 1, comparacoes, trocas);
    }

    if (posPivo + 1 < fim) {
        quickSortJogadoresAleatorio(v, posPivo + 1, fim, comparacoes, trocas);
    }
}

void bubbleSortCriterio(Jogador v[], int n, int *comparacoes, int *trocas) {
    int i, j;
    int trocou;
    Jogador aux;

    for (i = 0; i < n - 1; i++) {
        trocou = 0;

        for (j = 0; j < n - 1 - i; j++) {
            (*comparacoes)++;

            if (jogadorMenor(v[j + 1], v[j])) {
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

void intercalarCriterio(Jogador v[], int inicio, int meio, int fim, Jogador aux[], int *comparacoes) {
    int i = inicio;
    int j = meio + 1;
    int k = 0;

    while (i <= meio && j <= fim) {
        (*comparacoes)++;

        if (jogadorMenor(v[j], v[i])) {
            aux[k] = v[j];
            j++;
        } else {
            aux[k] = v[i];
            i++;
        }
        k++;
    }

    while (i <= meio) {
        aux[k] = v[i];
        i++;
        k++;
    }

    while (j <= fim) {
        aux[k] = v[j];
        j++;
        k++;
    }

    for (i = 0; i < k; i++) {
        v[inicio + i] = aux[i];
    }
}

void mergeSortCriterioRecursivo(Jogador v[], int inicio, int fim, Jogador aux[], int *comparacoes) {
    int meio;

    if (inicio >= fim) {
        return;
    }

    meio = inicio + (fim - inicio) / 2;

    mergeSortCriterioRecursivo(v, inicio, meio, aux, comparacoes);
    mergeSortCriterioRecursivo(v, meio + 1, fim, aux, comparacoes);

    intercalarCriterio(v, inicio, meio, fim, aux, comparacoes);
}

int mergeSortCriterio(Jogador v[], int n, int *comparacoes) {
    Jogador *aux;

    if (n <= 1) {
        return 1;
    }

    aux = (Jogador *) malloc(n * sizeof(Jogador));
    if (aux == NULL) {
        return 0;
    }

    mergeSortCriterioRecursivo(v, 0, n - 1, aux, comparacoes);

    free(aux);
    return 1;
}

void copiarJogadores(Jogador origem[], Jogador destino[], int n) {
    int i;

    for (i = 0; i < n; i++) {
        destino[i] = origem[i];
    }
}

void testarQuickAleatorioNumeros(char titulo[], int original[], int n) {
    int copia[MAX_JOGADORES];
    int fixo[MAX_JOGADORES];
    int referencia[MAX_JOGADORES];
    int compAleatorio = 0;
    int trocasAleatorio = 0;
    int compFixo = 0;
    int trocasFixo = 0;
    int compSelection = 0;
    int trocasSelection = 0;

    copiarVetor(original, copia, n);
    copiarVetor(original, fixo, n);
    copiarVetor(original, referencia, n);

    printf("--- %s ---\n", titulo);
    printf("Antes : ");
    imprimirPontuacoes(copia, n);

    quickSortAleatorio(copia, 0, n - 1, &compAleatorio, &trocasAleatorio);
    quickSortRecursivo(fixo, 0, n - 1, &compFixo, &trocasFixo);
    selectionSortNumeros(referencia, n, &compSelection, &trocasSelection);

    printf("Depois: ");
    imprimirPontuacoes(copia, n);
    printf("Pivo aleatorio: Comparacoes: %d | Trocas: %d\n", compAleatorio, trocasAleatorio);
    printf("Pivo fixo     : Comparacoes: %d | Trocas: %d\n", compFixo, trocasFixo);
    printf("Vetor ordenado? ");
    mostrarValidacao(estaOrdenadoNumeros(copia, n));
    printf("Igual ao Selection Sort (repetidos preservados)? ");
    mostrarValidacao(vetoresIguais(copia, referencia, n));
    printf("Soma igual a da entrada? ");
    mostrarValidacao(somaVetor(copia, n) == somaVetor(original, n));
    printf("\n");
}

void testarQuickJogadores(char titulo[], Jogador original[], int n) {
    Jogador copia[MAX_JOGADORES];
    Jogador referencia[MAX_JOGADORES];
    int comparacoes = 0;
    int trocas = 0;
    int compSelection = 0;
    int trocasSelection = 0;

    copiarJogadores(original, copia, n);
    copiarJogadores(original, referencia, n);

    printf("--- %s ---\n", titulo);
    printf("Antes:\n");
    imprimirJogadores(copia, n);

    quickSortJogadoresAleatorio(copia, 0, n - 1, &comparacoes, &trocas);
    selectionSortJogadores(referencia, n, &compSelection, &trocasSelection);

    printf("\nDepois (por pontuacao, desempate por nome e ID):\n");
    imprimirJogadores(copia, n);
    printf("Comparacoes: %d | Trocas: %d\n", comparacoes, trocas);
    printf("Jogadores ordenados? ");
    mostrarValidacao(estaOrdenadoJogadores(copia, n));
    printf("Igual ao resultado do Selection Sort? ");
    mostrarValidacao(jogadoresIguais(copia, referencia, n));
    printf("Campos continuam associados? ");
    mostrarValidacao(camposAssociados(original, copia, n));
    printf("Todos os jogadores presentes? ");
    mostrarValidacao(todosPresentes(original, copia, n));
    printf("\n");
}

int executarNumeros(int alg, int v[], int n, int *comparacoes, int *trocas, int *deslocamentos) {
    int passagens = 0;

    switch (alg) {
        case ALG_SELECTION:
            selectionSortNumeros(v, n, comparacoes, trocas);
            break;
        case ALG_INSERTION:
            insertionSortNumeros(v, n, comparacoes, deslocamentos);
            break;
        case ALG_BUBBLE:
            bubbleSortNumeros(v, n, comparacoes, trocas, &passagens);
            break;
        case ALG_MERGE:
            return mergeSortNumeros(v, n, comparacoes);
        case ALG_QUICK:
            quickSortAleatorio(v, 0, n - 1, comparacoes, trocas);
            break;
    }

    return 1;
}

int executarJogadores(int alg, Jogador v[], int n, int *comparacoes, int *trocas, int *deslocamentos) {
    switch (alg) {
        case ALG_SELECTION:
            selectionSortJogadores(v, n, comparacoes, trocas);
            break;
        case ALG_INSERTION:
            insertionSortJogadores(v, n, comparacoes, deslocamentos);
            break;
        case ALG_BUBBLE:
            bubbleSortCriterio(v, n, comparacoes, trocas);
            break;
        case ALG_MERGE:
            return mergeSortCriterio(v, n, comparacoes);
        case ALG_QUICK:
            quickSortJogadoresAleatorio(v, 0, n - 1, comparacoes, trocas);
            break;
    }

    return 1;
}

void imprimirNomeAlgoritmo(int alg) {
    switch (alg) {
        case ALG_SELECTION:
            printf("%-22s", "Selection Sort");
            break;
        case ALG_INSERTION:
            printf("%-22s", "Insertion Sort");
            break;
        case ALG_BUBBLE:
            printf("%-22s", "Bubble Sort");
            break;
        case ALG_MERGE:
            printf("%-22s", "Merge Sort");
            break;
        case ALG_QUICK:
            printf("%-22s", "Quick (pivo aleatorio)");
            break;
    }
}

void imprimirCabecalhoRelatorio() {
    printf("%-22s| %12s | %7s | %13s | Resultado\n", "Algoritmo", "Comparacoes", "Trocas", "Deslocamentos");
    printf("----------------------+--------------+---------+---------------+----------\n");
}

void imprimirLinhaRelatorio(int alg, int comparacoes, int trocas, int deslocamentos, int ok) {
    imprimirNomeAlgoritmo(alg);
    printf("| %12d | %7d | %13d | ", comparacoes, trocas, deslocamentos);
    mostrarValidacao(ok);
}

void relatorioNumeros(int original[], int n) {
    int copia[MAX_JOGADORES];
    int referencia[MAX_JOGADORES];
    int comparacoes, trocas, deslocamentos;
    int alg, ok;

    printf("PONTUACOES (ordem crescente)\n");
    printf("Entrada: ");
    imprimirPontuacoes(original, n);
    imprimirCabecalhoRelatorio();

    for (alg = 0; alg < TOTAL_ALGORITMOS; alg++) {
        copiarVetor(original, copia, n);
        comparacoes = 0;
        trocas = 0;
        deslocamentos = 0;

        ok = executarNumeros(alg, copia, n, &comparacoes, &trocas, &deslocamentos);

        if (ok) {
            if (alg == ALG_SELECTION) {
                copiarVetor(copia, referencia, n);
            }
            ok = estaOrdenadoNumeros(copia, n) && vetoresIguais(copia, referencia, n);
        }

        imprimirLinhaRelatorio(alg, comparacoes, trocas, deslocamentos, ok);
    }
    printf("\n");
}

void relatorioJogadores(char titulo[], Jogador original[], int n) {
    Jogador copia[MAX_JOGADORES];
    Jogador referencia[MAX_JOGADORES];
    int comparacoes, trocas, deslocamentos;
    int alg, ok;

    printf("JOGADORES - %s (pontuacao, desempate por nome e ID)\n", titulo);
    imprimirCabecalhoRelatorio();

    for (alg = 0; alg < TOTAL_ALGORITMOS; alg++) {
        copiarJogadores(original, copia, n);
        comparacoes = 0;
        trocas = 0;
        deslocamentos = 0;

        ok = executarJogadores(alg, copia, n, &comparacoes, &trocas, &deslocamentos);

        if (ok) {
            if (alg == ALG_SELECTION) {
                copiarJogadores(copia, referencia, n);
            }
            ok = estaOrdenadoJogadores(copia, n)
                 && jogadoresIguais(copia, referencia, n)
                 && camposAssociados(original, copia, n);
        }

        imprimirLinhaRelatorio(alg, comparacoes, trocas, deslocamentos, ok);
    }
    printf("\n");
}

int main() {
    int pontosOriginal[MAX_JOGADORES] = {75, 40, 90, 55, 40, 100};
    int pontosTrabalho[MAX_JOGADORES];
    int pontosInsertion[MAX_JOGADORES];

    int entradaOrdenada[MAX_JOGADORES] = {30, 40, 55, 75, 90, 100};
    int entradaInversa[MAX_JOGADORES] = {100, 90, 75, 55, 40, 30};

    int entradaPivoMeio[MAX_JOGADORES] = {75, 40, 90, 55, 40, 60};
    int entradaRepetidos[MAX_JOGADORES] = {50, 20, 50, 20, 50, 20};
    int entradaIguais[MAX_JOGADORES] = {40, 40, 40, 40, 40, 40};

    int mergeA1[4] = {40, 55, 75, 90};
    int mergeB1[2] = {30, 100};
    int mergeA2[3] = {30, 40, 55};
    int mergeB2[3] = {75, 90, 100};

    int unico[1] = {42};

    Jogador jogadoresOriginal[MAX_JOGADORES];
    Jogador jogadoresTrabalho[MAX_JOGADORES];
    Jogador jogadoresInsertion[MAX_JOGADORES];
    Jogador catalogoOriginal[MAX_JOGADORES];
    Jogador catalogoTrabalho[MAX_JOGADORES];

    int i, opcao;
    int comparacoes, trocas, deslocamentos;
    int divisoes;

    srand((unsigned) time(NULL));

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
        printf("6 - Intercalacao e Divisao e Conquista\n");
        printf("7 - Merge Sort\n");
        printf("8 - Quick Sort e Particionamento\n");
        printf("9 - Quick Sort com Pivo Aleatorio\n");
        printf("10 - Relatorio Comparativo Final\n");
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

            case 6:
                printf("\n=== INTERCALACAO ===\n");

                testarIntercalacao("Sobra no vetor B", mergeA1, 4, mergeB1, 2);
                testarIntercalacao("A termina primeiro", mergeA2, 3, mergeB2, 3);

                printf("\n=== DIVISAO E CONQUISTA - DIVISAO DO INTERVALO ===\n");

                divisoes = 0;

                dividirIntervalo(pontosOriginal, 0, MAX_JOGADORES - 1, 0, &divisoes);

                printf("Divisoes realizadas: %d\n", divisoes);

                break;

            case 7:
                printf("\n=== MERGE SORT DE NUMEROS ===\n");

                testarMergeNumeros("Entrada aleatoria (com repetidos)", pontosOriginal, MAX_JOGADORES);
                testarMergeNumeros("Entrada em ordem inversa", entradaInversa, MAX_JOGADORES);
                testarMergeNumeros("Entrada ja ordenada", entradaOrdenada, MAX_JOGADORES);

                printf("\n--- CASOS BASE ---\n");

                comparacoes = 0;

                mergeSortNumeros(unico, 0, &comparacoes);
                mergeSortNumeros(unico, 1, &comparacoes);

                printf("Vetor com 0 e com 1 elemento: ");
                imprimirPontuacoes(unico, 1);

                printf("Comparacoes: %d\n", comparacoes);

                printf("\n=== MERGE SORT DE JOGADORES ===\n");

                testarMergeJogadores("Jogadores por pontuacao crescente", jogadoresOriginal, MAX_JOGADORES, CAMPO_PONTUACAO, CRESCENTE);
                testarMergeJogadores("Catalogo por nome crescente", catalogoOriginal, MAX_JOGADORES, CAMPO_NOME, CRESCENTE);
                testarMergeJogadores("Catalogo por pontuacao decrescente", catalogoOriginal, MAX_JOGADORES, CAMPO_PONTUACAO, DECRESCENTE);

                break;

            case 8:
                printf("\n=== PARTICAO EM TORNO DO PIVO ===\n");

                testarParticoes("Pivo no meio dos valores", entradaPivoMeio, MAX_JOGADORES);
                testarParticoes("Valores repetidos", entradaRepetidos, MAX_JOGADORES);
                testarParticoes("Todos os valores iguais", entradaIguais, MAX_JOGADORES);

                printf("\n=== QUICK SORT (PARTICAO IN-PLACE) ===\n");

                testarQuickSort("Entrada aleatoria (com repetidos)", pontosOriginal, MAX_JOGADORES);
                testarQuickSort("Valores repetidos", entradaRepetidos, MAX_JOGADORES);
                testarQuickSort("Todos os valores iguais", entradaIguais, MAX_JOGADORES);
                testarQuickSort("Entrada em ordem inversa", entradaInversa, MAX_JOGADORES);
                testarQuickSort("Entrada ja ordenada", entradaOrdenada, MAX_JOGADORES);

                break;

            case 9:
                printf("\n=== QUICK SORT COM PIVO ALEATORIO - NUMEROS ===\n");

                testarQuickAleatorioNumeros("Entrada aleatoria (com repetidos)", pontosOriginal, MAX_JOGADORES);
                testarQuickAleatorioNumeros("Valores repetidos", entradaRepetidos, MAX_JOGADORES);
                testarQuickAleatorioNumeros("Todos os valores iguais", entradaIguais, MAX_JOGADORES);
                testarQuickAleatorioNumeros("Entrada em ordem inversa", entradaInversa, MAX_JOGADORES);
                testarQuickAleatorioNumeros("Entrada ja ordenada", entradaOrdenada, MAX_JOGADORES);

                printf("\n=== QUICK SORT COM PIVO ALEATORIO - JOGADORES ===\n");

                testarQuickJogadores("Jogadores da central", jogadoresOriginal, MAX_JOGADORES);
                testarQuickJogadores("Catalogo com nomes repetidos", catalogoOriginal, MAX_JOGADORES);

                break;

            case 10:
                printf("\n=== RELATORIO COMPARATIVO FINAL ===\n\n");

                relatorioNumeros(pontosOriginal, MAX_JOGADORES);
                relatorioJogadores("Jogadores da central", jogadoresOriginal, MAX_JOGADORES);
                relatorioJogadores("Catalogo com nomes repetidos", catalogoOriginal, MAX_JOGADORES);

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