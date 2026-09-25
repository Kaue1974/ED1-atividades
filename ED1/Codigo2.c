#include <stdio.h>

void aplicar_dano (int *pvida, int *pdano) {
    *pvida -= *pdano;
    
    printf(" VIDA: %d \n", *pvida);
    printf(" ENDEREÇO DE VIDA: %p \n", (void*)pvida);
    printf(" ---------------------\n");
}

void restaurar_vida (int *pvida, int *pcura) {
    *pvida += *pcura;
    
    printf(" VIDA: %d \n", *pvida);
    printf(" ENDEREÇO DE VIDA: %p \n", (void*)pvida);
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

    printf(" --------JOGO---------\n");
    printf(" VIDA: %d \n", *pvida);
    printf(" TESOURO: %d \n", *ptes);
    printf(" PONTOS: %d \n", *ppunt);
    printf(" ---------------------\n");

    return 0; 
}