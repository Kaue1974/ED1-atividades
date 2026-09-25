#include <stdio.h>

int main () {

    int vida = 100, dano, cura, at, tes = 0;
    int *pvida = &vida, *pdano = &dano, *pcura = &cura, *pat = &at, *ptes = &tes;

    printf(" --------JOGO---------\n");
    printf(" VIDA: %d \n", *pvida);
    printf(" TESOURO: %d \n", *ptes);
    printf(" ---------------------\n");

    // DANO

    printf(" Digite o dano: \n");
    scanf("%d", pdano);

    *pvida -= *pdano;
    
    printf(" VIDA: %d \n", *pvida);
    printf(" ---------------------\n");

    // CURA

    printf(" Digite a cura: \n");
    scanf("%d", pcura);

    *pvida += *pcura;
    
    printf(" VIDA: %d \n", *pvida);
    printf(" ---------------------\n");

    // TESOURO

    printf(" Deseja ativar o TESOURO? Digite 1 para sim: ");
    scanf("%d", pat);

    if (*pat == 1) {
        *ptes = 1;
    }

    printf(" TESOURO: %d \n", *ptes);

    printf(" --------JOGO---------\n");
    printf(" VIDA: %d \n", *pvida);
    printf(" TESOURO: %d \n", *ptes);
    printf(" ---------------------\n");

    return 0; 
}