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

int main () {

    int vida = 100, dano, cura, at, tes = 0, punt = 0;
    int *pvida = &vida, *pdano = &dano, *pcura = &cura, *pat = &at, *ptes = &tes, *ppunt = &punt;

    printf(" --------JOGO---------\n");
    printf(" VIDA: %d \n", *pvida);
    printf(" TESOURO: %d \n", *ptes);
    printf(" PONTOS: %d \n", *ppunt);
    printf(" ---------------------\n");

    printf(" Digite o dano: \n");
    scanf("%d", pdano);

    aplicar_dano(pvida, pdano);

    printf(" VIDA MAIN: %p \n", (void*)pvida);
    printf(" ---------------------\n");

    printf(" Digite a cura: \n");
    scanf("%d", pcura);

    restaurar_vida(pvida, pcura);

    printf(" VIDA MAIN: %p \n", (void*)pvida);
    printf(" ---------------------\n");

    printf(" Deseja ativar o TESOURO? Digite 1 para sim: ");
    scanf("%d", pat);

    if (*pat == 1) {
        *ptes = 1;
    }

    printf(" TESOURO: %d \n", *ptes);
    printf(" ---------------------\n");

    aplicar_pontuacao_dupla(ppunt, ptes);

    printf(" PONTUACAO MAIN: %p \n", (void*)ppunt);
    printf(" ---------------------\n");

    printf(" ------- MAPAS -------\n");

    int mapa[5];
    int altura_p = 0;
    int *paltura_p = &altura_p;

    ler_mapa(mapa, 5);

    printf("-- CONFIRA O MAPA --\n");

    mostrar_mapa(mapa, 5);


    printf("-- EXPLORANDO O MAPA --\n");

    exploracao_mapa(mapa, 5, ppunt, paltura_p);

    printf(" ---------------------\n");
    printf(" PONTOS: %d \n", *ppunt);
    printf(" ALTURA AlCANCADA: %d \n", *paltura_p);

    printf(" --------JOGO---------\n");
    printf(" VIDA: %d \n", *pvida);
    printf(" TESOURO: %d \n", *ptes);
    printf(" PONTOS: %d \n", *ppunt);
    printf(" ---------------------\n");

    return 0; 
}