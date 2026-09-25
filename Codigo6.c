#include <stdio.h>

void aplicar_dano (int *pvida, int *pdano) {
    *pvida -= *pdano;
    
    printf(" VIDA: %d \n", *pvida);
    printf(" ENDERECO DE VIDA: %p \n", (void*)pvida);
    printf(" ---------------------\n");
}

void restaurar_vida (int *pvida, int *pcura) {
    *pvida += *pcura;
    
    printf(" VIDA: %d \n", *pvida);
    printf(" ENDERECO DE VIDA: %p \n", (void*)pvida);
    printf(" ---------------------\n");
}

void aplicar_pontuacao_dupla (int *ppunt, int *ptes) {
   
    if (*ptes == 1) {
        *ppunt += 100;
    } else {
        *ppunt += 10;
    }
    
    printf(" PONTOS: %d ; PONTEIRO: %p\n", *ppunt, (void*)ppunt);
    printf(" ---------------------\n");

}

void ler_mapa(int *mapa, int tamanho) {
    int i;

    for (i = 0; i < tamanho; i++) {
        printf("Digite o valor da plataforma %d:", i+1);
        scanf("%d", mapa + i);
    }
}

void mostrar_mapa(const int *mapa, int tamanho) {
    int i;

    printf("-------- MAPA --------\n");

    for (i = 0; i < tamanho; i++) {

        printf(" INDICE: %d \n", i);
        printf(" ENDERECO DA PLATAFORMA %p \n", (void *)(mapa + i));
        printf(" PLATAFORMA: %d \n", *(mapa + i));
        printf(" ---------------------\n");
    }
}

void exploracao_mapa(int *mapa, int tamanho, int *ppunt, int *paltura_p) {
    int i;
    int *pex = mapa;

    for (i = 1; pex < mapa + tamanho; i++){

        printf("Plataforma %d explorada: %d\n", i, *pex);
        
        // Como o vetor "v" e "a" são do tipo inteiro, quando adiciona 1 
        // o ponteiro avança para o proximo elemento do vetor, e não para o proximo byte.
       
        *ppunt += *pex;
        *paltura_p += *pex;

        pex++;
    }

    // Utilizo o ponteiro auxiliar pex no lugar de *(mapa + i),
    // assim, o ponteiro funciona como a posição do jogador
}

void mostrar_item(int *inventario[], int indice) { 
    printf("\n------- ITEM -------\n"); 
    
    if (indice == 0) { 
        printf("ITEM: ESPADA\n"); 
    } else if (indice == 1) { 
        printf("ITEM: POCAO\n"); 
    } else if (indice == 2) { 
        printf("ITEM: MOEDA\n"); 
    } 
    
    printf("QUANTIDADE: %d\n", *inventario[indice]); 
    printf("ENDERECO: %p\n", (void *)inventario[indice]); 
    printf("---------------------\n"); 
}

void alterar_item(int *inventario[], int indice) { 
    int nova_quantidade; 
    
    printf("\n------- ALTERAR ITEM -------\n"); 
    
    if (indice == 0) { 
        printf("ITEM: ESPADA\n"); 
    } else if (indice == 1) { 
        printf("ITEM: POCAO\n"); 
    } else if (indice == 2) { 
        printf("ITEM: MOEDA\n"); 
    } 
    
    printf("QUANTIDADE ATUAL: %d\n", **(inventario + indice)); 
    
    printf("Digite a nova quantidade: "); 
    scanf("%d", &nova_quantidade); 
    
    **(inventario + indice) = nova_quantidade; 
    
    printf("Quantidade alterada!\n"); 
    printf("---------------------\n"); 
}

void mostrar_inventario(int *inventario[], int tamanho) { 
    int i; 
    
    printf("\n====== INVENTARIO ======\n"); 
    
    for (i = 0; i < tamanho; i++) { 
        printf("INDICE: %d\n", i); 
        
        if (i == 0) { 
            printf("ITEM: ESPADA\n"); 
        } else if (i == 1) { 
            printf("ITEM: POCAO\n"); 
        } else if (i == 2) { 
            printf("ITEM: MOEDA\n"); 
        } 
        
    printf("QUANTIDADE: %d\n", *inventario[i]); 
    printf("ENDERECO: %p\n", (void *)inventario[i]); 
    printf("---------------------\n"); } 
}

