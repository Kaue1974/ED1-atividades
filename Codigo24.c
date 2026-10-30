#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int identificador;
    char jogador[50];
    int pontuacao;
} Partida;

void gravarPartidaBinario(Partida p, const char *nomeArquivo) {

    FILE *arquivo = fopen(nomeArquivo, "wb");
    
    if (arquivo == NULL) {
        printf("Erro ao criar o arquivo binario.\n");
        return;
    }

    int elementosEscritos = fwrite(&p, sizeof(Partida), 1, arquivo);

    if (elementosEscritos != 1) {
        printf("Falha na gravacao.\n");
    } else {
        printf("Partida de '%s' salva com sucesso em formato binario!\n", p.jogador);
    }

    fclose(arquivo);
}

void restaurarPartidaBinario(const char *nomeArquivo) {

    FILE *arquivo = fopen(nomeArquivo, "rb");
    
    if (arquivo == NULL) {
        printf("Nenhum arquivo binario encontrado.\n");
        return;
    }

    Partida pReconstruida; 

    int elementosLidos = fread(&pReconstruida, sizeof(Partida), 1, arquivo);

    if (elementosLidos == 1) {
        printf("\n--- Registro Restaurado do Binario ---\n");
        printf("ID: %03d | Jogador: %-15s | Pontuacao: %d\n", 
               pReconstruida.identificador, pReconstruida.jogador, pReconstruida.pontuacao);
        printf("--------------------------------------\n");
    } else {
        if (feof(arquivo)) {
            printf("\n Arquivo vazio.\n");
        } else if (ferror(arquivo)) {
            printf("\n Ocorreu uma falha.\n");
        }
    }

    fclose(arquivo);
}

int main() {
    const char *arquivoBin = "savegame.bin";

    Partida partidaOriginal = {99, "Kaue", 5800};
    
    printf("Dados originais na memoria = ID: %d, Jogador: %s, Pontuacao: %d\n\n", 
           partidaOriginal.identificador, partidaOriginal.jogador, partidaOriginal.pontuacao);

    gravarPartidaBinario(partidaOriginal, arquivoBin);

    restaurarPartidaBinario(arquivoBin);

    return 0;
}