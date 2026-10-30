#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int buscaLinear(int *vetor, int tamanho, int alvo, int *contadorOperacoes) {
    *contadorOperacoes = 0;
    
    for (int i = 0; i < tamanho; i++) {
        (*contadorOperacoes)++; // 
       
        if (vetor[i] == alvo) {
            return i; 
        }
    }

    return -1;
}

int buscaBinaria(int *vetor, int tamanho, int alvo, int *contadorOperacoes) {
    int inicio = 0;
    int fim = tamanho - 1;
    *contadorOperacoes = 0;

    while (inicio <= fim) {
        
        (*contadorOperacoes)++;
        int meio = inicio + (fim - inicio) / 2;

        if (vetor[meio] == alvo) return meio;
        
        if (vetor[meio] < alvo) {
            inicio = meio + 1;
        } else {
            fim = meio - 1;
        }
    }

    return -1;
}

int main() {
    int tamanho = 100;

    int *vetorOrdenado = (int *)malloc(tamanho * sizeof(int));
   
    for (int i = 0; i < tamanho; i++) {
        vetorOrdenado[i] = (i + 1) * 10; 
    }

    int alvos[] = {10, 500, 1000, 9999}; 
    const char *nomesTestes[] = {"Inicio", "Meio  ", "Fim   ", "Ausente"};
    int contadorLinear, contadorBinaria;
    int posLinear, posBinaria;

    printf("=== EXPERIMENTO 1: DADOS COMPATIVEIS (ORDENADOS) ===\n");
    printf("Procurando em vetor de %d elementos...\n\n", tamanho);
    printf("Caso de Teste | Alvo | Custo Linear O(n) | Custo Binario O(log n)\n");
    printf("-----------------------------------------------------------------\n");

    for (int i = 0; i < 4; i++) {
        posLinear = buscaLinear(vetorOrdenado, tamanho, alvos[i], &contadorLinear);
        posBinaria = buscaBinaria(vetorOrdenado, tamanho, alvos[i], &contadorBinaria);

        printf("%-13s | %-4d | %-17d | %-22d\n", 
               nomesTestes[i], alvos[i], contadorLinear, contadorBinaria);
    }

    int vetorDesordenado[] = {45, 12, 89, 3, 27, 68, 15, 99, 31, 7};
    int tamanhoDesordenado = 10;
    int alvoAleatorio = 27;
    int contador;

    printf("\n=== EXPERIMENTO 2: DADOS DESORDENADOS ===\n");
    printf("Vetor: [ 45, 12, 89, 3, 27, 68, 15, 99, 31, 7 ]\n");

    int posEncontrada = buscaLinear(vetorDesordenado, tamanhoDesordenado, alvoAleatorio, &contador);
    
    if (posEncontrada != -1) {
        printf("Busca Linear aplicada com sucesso. Valor encontrado no indice %d (Custo: %d operacoes).\n", posEncontrada, contador);
    }

    free(vetorOrdenado);
    return 0;
}