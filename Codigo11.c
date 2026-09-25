#include <stdio.h> 
#include <string.h> 
#include <stdlib.h>

#define TAM_NOME 50 
#define TAM_APELIDO 20 
#define TAM_SENHA 20 

#define TAM_EXIBICAO 50 
#define TAM_EQUIPE 30 
#define TAM_JOGADOR 50

#define LINHAS 5
#define COLUNAS 5
#define TAM_CELULA 50

void exibir_valor(void *dado, int tipo) { 
    if (tipo == 1) { 
        int valor = *(int *)dado; 
        printf("Valor inteiro: %d\n", valor); 
    } else if (tipo == 2) { 
        float valor = *(float *)dado; 
        printf("Valor real: %.2f\n", valor); 
    } 
}

void inicializar_mapa(char mapa[LINHAS][COLUNAS][TAM_CELULA]) { 
    int linha; 
    int coluna; 
    
    for (linha = 0; linha < LINHAS; linha++) { 
        for (coluna = 0; coluna < COLUNAS; coluna++) { 
            strcpy(mapa[linha][coluna], "-"); 
        } 
    } 
}

int coordenada_valida(int linha, int coluna) { 
    if (linha < 0 || linha >= LINHAS || coluna < 0 || coluna >= COLUNAS) { 
        return 0; 
    } 
    
    return 1; 
}

void mostrar_mapa(char mapa[LINHAS][COLUNAS][TAM_CELULA]) { 
    int linha; 
    int coluna; 
    
    printf("========== MAPA ==========\n"); 
    
    for (linha = 0; linha < LINHAS; linha++) { 
        for (coluna = 0; coluna < COLUNAS; coluna++) { 
            printf("[%-15s]", mapa[linha][coluna]); 
        } 
        
        printf("\n\n"); 
    } 
}

void posicionar_jogador( char mapa[LINHAS][COLUNAS][TAM_CELULA], char jogadores[][TAM_JOGADOR], int quantidade_jogadores ) { 
    int linha; 
    int coluna; 
    int jogador; 
    
    printf("===== POSICIONAR JOGADOR =====\n"); 
    printf("Escolha o jogador (1 a %d): ", quantidade_jogadores); 
    scanf("%d", &jogador); 
    
    if (jogador < 1 || jogador > quantidade_jogadores) { 
        printf("Jogador invalido.\n"); 
        return; 
    } 
    
    jogador--; 
    
    printf("Digite a linha (0 a %d): ", LINHAS - 1); 
    scanf("%d", &linha); 
    
    printf("Digite a coluna (0 a %d): ", COLUNAS - 1); 
    scanf("%d", &coluna); 
    
    if (!coordenada_valida(linha, coluna)) { 
        printf("Coordenada invalida.\n"); 
        return; 
    } 
    
    if (strcmp(mapa[linha][coluna], "-") != 0) { 
        printf("Essa posicao ja esta ocupada.\n"); 
        return; 
    } 
    
    strcpy(mapa[linha][coluna], jogadores[jogador]); 
    
    printf("Jogador %s posicionado com sucesso!\n", jogadores[jogador]); 
}

void remover_jogador( char mapa[LINHAS][COLUNAS][TAM_CELULA] ) { 
    int linha; 
    int coluna; 
    
    printf("===== REMOVER JOGADOR =====\n"); 
    printf("Digite a linha (0 a %d): ", LINHAS - 1); 
    scanf("%d", &linha); 
    
    printf("Digite a coluna (0 a %d): ", COLUNAS - 1); 
    scanf("%d", &coluna); 
    
    if (!coordenada_valida(linha, coluna)) { 
        printf("Coordenada invalida.\n"); 
        return; 
    } 
    
    if (strcmp(mapa[linha][coluna], "-") == 0) { 
        printf("Posicao livre\n"); 
        return; 
    } 
    
    strcpy(mapa[linha][coluna], "-"); 
    
    printf("Posicao removida.\n"); 
}

