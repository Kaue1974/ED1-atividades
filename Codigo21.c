#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int identificador;
    char jogador[50];
    int pontuacao;
} Partida;

void salvarRelatorio(Partida *vetorPartidas, int tamanho, const char *nomeArquivo) {
    
    FILE *arquivo = fopen(nomeArquivo, "w");
    
    if (arquivo == NULL) {
        printf("Erro ao criar o arquivo.\n");
        return;
    }

    for (int i = 0; i < tamanho; i++) {
       
        fprintf(arquivo, "%d %s %d\n", vetorPartidas[i].identificador,
                                       vetorPartidas[i].jogador,
                                       vetorPartidas[i].pontuacao);
    }

    fclose(arquivo); 

    printf("Relatorio salvo '%s'!\n", nomeArquivo);
}

void exibirRelatorio(const char *nomeArquivo) {
    
    FILE *arquivo = fopen(nomeArquivo, "r");

    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return;
    }

    Partida p;

    printf("\n--- Dados Recuperados do Arquivo ---\n");

    while (fscanf(arquivo, "%d %49s %d", &p.identificador, p.jogador, &p.pontuacao) == 3) {
        
        printf("Partida ID: %03d | Jogador: %-15s | Pontuacao: %d\n", p.identificador, p.jogador, p.pontuacao);
    }

    fclose(arquivo); 

    printf("------------------------------------\n");
}

int main() {
    
    Partida historico[3] = {
        {1, "Kaue", 2500},
        {2, "Felipe", 1850},
        {3, "Mariana", 3200}
    };

    const char *nomeDoArquivo = "relatorio_partidas.txt";

    salvarRelatorio(historico, 3, nomeDoArquivo);

    exibirRelatorio(nomeDoArquivo);

    return 0;
}