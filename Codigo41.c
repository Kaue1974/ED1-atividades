#include <stdio.h>
#include "agenda41.h"

#define TOTAL_MISSOES 3

int main() {
    Missao agenda[TOTAL_MISSOES];
    int i, opcao;

    agenda[0] = criarMissao(1, "Resgatar o mensageiro", 5);
    agenda[1] = criarMissao(2, "Mapear a caverna", 3);
    agenda[2] = criarMissao(3, "Entregar suprimentos", 4);

    do {
        printf("\n========== MENU ==========\n");
        printf("1 - Exibir missoes\n");
        printf("0 - Sair\n");
        printf("==========================\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {

            case 1:
                printf("\n=== AGENDA DE MISSOES ===\n");

                for (i = 0; i < TOTAL_MISSOES; i++) {
                    exibirMissao(agenda[i]);
                }

                break;

            case 0:
                printf("\nEncerrando o programa...\n");
                break;

            default:
                printf("\nOpcao invalida!\n");
        }

    } while (opcao != 0);

    return 0;
}