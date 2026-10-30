#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int identificador;
    char jogador[50];
    int pontuacao;
} Partida;

void anexarPartida(Partida p, const char *nomeArquivo) {
   
    FILE *arquivo = fopen(nomeArquivo, "a"); 
    
    if (arquivo == NULL) {
        printf("Erro ao acessar o arquivo.\n");
        return;
    }

    fprintf(arquivo, "%d %s %d\n", p.identificador, p.jogador, p.pontuacao);
    fclose(arquivo); 
    
    printf("Registro adicionado: %s marcou %d pontos!\n", p.jogador, p.pontuacao);
}

void exibirHistorico(const char *nomeArquivo) {
  
    FILE *arquivo = fopen(nomeArquivo, "r"); 
    
    if (arquivo == NULL) {
        printf("Nenhum historico encontrado.\n");
        return;
    }

    Partida p;

    int contador = 0;
    int itensLidos;

    printf("\n--- Historico Completo de Partidas ---\n");

    while ((itensLidos = fscanf(arquivo, "%d %49s %d", &p.identificador, p.jogador, &p.pontuacao)) == 3) {
        contador++; 

        printf("Registro %02d | ID: %03d | Jogador: %-15s | Pontuacao: %d\n", 
               contador, p.identificador, p.jogador, p.pontuacao);
    }

    if (contador == 0 && itensLidos == EOF) {
        printf("O historico esta vazio.\n");
    } else if (itensLidos != EOF) {
        printf("\nLeitura interrompida: %d.\n", contador);
    } else {
        printf("\nFim do historico lido com sucesso. Total de partidas: %d\n", contador);
    }

    fclose(arquivo); 
    printf("--------------------------------------\n");
}

int main() {
    const char *nomeDoArquivo = "relatorio_partidas.txt";

    Partida novaPartida1 = {4, "Lucas", 4100};
    Partida novaPartida2 = {5, "Amanda", 2750};

    anexarPartida(novaPartida1, nomeDoArquivo);
    anexarPartida(novaPartida2, nomeDoArquivo);

    exibirHistorico(nomeDoArquivo);

    return 0;
}