#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NOME 50
#define MAX_EQUIPE 50
#define MAX_VIDA 100

typedef struct {
    int x;
    int y;
} Posicao;

typedef enum {
    GUERREIRO,
    MAGO,
    ARQUEIRO
} Classe;

typedef struct {
    int identificador;
    char nome[MAX_NOME];
    int vida;
    int pontuacao;
    Posicao posicao;
    Classe classe;
} Personagem;

typedef struct {
    int identificador;
    char nome[MAX_NOME];
    Personagem *personagens;
    int quantidade;
    int capacidade;
} Equipe;

Personagem criar_personagem(int identificador, const char nome[], int vida, int pontuacao, int x, int y, Classe classe) {
    Personagem personagem = {.identificador = identificador, .nome = "", .vida = vida, .pontuacao = pontuacao,
        .posicao = {.x = x, .y = y}, .classe = classe};

    strncpy(personagem.nome, nome, sizeof(personagem.nome) - 1);

    personagem.nome[sizeof(personagem.nome) - 1] = '\0';

    return personagem;
}

const char *texto_classe(Classe classe) { 
    switch (classe) { 
        case GUERREIRO: 
            return "Guerreiro"; 
        
        case MAGO: 
            return "Mago"; 
            
        case ARQUEIRO: 
            return "Arqueiro"; 
            
        default: 
            return "Classe desconhecida"; 
    } 
}

void alterar_nome(Personagem *personagem) { 
    if (personagem == NULL) { 
        printf("Erro: ponteiro nulo.\n"); 
        
        return; 
    } 
    
    char novo_nome[MAX_NOME]; 
    
    printf("Digite o novo nome: "); 
    fgets(novo_nome, sizeof(novo_nome), stdin); 
    
    novo_nome[strcspn(novo_nome, "\n")] = '\0'; 
    
    if (strlen(novo_nome) == 0) { 
        printf("Nome invalido.\n"); 
        
        return; 
    } 
    
    strncpy(personagem->nome, novo_nome, sizeof(personagem->nome) - 1); 
    
    personagem->nome[sizeof(personagem->nome) - 1] = '\0'; 
}

void alterar_vida(Personagem *personagem, int dano) {
    if (personagem == NULL) {
        printf("Erro: ponteiro nulo.\n"); 
        
        return; 
    } 
    
    if (dano < 0) {
        printf("Dano invalido.\n"); 
        
        return; 
    } 
    
    personagem->vida -= dano; 
    
    if (personagem->vida < 0) {
        personagem->vida = 0;
    } 
    
    if (personagem->vida > MAX_VIDA) {
        personagem->vida = MAX_VIDA; 
    }
}

void alterar_posicao(Personagem *personagem, int x, int y) {
    if (personagem == NULL) {
        printf("Erro: ponteiro nulo.\n"); 
        
        return; 
    } 
    
    if (x < 0 || y < 0) {
        printf("Posicao invalida.\n"); 
        
        return;
    } 
    
    personagem->posicao.x = x; 
    personagem->posicao.y = y; 
} 

void alterar_pontuacao(Personagem *personagem, int pontos) {
    if (personagem == NULL) {
        printf("Erro: ponteiro nulo.\n"); 
        
        return;
    } 
    
    if (pontos < 0) {
        printf("Pontuacao invalida.\n"); 
        
        return; 
    } 
    
    personagem->pontuacao += pontos;
}

void mostrar_personagem(Personagem personagem) {
    
    printf("==== PERSONAGEM ====\n"); 
    printf("Identificador: %d\n", personagem.identificador); 
    printf("Nome: %s\n", personagem.nome); 
    printf("Vida: %d\n", personagem.vida); 
    printf("Pontuacao: %d\n", personagem.pontuacao); 
    printf( "Posicao: (%d, %d)\n", personagem.posicao.x, personagem.posicao.y ); 
    printf( "Classe: %s\n", texto_classe(personagem.classe) ); 
}

void demonstrar_copia(Personagem personagem) {
    printf("==== DENTRO DA FUNCAO ====\n");
    printf("Vida antes da alteracao da copia: %d\n", personagem.vida);

    personagem.vida = 0;

    printf("Vida depois da alteracao da copia: %d\n", personagem.vida);
}

int buscar_personagem (Personagem catalogo[], int quantidade, int identificador) {
    for (int i = 0; i < quantidade; i++) {
        if (catalogo[i].identificador == identificador) {
            return i;
        }
    }

    return -1;
}

void listar_personagens(Personagem catalogo[], int quantidade) {
    if (quantidade == 0) {
        printf("\nNenhum personagem cadastrado.\n");
        return;
    }

    printf("\n======= LISTA DE PERSONAGENS =======\n");

    for (int i = 0; i < quantidade; i++) {
        mostrar_personagem(catalogo[i]);
    }
}