void reposicionar_jogador( char mapa[LINHAS][COLUNAS][TAM_CELULA], char jogadores[][TAM_JOGADOR], int quantidade_jogadores ) { 
    int linha_antiga; 
    int coluna_antiga; 
    int linha_nova; 
    int coluna_nova; 
    int jogador; 
    int i; 
    
    printf("===== REPOSICIONAR JOGADOR =====\n"); 
    printf("Escolha o jogador (1 a %d): ", quantidade_jogadores); 
    scanf("%d", &jogador); 
    
    if (jogador < 1 || jogador > quantidade_jogadores) { 
        printf("Jogador invalido.\n"); 
        return; 
    } 
    
    jogador--; 
    
    int encontrado = 0; 
    
    for (i = 0; i < LINHAS; i++) { 
        int j; 
        
        for (j = 0; j < COLUNAS; j++) { 
            if (strcmp(mapa[i][j], jogadores[jogador]) == 0) { 
                linha_antiga = i; 
                coluna_antiga = j; 
                encontrado = 1; 
                
                break;
            } 
        } 
        
        if (encontrado == 1) { 
            break; 
        } 
    } 
    
    if (encontrado == 0) { 
        printf("Nao esta no mapa\n"); 
        return; 
    } 
    
    printf("Posicao atual: linha %d, coluna %d\n", linha_antiga, coluna_antiga); 
    printf("Digite a nova linha (0 a %d): ", LINHAS - 1); 
    scanf("%d", &linha_nova); 
    
    printf("Digite a nova coluna (0 a %d): ", COLUNAS - 1); 
    scanf("%d", &coluna_nova); 
    
    if (!coordenada_valida(linha_nova, coluna_nova)) { 
        printf("Nova coordenada invalida.\n"); 
        return; 
    } 
    
    if (strcmp(mapa[linha_nova][coluna_nova], "-") != 0) { 
        printf("A nova posicao ja esta ocupada.\n"); 
        return; 
    } 
    
    strcpy(mapa[linha_antiga][coluna_antiga], "-"); 
    strcpy(mapa[linha_nova][coluna_nova], jogadores[jogador]); 
    printf("Jogador reposicionado com sucesso!\n"); 
}