void menu_itens(int *inventario[], int tamanho) { 
    int opcao; 
    int indice; 
    
    do { 
        printf("\n====== MENU DE ITENS ======\n"); 
        printf("1 - Mostrar inventario\n"); 
        printf("2 - Consultar item usando inventario[i]\n"); 
        printf("3 - Alterar item usando *(inventario + i)\n"); 
        printf("0 - Voltar\n"); 
        printf("Escolha: "); 
        scanf("%d", &opcao); 
        
        switch (opcao) { 
            case 1: 
                mostrar_inventario(inventario, tamanho); 
                break; 
            
            case 2: 
                printf("Digite o indice do item (0 a %d): ", tamanho - 1); 
                scanf("%d", &indice); 
                
                if (indice >= 0 && indice < tamanho) { 
                    mostrar_item(inventario, indice); 
                } else { 
                    printf("Indice invalido!\n"); 
                } 
                break; 
                
            case 3: 
                printf("Digite o indice do item (0 a %d): ", tamanho - 1); 
                scanf("%d", &indice); 
                
                if (indice >= 0 && indice < tamanho) { 
                    alterar_item(inventario, indice); 
                } else { 
                    printf("Indice invalido!\n"); 
                } 
                break; 
                
            case 0: 
                printf("Voltando\n"); 
                break; 
                
            default: 
                printf("Opcao invalida!\n"); 
        } 
    } while (opcao != 0); 
}

int main () {

    int vida = 100, dano, cura, at, tes = 0, punt = 0;
    int *pvida = &vida, *pdano = &dano, *pcura = &cura, *pat = &at, *ptes = &tes, *ppunt = &punt;

    //Itens

    int espada = 1; 
    int pocao = 3; 
    int moeda = 10;

    int *inventario[3]; 
    
    inventario[0] = &espada; 
    inventario[1] = &pocao; 
    inventario[2] = &moeda;

    // MAPA

    int mapa[5]; 
    int altura_p = 0; 
    int *paltura_p = &altura_p; 
    int opcao;

    do { 
        
        printf("\n"); 
        printf("================================\n"); 
        printf("============  JOGO  ============\n"); 
        printf("================================\n"); 
        
        printf(" VIDA: %d\n", *pvida); 
        printf(" TESOURO: %d\n", *ptes); 
        printf(" PONTOS: %d\n", *ppunt); 
        printf("================================\n"); 
        
        printf("==========  ESCOLHA  ===========\n"); 
        printf("1 - Aplicar dano\n"); 
        printf("2 - Restaurar vida\n"); 
        printf("3 - Ativar tesouro\n"); 
        printf("4 - Aplicar pontuacao\n"); 
        printf("5 - Configurar mapa\n"); 
        printf("6 - Mostrar mapa\n"); 
        printf("7 - Explorar mapa\n"); 
        printf("8 - Inventario\n"); 
        printf("0 - Sair\n"); 
        
        printf("Escolha uma opcao: "); 
        scanf("%d", &opcao); 
        
        switch (opcao) { 
            case 1: 
                printf("\nDigite o dano: "); 
                scanf("%d", pdano); 
                
                aplicar_dano(pvida, pdano); 
                break; 
                
            case 2: 
                printf("\nDigite a cura: "); 
                scanf("%d", pcura); 
                
                restaurar_vida(pvida, pcura); 
                break; 
                
            case 3: 
                printf("\nDeseja ativar o TESOURO?\n"); 
                printf("Digite 1 para sim: "); 
                scanf("%d", pat); 
                
                if (*pat == 1) { 
                    *ptes = 1; 
                } 
                
                printf("TESOURO: %d\n", *ptes); 
                
                break; 
                
            case 4: 
                aplicar_pontuacao_dupla(ppunt, ptes); 
                
                break; 
                
            case 5: 
                printf("\n------- CONFIGURAR MAPA -------\n"); 
                
                ler_mapa(mapa, 5); 
                
                break; 
            
            case 6: 
                printf("\n------- MOSTRAR MAPA -------\n"); 
                
                mostrar_mapa(mapa, 5); 
                
                break; 
                
            case 7: 
                printf("\n------- EXPLORANDO O MAPA -------\n"); 
                
                exploracao_mapa( mapa, 5, ppunt, paltura_p ); 
                
                printf("---------------------\n"); 
                printf("PONTOS: %d\n", *ppunt); 
                printf("ALTURA ALCANCADA: %d\n", *paltura_p); 
                
                break; 
                
            case 8: 
                menu_itens(inventario, 3); 
                
                break; 
                
            case 0: 
                printf("\nJogo encerrado!\n"); 
                break; 
                
            default: printf("\nOpcao invalida!\n"); 
        } 
    } while (opcao != 0); 
    
    return 0; 
}