int adicionar_personagem(Personagem **catalogo, int *quantidade, int *capacidade, Personagem personagem) {
    if (*quantidade >= *capacidade) {
        int nova_capacidade = *capacidade * 2;

        Personagem *temporario = realloc(*catalogo, nova_capacidade * sizeof(Personagem));

        if (temporario == NULL) {
            printf("Erro ao aumentar o catalogo.\n");
            return 0;
        }

        *catalogo = temporario;
        *capacidade = nova_capacidade;

        printf("Catalogo ampliado para %d personagens.\n", *capacidade);
    }

    (*catalogo)[*quantidade] = personagem;
    (*quantidade)++;

    return 1;
}

int adicionar_na_equipe(Equipe *equipe, Personagem personagem) {
    if (equipe == NULL) {
        return 0;
    }

    if (equipe->quantidade >= equipe->capacidade) {
        int nova_capacidade = equipe->capacidade * 2;

        Personagem *temporario = realloc(equipe->personagens, nova_capacidade * sizeof(Personagem));

        if (temporario == NULL) {
            printf("Erro ao aumentar a equipe.\n");
            return 0;
        }

        equipe->personagens = temporario;
        equipe->capacidade = nova_capacidade;
    }

    equipe->personagens[equipe->quantidade] = personagem;
    equipe->quantidade++;

    return 1;
}

void listar_equipe(Equipe *equipe) {
    if (equipe == NULL) {
        printf("Equipe invalida.\n");
        return;
    }

    printf("======= EQUIPE =======\n");
    printf("ID da equipe: %d\n", equipe->identificador);
    printf("Nome da equipe: %s\n", equipe->nome);
    printf("Quantidade de personagens: %d\n", equipe->quantidade);

    for (int i = 0; i < equipe->quantidade; i++) {
        mostrar_personagem(equipe->personagens[i]);
    }
}

void intercalar(int vetor1[], int tamanho1, int vetor2[], int tamanho2, int resultado[], int *comparacoes) {
    int i = 0;
    int j = 0;
    int k = 0;

    *comparacoes = 0;

    while (i < tamanho1 && j < tamanho2) {
        (*comparacoes)++;

        if (vetor1[i] <= vetor2[j]) {
            resultado[k] = vetor1[i];
            i++;
        } else {
            resultado[k] = vetor2[j];
            j++;
        }

        k++;
    }

    while (i < tamanho1) {
        resultado[k] = vetor1[i];
        i++;
        k++;
    }

    while (j < tamanho2) {
        resultado[k] = vetor2[j];
        j++;
        k++;
    }
}

void dividir(int vetor[], int inicio, int fim) {
    if (inicio >= fim) {
        return;
    }

    int meio = inicio + (fim - inicio) / 2;

    printf("Dividindo intervalo [%d, %d] no meio %d\n", inicio, fim, meio);

    dividir(vetor, inicio, meio);
    dividir(vetor, meio + 1, fim);
}

void mostrar_vetor(int vetor[], int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        printf("%d ", vetor[i]);
    }

    printf("\n");
}

void menu() {
    printf("====================================\n");
    printf("====== CATALOGO DE PERSONAGENS =====\n");
    printf("====================================\n");
    printf("1 - Cadastrar personagem\n");
    printf("2 - Buscar personagem\n");
    printf("3 - Alterar vida\n");
    printf("4 - Alterar pontuacao\n");
    printf("5 - Alterar posicao\n");
    printf("6 - Alterar nome\n");
    printf("7 - Listar personagens\n");
    printf("8 - Adicionar personagem a equipe\n");
    printf("9 - Listar equipe\n");
    printf("0 - Sair\n");
    printf("====================================\n");
    printf("Escolha uma opcao: ");
}

