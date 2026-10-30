#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int identificador;
    char jogador[50];
    int pontuacao;
} Partida;

void processarTemporada(const char *arqOrigem, const char *arqDestino, int bonusTemporada) {
    
    FILE *origem = fopen(arqOrigem, "r");

    if (origem == NULL) {
        printf("Nao foi possivel abrir o arquivo '%s'.\n", arqOrigem);
        return; 
    }

    FILE *destino = fopen(arqDestino, "w");
    
    if (destino == NULL) {

        printf("Nao foi possivel criar o arquivo '%s'.\n", arqDestino);
        
        fclose(origem); 
        return; 
    }

    Partida p;

    int registrosProcessados = 0;

    printf("\nIniciando processamento da temporada.\n");
    printf("Bonus aplicado a cada partida: +%d pontos.\n", bonusTemporada);

    while (fscanf(origem, "%d %49s %d", &p.identificador, p.jogador, &p.pontuacao) == 3) {
        
        p.pontuacao += bonusTemporada;

        fprintf(destino, "%d %s %d\n", p.identificador, p.jogador, p.pontuacao);
        
        registrosProcessados++;
    }

    fclose(origem);
    fclose(destino);

    printf("%d registros foram processados e salvos em '%s'.\n", registrosProcessados, arqDestino);
}

int main() {

    const char *arquivoBruto = "relatorio_partidas.txt";
    const char *arquivoProcessado = "relatorio_final_temporada.txt";
    
    int bonus = 500;

    processarTemporada(arquivoBruto, arquivoProcessado, bonus);

    return 0;
}