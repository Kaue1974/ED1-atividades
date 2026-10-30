#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int acessarDireto(int *vetor, int tamanho, int indiceDesejado, int *contadorOperacoes) {
    
    *contadorOperacoes = 0;

    (*contadorOperacoes)++;
   
    if (indiceDesejado < 0 || indiceDesejado >= tamanho) {
        printf("Indice invalido!\n");
        return -1;
    }

    (*contadorOperacoes)++;

    return vetor[indiceDesejado];
}

int buscarMaior(int *vetor, int tamanho, int *contadorOperacoes) {
    
    *contadorOperacoes = 0;

    if (tamanho <= 0) return -1;

    int maiorAtual = vetor[0];
    (*contadorOperacoes)++; 

    for (int i = 1; i < tamanho; i++) {
        
        (*contadorOperacoes)++; 
        
        if (vetor[i] > maiorAtual) {
            maiorAtual = vetor[i];
        }
    }

    return maiorAtual;
}

void executarExperimento(int tamanho) {
    
    int *vetor = (int *)malloc(tamanho * sizeof(int));
    
    for (int i = 0; i < tamanho; i++) {
        vetor[i] = rand() % 10000; 
    }

    int contadorO1, contadorOn;
    int indiceAleatorio = tamanho / 2;

    acessarDireto(vetor, tamanho, indiceAleatorio, &contadorO1);
    buscarMaior(vetor, tamanho, &contadorOn);

    printf("Tamanho do Vetor (N): %-5d | Operacoes O(1): %-3d | Operacoes O(n): %-5d\n", 
           tamanho, contadorO1, contadorOn);

    free(vetor);
}

int main() {
    
    srand(time(NULL));

    printf("=== LABORATORIO: O(1) vs O(n) ===\n\n");

    executarExperimento(10);
    executarExperimento(100);
    executarExperimento(1000);
    executarExperimento(5000); 

    return 0;
}