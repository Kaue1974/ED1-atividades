#include <stdio.h> 
#include <string.h> 

#define TAM_NOME 50 
#define TAM_APELIDO 20 
#define TAM_SENHA 20 
#define TAM_EXIBICAO 50 
#define TAM_EQUIPE 30 
#define QUANTIDADE_JOGADORES 5 
#define TAM_JOGADOR 50

int main() { 
    
    char nome[TAM_NOME]; 
    char apelido[TAM_APELIDO]; 
    char senha[TAM_SENHA]; 
    char confirmacao[TAM_SENHA]; 

    char equipe[TAM_EQUIPE]; 
    char nome_exibicao[TAM_EXIBICAO]; 
    char jogadores[QUANTIDADE_JOGADORES][TAM_JOGADOR]; 
    char busca[TAM_JOGADOR];
    
    int i; 
    int encontrado = 0;

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

    printf("\n===== CADASTRO DOS JOGADORES =====\n"); 
    
    for (i = 0; i < QUANTIDADE_JOGADORES; i++) { 

        printf("Digite o nome do jogador %d: ", i + 1); 
        fgets(jogadores[i], TAM_JOGADOR, stdin); 
        
        jogadores[i][strcspn(jogadores[i], "\n")] = '\0'; 
    }
    
    printf("\n===== JOGADORES CADASTRADOS =====\n"); 
    
    for (i = 0; i < QUANTIDADE_JOGADORES; i++) { 
        printf("%d - %s\n", i + 1, jogadores[i]); 
    }

    printf("\n===== BUSCAR JOGADOR =====\n"); 
    printf("Digite o nome que deseja buscar: "); 
    fgets(busca, TAM_JOGADOR, stdin); 
    
    busca[strcspn(busca, "\n")] = '\0'; 
    
    for (i = 0; i < QUANTIDADE_JOGADORES; i++) {
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

    printf("===== CADASTRO REALIZADO =====\n"); 
    printf("Nome: %s\n", nome); 
    printf("Apelido: %s\n", apelido); 
    printf("Nome de exibicao: %s\n", nome_exibicao);

    return 0; 
}