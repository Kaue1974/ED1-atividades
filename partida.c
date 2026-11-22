#include <stdio.h>
#include "partida.h"

int salvarRelatorio(const Partida *vetorPartidas, int tamanho, const char *nomeArquivo) {
    FILE *arquivo = fopen(nomeArquivo, "w");
    int i;

    if (arquivo == NULL) {
        printf("Erro ao criar o arquivo.\n");
        return 0;
    }

    for (i = 0; i < tamanho; i++) {
        fprintf(arquivo, "%d %s %d\n", vetorPartidas[i].identificador, vetorPartidas[i].jogador, vetorPartidas[i].pontuacao);
    }

    fclose(arquivo);

    printf("Relatorio salvo '%s'!\n", nomeArquivo);
    return 1;
}

int exibirRelatorio(const char *nomeArquivo) {
    FILE *arquivo = fopen(nomeArquivo, "r");

    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return 0;
    }

    Partida p;

    printf("\n--- Dados Recuperados do Arquivo ---\n");

    while (fscanf(arquivo, "%d %49s %d", &p.identificador, p.jogador, &p.pontuacao) == 3) {
        printf("Partida ID: %03d | Jogador: %-15s | Pontuacao: %d\n", p.identificador, p.jogador, p.pontuacao);
    }

    fclose(arquivo);

    printf("------------------------------------\n");
    return 1;
}