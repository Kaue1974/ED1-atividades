#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int identificador;
    char jogador[50];
    int pontuacao;
} Partida;

void cadastrarPartida(Partida **vetorAtual, int *quantidadeAtual) {
    
    Partida *novoVetor = realloc(*vetorAtual, (*quantidadeAtual + 1) * sizeof(Partida));
    
    if (novoVetor == NULL) {
        printf("Memoria insuficiente.\n");
        return;
    }
    
    *vetorAtual = novoVetor;
    int indice = *quantidadeAtual; 

    printf("\n--- Nova Partida ---\n");
    printf("ID da partida: ");
    scanf("%d", &(*vetorAtual)[indice].identificador);
    
    printf("Nome do jogador (sem espacos): ");
    scanf("%49s", (*vetorAtual)[indice].jogador);
    
    printf("Pontuacao: ");
    scanf("%d", &(*vetorAtual)[indice].pontuacao);

    (*quantidadeAtual)++; 
    printf("Partida cadastrada.\n");
}

void listarPartidas(Partida *vetor, int quantidade) {
    if (quantidade == 0 || vetor == NULL) {
        printf("\n Nenhuma partida registrada.\n");
        return;
    }

    printf("\n--- Temporada Atual (%d partidas) ---\n", quantidade);
   
    for (int i = 0; i < quantidade; i++) {
        printf("ID: %03d | Jogador: %-15s | Pontuacao: %d\n", 
               vetor[i].identificador, vetor[i].jogador, vetor[i].pontuacao);
    }

    printf("--------------------------------------\n");
}

void salvarTemporada(Partida *vetor, int quantidade, const char *nomeArquivo) {
   
    FILE *arquivo = fopen(nomeArquivo, "wb");
   
    if (arquivo == NULL) {
        printf("Nao foi possivel criar o arquivo para salvar.\n");
        return;
    }

    if (fwrite(&quantidade, sizeof(int), 1, arquivo) != 1) {
        printf("Falha ao gravar a quantidade de registros.\n");
        fclose(arquivo);
        return;
    }

    if (quantidade > 0) {
        if (fwrite(vetor, sizeof(Partida), quantidade, arquivo) != (size_t)quantidade) {
            printf("Falha ao gravar os registros das partidas.\n");
            fclose(arquivo);
            return;
        }
    }

    printf("\n Temporada salva com sucesso!.\n");
    fclose(arquivo);
}

void carregarTemporada(Partida **vetorAtual, int *quantidadeAtual, const char *nomeArquivo) {
   
    FILE *arquivo = fopen(nomeArquivo, "rb");
   
    if (arquivo == NULL) {
        printf("Arquivo de save nao encontrado.\n");
        return;
    }

    int qtdLida = 0;

    if (fread(&qtdLida, sizeof(int), 1, arquivo) != 1) {
        printf("Arquivo vazio ou corrompido.\n");
        fclose(arquivo);
        return;
    }

    if (qtdLida < 0 || qtdLida > 100000) { 
        printf("O arquivo parece estar corrompido (Quantidade invalida: %d).\n", qtdLida);
        fclose(arquivo);
        return;
    }

    Partida *vetorTemporario = NULL;

    if (qtdLida > 0) {
        vetorTemporario = (Partida *) malloc(qtdLida * sizeof(Partida));
        
        if (vetorTemporario == NULL) {
            printf("Falha na alocacao de memoria.\n");
            fclose(arquivo);
            return;
        }

        if (fread(vetorTemporario, sizeof(Partida), qtdLida, arquivo) != (size_t)qtdLida) {
           
            printf("Leitura incompleta.\n");
            
            free(vetorTemporario); 
            fclose(arquivo);
            return;
        }
    }

    free(*vetorAtual); 
    
    *vetorAtual = vetorTemporario; 
    *quantidadeAtual = qtdLida;  

    printf("\n Jogo carregado com sucesso! (%d partidas restauradas).\n", qtdLida);
    fclose(arquivo);
}

int main() {
  
    Partida *temporada = NULL; 
  
    int quantidade = 0;        
    int opcao;
  
    const char *arquivoSave = "temporada_completa.bin";

    do {
        printf("\n======= GERENCIADOR DE TEMPORADA =======\n");
        printf("1. Cadastrar nova partida\n");
        printf("2. Listar partidas na memoria\n");
        printf("3. Salvar temporada no disco\n");
        printf("4. Carregar temporada do disco\n");
        printf("5. Sair\n");
        printf("========================================\n");
        printf("Escolha uma opcao: ");
        
        if (scanf("%d", &opcao) != 1) { 
            while(getchar() != '\n'); 
            continue; 
        }

        switch (opcao) {
            case 1:
                cadastrarPartida(&temporada, &quantidade);
                break;
            case 2:
                listarPartidas(temporada, quantidade);
                break;
            case 3:
                salvarTemporada(temporada, quantidade, arquivoSave);
                break;
            case 4:
                carregarTemporada(&temporada, &quantidade, arquivoSave);
                break;
            case 5:
                printf("Encerrando o programa.\n");
                break;
            default:
                printf("Opcao invalida. Tente novamente.\n");
        }
    } while (opcao != 5);

    free(temporada);

    return 0;
}