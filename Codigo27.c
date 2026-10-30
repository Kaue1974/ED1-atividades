#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int acessarDireto(int *vetor, int tamanho, int indice, int *contador) {
    *contador = 2; 

    if (indice < 0 || indice >= tamanho) return -1;

    return vetor[indice];
}

int buscarMaior(int *vetor, int tamanho, int *contador) {
    *contador = 1; 

    if (tamanho <= 0) return -1;

    int maior = vetor[0];

    for (int i = 1; i < tamanho; i++) {
        (*contador)++;
        if (vetor[i] > maior) maior = vetor[i];
    }

    return maior;
}

void encontrarPares(int *vetor, int tamanho, int alvo, int *contador) {
    *contador = 0; 

    int paresEncontrados = 0;

    for (int i = 0; i < tamanho - 1; i++) {
        
        for (int j = i + 1; j < tamanho; j++) {
            
            (*contador)++; 
            
            if (vetor[i] + vetor[j] == alvo) {
                paresEncontrados++;
            }
        }
    }
}

void executarExperimento(int tamanho) {
    int *vetor = (int *)malloc(tamanho * sizeof(int));
    
    for (int i = 0; i < tamanho; i++) {
        vetor[i] = rand() % 1000; 
    }

    int alvoTeste = 1500;
    int c1, cn, cn2; 

    acessarDireto(vetor, tamanho, tamanho / 2, &c1);
    buscarMaior(vetor, tamanho, &cn);
    encontrarPares(vetor, tamanho, alvoTeste, &cn2);

    printf("N = %-5d | O(1): %-3d | O(n): %-5d | O(n^2): %-9d\n", tamanho, c1, cn, cn2);

    free(vetor);
}

int main() {
    srand(time(NULL));

    printf("=== LABORATORIO DE COMPLEXIDADE: O(1) vs O(n) vs O(n^2) ===\n\n");
    printf("Tamanho   | Constante | Linear      | Quadratico\n");
    printf("-----------------------------------------------------------\n");

    executarExperimento(10);
    executarExperimento(50);
    executarExperimento(100);
    executarExperimento(500);
    executarExperimento(1000);
    executarExperimento(2000); 

    return 0;
}