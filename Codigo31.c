#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int acessarDireto(int *v, int tam, int i, int *c) { 
    *c = 2; 

    return (i >= 0 && i < tam) ? v[i] : -1; 
}

int buscarMaior(int *v, int tam, int *c) {
    *c = 1; int m = v[0];
    
    for(int i=1; i<tam; i++) { 
        (*c)++; 
        
        if(v[i] > m) m = v[i]; 
    }
    
    return m;
}

void encontrarPares(int *v, int tam, int alvo, int *c) {
    *c = 0;

    for(int i=0; i<tam-1; i++)
        for(int j=i+1; j<tam; j++) { 
            (*c)++; 
        }
}

int buscaLinear(int *v, int tam, int alvo, int *c) {
    *c = 0;
    
    for(int i=0; i<tam; i++) { 
        (*c)++; if(v[i] == alvo) return i; 
    }
    
    return -1;
}

int fatorialRecursivo(int n, int *c) {
    (*c)++;

    if (n <= 1) return 1;
    
    return n * fatorialRecursivo(n - 1, c);
}

int fibonacciRecursivo(int n, int *chamadas) {
    (*chamadas)++; 

    if (n == 0) return 0;
    if (n == 1) return 1;

    return fibonacciRecursivo(n - 1, chamadas) + fibonacciRecursivo(n - 2, chamadas);
}

int buscaBinariaRecursiva(int *vetor, int inicio, int fim, int alvo, int *chamadas) {
    (*chamadas)++; 

    if (inicio > fim) {
        return -1; 
    }

    int meio = inicio + (fim - inicio) / 2;

    if (vetor[meio] == alvo) {
        return meio; 
    }

    if (vetor[meio] < alvo) {
        return buscaBinariaRecursiva(vetor, meio + 1, fim, alvo, chamadas);
    } else {
        return buscaBinariaRecursiva(vetor, inicio, meio - 1, alvo, chamadas);
    }
}

int main() {
    int opcao;
    int c1, c2, c3; 
    int tamanhoVetor = 1000;
    int *vetorBusca = (int *)malloc(tamanhoVetor * sizeof(int));
    
    for (int i = 0; i < tamanhoVetor; i++) vetorBusca[i] = i * 2; 

    do {
        printf("\n======= LABORATORIO DE ALGORITMOS =======\n");
        printf("1. O(1) vs O(n) (Acesso vs Busca Linear)\n");
        printf("2. O(n^2) (Pares aninhados)\n");
        printf("3. O(n) vs O(log n) (Linear vs Binaria Iterativa)\n");
        printf("4. Fundamentos da Recursao (Fatorial)\n");
        printf("5. Ramificacao vs Reducao Recursiva\n");
        printf("0. Sair\n");
        printf("=========================================\n");
        printf("Escolha o experimento: ");
        scanf("%d", &opcao);
        
        printf("\n");

        switch(opcao) {
            case 1:
                acessarDireto(vetorBusca, tamanhoVetor, 500, &c1);
                buscarMaior(vetorBusca, tamanhoVetor, &c2);

                printf("Tamanho N = %d\nCusto O(1): %d operacoes\nCusto O(n): %d operacoes\n", tamanhoVetor, c1, c2);
                break;
                
            case 2:
                encontrarPares(vetorBusca, tamanhoVetor, 5000, &c1);

                printf("Tamanho N = %d\nCusto O(n^2): %d operacoes (Lacos aninhados)\n", tamanhoVetor, c1);
                break;
                
            case 3:
                buscaLinear(vetorBusca, tamanhoVetor, -10, &c1); 

                printf("Tamanho N = %d (Pior caso)\n", tamanhoVetor);
                printf("Busca Linear O(n): %d comparacoes\n", c1);
    
                break;

            case 4:
                c1 = 0;
                int res = fatorialRecursivo(5, &c1);

                printf("Fatorial de 5 = %d\nChamadas recursivas empilhadas: %d\n", res, c1);
                break;

            case 5: {
                
                int numFib;

                printf("Digite a posicao da sequencia de Fibonacci desejada (Maximo 30): ");
                scanf("%d", &numFib);
                
                if (numFib > 30) {
                    printf("Limitando entrada a 30 para evitar execucao excessiva (O(2^n)).\n");
                    numFib = 30;
                }
                
                c1 = 0;
                int fib = fibonacciRecursivo(numFib, &c1);

                printf("\n-> FIBONACCI: Termo %d = %d", numFib, fib);
                printf("\n   Total de chamadas recursivas: %d\n", c1);
                
                int alvo = vetorBusca[tamanhoVetor - 1]; 
                c2 = 0;
                int pos = buscaBinariaRecursiva(vetorBusca, 0, tamanhoVetor - 1, alvo, &c2);
                
                break;
            }
            case 0:
                printf("Encerrando.\n");
                break;
            default:
                printf("Opcao invalida.\n");
        }
    } while (opcao != 0);

    free(vetorBusca);
    return 0;
}