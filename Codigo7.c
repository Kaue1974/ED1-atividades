#include <stdio.h> 
#include <string.h> 

#define TAM_NOME 50 
#define TAM_APELIDO 20 
#define TAM_SENHA 20 

int main() { 
    
    char nome[TAM_NOME]; 
    char apelido[TAM_APELIDO]; 
    char senha[TAM_SENHA]; 
    char confirmacao[TAM_SENHA]; 
    
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
    
    printf("\n===== CADASTRO REALIZADO =====\n"); 
    printf("Nome: %s\n", nome); 
    printf("Apelido: %s\n", apelido); 

    return 0; 
}