int main() {

    int capacidade = 5;
    int quantidade = 0;
    int nova_quantidade;
    
    int opcao;

    Personagem *catalogo = calloc(capacidade, sizeof(Personagem));

    if (catalogo == NULL) {
        printf("Erro ao alocar memoria.\n");
        return 1;
    }

    Equipe equipe;

    equipe.identificador = 1;

    strcpy(equipe.nome, "Equipe Kaue");

    equipe.capacidade = 3;
    equipe.quantidade = 0;

    equipe.personagens = malloc (equipe.capacidade * sizeof(Personagem));

    if (equipe.personagens == NULL) {
        printf("Erro ao criar equipe.\n");

        free(catalogo);

        return 1;
    }

    Personagem inicial = criar_personagem(1, "Kaue", 100, 0, 0, 0, GUERREIRO);

    adicionar_personagem(&catalogo, &quantidade, &capacidade, inicial);

    do {
        menu();

        scanf("%d", &opcao);
        
        getchar();

        if (opcao == 1) {
            int id;
            char nome[MAX_NOME];
            int vida;
            int pontos;
            int x;
            int y;
            int classe;

            printf("Identificador: ");
            scanf("%d", &id);
            getchar();

            printf("Nome: ");
            fgets(nome, sizeof(nome), stdin);
            nome[strcspn(nome, "\n")] = '\0';

            printf("Vida: ");
            scanf("%d", &vida);

            printf("Pontuacao: ");
            scanf("%d", &pontos);

            printf("Posicao X: ");
            scanf("%d", &x);

            printf("Posicao Y: ");
            scanf("%d", &y);

            printf("\nClasse:\n");
            printf("0 - Guerreiro\n");
            printf("1 - Mago\n");
            printf("2 - Arqueiro\n");
            printf("Escolha: ");
            scanf("%d", &classe);
            getchar();

            if (classe < GUERREIRO || classe > ARQUEIRO) {
                printf("Classe invalida.\n");
                continue;
            }

            if (vida < 0 || vida > MAX_VIDA) {
                printf("Vida invalida.\n");
                continue;
            }

            if (pontos < 0 || x < 0 || y < 0) {
                printf("Valor invalido.\n");
                continue;
            }

            if (buscar_personagem(catalogo, quantidade, id) != -1) {
                printf("Identificador ja cadastrado.\n");
                continue;
            }

            Personagem novo = criar_personagem(id, nome, vida, pontos, x, y, (Classe)classe);

            if (adicionar_personagem(&catalogo, &quantidade, &capacidade, novo)) {
                printf("Personagem cadastrado.\n");
            }
        } else if (opcao == 2) {
            int id;

            printf("Digite o identificador: ");
            scanf("%d", &id);
            getchar();

            int indice = buscar_personagem(catalogo, quantidade, id);

            if (indice == -1) {
                printf("Personagem nao encontrado.\n");
            } else {
                mostrar_personagem(catalogo[indice]);
            }
        } else if (opcao == 3) {
            int id;
            int dano;

            printf("Identificador: ");
            scanf("%d", &id);

            printf("Dano: ");
            scanf("%d", &dano);
            getchar();

            int indice = buscar_personagem(catalogo, quantidade, id);

            if (indice == -1) {
                printf("Personagem nao encontrado.\n");
            } else {
                alterar_vida(&catalogo[indice], dano);

                printf("Vida alterada.\n");
            }
        } else if (opcao == 4) {
            int id;
            int pontos;

            printf("Identificador: ");
            scanf("%d", &id);

            printf("Pontos: ");
            scanf("%d", &pontos);
            getchar();

            int indice = buscar_personagem(catalogo, quantidade, id);

            if (indice == -1) {
                printf("Personagem nao encontrado.\n");
            } else {
                alterar_pontuacao(&catalogo[indice], pontos);

                printf("Pontuacao alterada.\n");
            }
        } else if (opcao == 5) {
            int id;
            int x;
            int y;

            printf("Identificador: ");
            scanf("%d", &id);

            printf("Nova posicao X: ");
            scanf("%d", &x);

            printf("Nova posicao Y: ");
            scanf("%d", &y);
            getchar();

            int indice = buscar_personagem(catalogo, quantidade, id);

            if (indice == -1) {
                printf("Personagem nao encontrado.\n");
            } else {
                alterar_posicao(&catalogo[indice], x, y);

                printf("Posicao alterada.\n");
            }
        } else if (opcao == 6) {
            int id;

            printf("Identificador: ");
            scanf("%d", &id);
            getchar();

            int indice = buscar_personagem(catalogo, quantidade, id);

            if (indice == -1) {
                printf("Personagem nao encontrado.\n");
            } else {
                alterar_nome(&catalogo[indice]);
            }
        } else if (opcao == 7) {
            listar_personagens(catalogo, quantidade);

        } else if (opcao == 8) {
            int id;

            printf("Digite o identificador do personagem: ");
            scanf("%d", &id);
            getchar();

            int indice = buscar_personagem(catalogo, quantidade, id);

            if (indice == -1) {
                printf("Personagem nao encontrado.\n");
            } else {
                if (adicionar_na_equipe(&equipe, catalogo[indice])) {
                    printf("Personagem adicionado a equipe.\n");
                }
            }

        } else if (opcao == 9) {
            listar_equipe(&equipe);

        } else if (opcao != 0) {
            printf("Opcao invalida.\n");
        }

    } while (opcao != 0);

    free(equipe.personagens);
    free(catalogo);

    return 0;
}