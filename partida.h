#ifndef PARTIDA_H
#define PARTIDA_H

#define TAM_NOME 50

typedef struct {
    int identificador;
    char jogador[TAM_NOME];
    int pontuacao;
} Partida;

int salvarRelatorio(const Partida *vetorPartidas, int tamanho, const char *nomeArquivo);

int exibirRelatorio(const char *nomeArquivo);

#endif