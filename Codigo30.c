#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int fatorialIterativo(int n, int *operacoes) {
    *operacoes = 0;
    int resultado = 1;
    
    for (int i = n; i > 1; i--) {
        (*operacoes)++;
        resultado *= i;
    }

    return resultado;
}

int fatorialRecursivo(int n, int *chamadas) {
    (*chamadas)++; 

    if (n <= 1) {
        return 1;
    }

    return n * fatorialRecursivo(n - 1, chamadas);
}

int somaVetorIterativa(int *vetor, int tamanho, int *operacoes) {
    *operacoes = 0;
    int soma = 0;
    
    for (int i = 0; i < tamanho; i++) {
        (*operacoes)++;
        soma += vetor[i];
    }

    return soma;
}

int somaVetorRecursiva(int *vetor, int tamanho, int *chamadas) {
    (*chamadas)++; 

    if (tamanho <= 0) {
        return 0; 
    }

    return vetor[tamanho - 1] + somaVetorRecursiva(vetor, tamanho - 1, chamadas);
}

int main() {
    int chamadas, operacoes;

    int numeroFatorial = 5;
    
    chamadas = 0;

    int resFatRec = fatorialRecursivo(numeroFatorial, &chamadas);
    int resFatIte = fatorialIterativo(numeroFatorial, &operacoes);

    printf("--- Teste 1: Fatorial de %d ---\n", numeroFatorial);
    printf("Resultado Iterativo : %-5d | Custo: %d repeticoes de laco\n", resFatIte, operacoes);
    printf("Resultado Recursivo : %-5d | Custo: %d chamadas empilhadas\n\n", resFatRec, chamadas);

    int tamanhoVetor = 6;
    int vetor[] = {10, 20, 30, 40, 50, 60}; 

    chamadas = 0;

    int resSomaRec = somaVetorRecursiva(vetor, tamanhoVetor, &chamadas);
    int resSomaIte = somaVetorIterativa(vetor, tamanhoVetor, &operacoes);

    printf("--- Teste 2: Soma de Vetor (%d elementos) ---\n", tamanhoVetor);
    printf("Resultado Iterativo : %-5d | Custo: %d repeticoes de laco\n", resSomaIte, operacoes);
    printf("Resultado Recursivo : %-5d | Custo: %d chamadas empilhadas\n\n", resSomaRec, chamadas);

    return 0;
}