int main() { 
    
    char nome[TAM_NOME]; 
    char apelido[TAM_APELIDO]; 
    char senha[TAM_SENHA]; 
    char confirmacao[TAM_SENHA]; 

    char equipe[TAM_EQUIPE]; 
    char nome_exibicao[TAM_EXIBICAO]; 
    char (*jogadores)[TAM_JOGADOR] = NULL; 
    char busca[TAM_JOGADOR];

    char mapa[LINHAS][COLUNAS][TAM_CELULA];

    int quantidade_jogadores;
    
    int i; 
    int encontrado = 0;
    int opcao;

    printf("===== CADASTRO DO JOGADOR =====\n"); 
    printf("Digite seu nome: "); 
    fgets(nome, TAM_NOME, stdin); 
    
    nome[strcspn(nome, "\n")] = '\0'; 
    
    printf("Digite seu apelido: "); 
    fgets(apelido, TAM_APELIDO, stdin); 
    
    apelido[strcspn(apelido, "\n")] = '\0'; 
    
    if (strlen(apelido) > 15) { 
        printf("O apelido deve ter no maximo 15 caracteres.\n"); 
        
        return 1; 
    } 
    
    printf("Digite sua senha: "); 
    fgets(senha, TAM_SENHA, stdin); 
    
    senha[strcspn(senha, "\n")] = '\0'; 
    
    printf("Confirme sua senha: "); 
    fgets(confirmacao, TAM_SENHA, stdin); 
    
    confirmacao[strcspn(confirmacao, "\n")] = '\0'; 
    
    if (strcmp(senha, confirmacao) != 0) { 
        printf("\nSenhas diferentes.\n"); 
        return 1; 
    } 

    printf("\nDigite o nome da equipe: "); 
    fgets(equipe, TAM_EQUIPE, stdin); 
    
    equipe[strcspn(equipe, "\n")] = '\0';

    if (strlen(apelido) + strlen(" - ") + strlen(equipe) + 1 <= TAM_EXIBICAO) { 
        strcpy(nome_exibicao, apelido); 
        strcat(nome_exibicao, " - "); 
        strcat(nome_exibicao, equipe); 
    } else { 
        printf("O nome ultrapassa o limite.\n"); 
        return 1; 
    }

    printf("\n===== QUANTIDADE DE JOGADORES =====\n"); 
    printf("Digite a quantidade de jogadores: "); 
    scanf("%d", &quantidade_jogadores);
    getchar();
    
    if (quantidade_jogadores <= 0) { 
        printf("Quantidade invalida.\n"); 
        return 1; 
    } 
    
    // Alocacao dinamica

    jogadores = malloc(quantidade_jogadores * sizeof(*jogadores)); 
    
    if (jogadores == NULL) { 
        printf("Erro ao alocar memoria.\n"); 
        return 1; 
    }

    printf("\n===== CADASTRO DOS JOGADORES =====\n"); 
    
    for (i = 0; i < quantidade_jogadores; i++) { 

        printf("Digite o nome do jogador %d: ", i + 1); 
        fgets(jogadores[i], TAM_JOGADOR, stdin); 
        
        jogadores[i][strcspn(jogadores[i], "\n")] = '\0'; 
    }
    
    printf("\n===== JOGADORES CADASTRADOS =====\n"); 
    
    for (i = 0; i < quantidade_jogadores; i++) { 
        printf("%d - %s\n", i + 1, jogadores[i]); 
    }

    printf("\n===== BUSCAR JOGADOR =====\n"); 
    printf("Digite o nome que deseja buscar: "); 
    fgets(busca, TAM_JOGADOR, stdin); 
    
    busca[strcspn(busca, "\n")] = '\0'; 
    
    for (i = 0; i < quantidade_jogadores; i++) {
        if (strcmp(jogadores[i], busca) == 0) {
            printf("Jogador encontrado!\n"); 
            printf("Posicao: %d\n", i + 1); 
            
            encontrado = 1; 
            break; 
        } 
    } 
    
    if (encontrado == 0) { 
        printf("Jogador nao encontrado.\n"); 
    }

    inicializar_mapa(mapa);

    do { 
        printf("==================================\n"); 
        printf("=========  MENU DO MAPA  =========\n"); 
        printf("==================================\n"); 
        
        printf("1 - Mostrar mapa\n"); 
        printf("2 - Posicionar jogador\n"); 
        printf("3 - Remover jogador\n"); 
        printf("4 - Reposicionar jogador\n"); 
        printf("0 - Finalizar\n"); 
        
        printf("Escolha: "); 
        scanf("%d", &opcao); 
        
        switch (opcao) { 
            case 1: 
                mostrar_mapa(mapa); 
                break; 
                
            case 2: 
                posicionar_jogador(mapa, jogadores, quantidade_jogadores); 
                break; 
                
            case 3: 
                remover_jogador(mapa); 
                break; 
                
            case 4: 
                reposicionar_jogador(mapa, jogadores, quantidade_jogadores); 
                break; 
            
            case 5: 
                {
                    int vida = 100;
                    float pontuacao = 95.5; 
                    
                    printf("\n===== TESTE DA FUNCAO GENERICA =====\n"); 
                    exibir_valor(&vida, 1); 
                    exibir_valor(&pontuacao, 2); 
                    break; 
                }

            case 0: 
                printf("Programa finalizado.\n"); 
                break; 
                
            default: printf("Opcao invalida.\n"); 
        } 
    } while (opcao != 0);

    printf("===== CADASTRO REALIZADO =====\n"); 
    printf("Nome: %s\n", nome); 
    printf("Apelido: %s\n", apelido); 
    printf("Nome de exibicao: %s\n", nome_exibicao);

    if (jogadores != NULL) { 
        free(jogadores); 
        jogadores = NULL; 
    }

    return 0; 
}