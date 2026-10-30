#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int buscaBinaria(int *vetor, int tamanho, int alvo, int *contadorOperacoes) {
    int inicio = 0;
    int fim = tamanho - 1;
    *contadorOperacoes = 0;

    printf("\n--- Iniciando Busca Binaria pelo valor: %d ---\n", alvo);

    while (inicio <= fim) {
        (*contadorOperacoes)++;

        int meio = inicio + (fim - inicio) / 2;

        printf("Passo %02d : Indice Inicio: %-3d | Meio: %-3d (Valor: %-4d) | Fim: %-3d\n", 
               *contadorOperacoes, inicio, meio, vetor[meio], fim);

        if (vetor[meio] == alvo) {
            printf("Alvo %d encontrado no indice %d!\n", alvo, meio);
            return meio; 
        }
        
        if (vetor[meio] < alvo) {
            inicio = meio + 1; 
            printf("   Descartou a metade esquerda.\n");
        } else {
            fim = meio - 1; 
            printf("   Descartou a metade direita.\n");
        }
    }

    printf("Alvo %d NAO ESTA no vetor.\n", alvo);
    return -1; 
}

int main() {
   
    int tamanho = 30;
    int *vetorOrdenado = (int *)malloc(tamanho * sizeof(int));
    
    for (int i = 0; i < tamanho; i++) {
        vetorOrdenado[i] = (i + 1) * 10;
    }

    printf("Vetor ordenado gerado com %d elementos.\n", tamanho);

    int contador;

    buscaBinaria(vetorOrdenado, tamanho, 210, &contador);
    printf("Total de operacoes: %d\n", contador);

    buscaBinaria(vetorOrdenado, tamanho, 115, &contador);
    printf("Total de operacoes: %d\n", contador);

    buscaBinaria(vetorOrdenado, tamanho, 10, &contador);
    printf("Total de operacoes: %d\n", contador);

    free(vetorOrdenado);

    return 0;
}