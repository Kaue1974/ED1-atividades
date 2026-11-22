#include <stdio.h>
#include "agenda43.h"

#define TOTAL_MISSOES 3

int main() {
    Lista *agenda;
    Missao disponiveis[TOTAL_MISSOES];
    int proxima = 0;
    int opcao;

    disponiveis[0] = criarMissao(1, "Resgatar o mensageiro", 5);
    disponiveis[1] = criarMissao(2, "Mapear a caverna", 3);
    disponiveis[2] = criarMissao(3, "Entregar suprimentos", 4);

    agenda = criarLista();

    if (agenda == NULL) {
        printf("Erro de memoria\n");
        return 1;
    }

    do {
        printf("\n========== MENU ==========\n");
        printf("1 - Inserir proxima missao no inicio\n");
        printf("2 - Exibir agenda\n");
        printf("3 - Inserir proxima missao no fim\n");
        printf("0 - Sair\n");
        printf("==========================\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {

            case 1:
                printf("\n=== INSERCAO NO INICIO ===\n");

                if (proxima >= TOTAL_MISSOES) {
                    printf("Todas as missoes disponiveis ja foram inseridas.\n");
                } else if (inserirInicio(agenda, disponiveis[proxima])) {
                    printf("Missao inserida: ");
                    exibirMissao(disponiveis[proxima]);
                    proxima++;
                } else {
                    printf("Erro ao inserir a missao.\n");
                }

                printf("Missoes na agenda: %d\n", tamanhoLista(agenda));

                break;

            case 2:
                printf("\n=== AGENDA DE MISSOES ===\n");

                exibirLista(agenda);

                break;

            case 3:
                printf("\n=== INSERCAO NO FIM ===\n");

                if (proxima >= TOTAL_MISSOES) {
                    printf("Todas as missoes disponiveis ja foram inseridas.\n");
                } else if (inserirFim(agenda, disponiveis[proxima])) {
                    printf("Missao inserida: ");
                    exibirMissao(disponiveis[proxima]);
                    proxima++;
                } else {
                    printf("Erro ao inserir a missao.\n");
                }

                printf("Missoes na agenda: %d\n", tamanhoLista(agenda));

                break;

            case 0:
                printf("\nEncerrando o programa...\n");
                break;

            default:
                printf("\nOpcao invalida!\n");
        }

    } while (opcao != 0);

    destruirLista(agenda);

    return 0;
}