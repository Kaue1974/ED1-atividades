#include <stdio.h>
#include "agenda46.h"

#define TOTAL_MISSOES 3

int main() {
    Lista *agenda;
    Missao disponiveis[TOTAL_MISSOES];
    Missao removida;
    int proxima = 0;
    int opcao;
    int idReferencia;
    int idRemover;

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
        printf("4 - Inserir proxima missao apos uma missao\n");
        printf("5 - Inserir proxima missao antes de uma missao\n");
        printf("6 - Remover primeira missao\n");
        printf("7 - Remover ultima missao\n");
        printf("8 - Remover missao por ID\n");
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

            case 4:
                printf("\n=== INSERCAO APOS UMA MISSAO ===\n");

                if (proxima >= TOTAL_MISSOES) {
                    printf("Todas as missoes disponiveis ja foram inseridas.\n");
                } else {
                    printf("ID da missao de referencia: ");
                    scanf("%d", &idReferencia);

                    if (!buscarMissao(agenda, idReferencia)) {
                        printf("Missao %d nao encontrada. Agenda inalterada.\n", idReferencia);
                    } else if (inserirApos(agenda, idReferencia, disponiveis[proxima])) {
                        printf("Missao inserida apos a missao %d: ", idReferencia);
                        exibirMissao(disponiveis[proxima]);
                        proxima++;
                    } else {
                        printf("Erro ao inserir a missao.\n");
                    }
                }

                printf("Missoes na agenda: %d\n", tamanhoLista(agenda));

                break;

            case 5:
                printf("\n=== INSERCAO ANTES DE UMA MISSAO ===\n");

                if (proxima >= TOTAL_MISSOES) {
                    printf("Todas as missoes disponiveis ja foram inseridas.\n");
                } else {
                    printf("ID da missao de referencia: ");
                    scanf("%d", &idReferencia);

                    if (!buscarMissao(agenda, idReferencia)) {
                        printf("Missao %d nao encontrada. Agenda inalterada.\n", idReferencia);
                    } else if (inserirAntes(agenda, idReferencia, disponiveis[proxima])) {
                        printf("Missao inserida antes da missao %d: ", idReferencia);
                        exibirMissao(disponiveis[proxima]);
                        proxima++;
                    } else {
                        printf("Erro ao inserir a missao.\n");
                    }
                }

                printf("Missoes na agenda: %d\n", tamanhoLista(agenda));

                break;

            case 6:
                printf("\n=== REMOCAO DA PRIMEIRA MISSAO ===\n");

                if (removerInicio(agenda, &removida)) {
                    printf("Missao removida: ");
                    exibirMissao(removida);
                } else {
                    printf("A agenda esta vazia. Nada para remover.\n");
                }

                printf("Missoes na agenda: %d\n", tamanhoLista(agenda));

                break;

            case 7:
                printf("\n=== REMOCAO DA ULTIMA MISSAO ===\n");

                if (removerFim(agenda, &removida)) {
                    printf("Missao removida: ");
                    exibirMissao(removida);
                } else {
                    printf("A agenda esta vazia. Nada para remover.\n");
                }

                printf("Missoes na agenda: %d\n", tamanhoLista(agenda));
                printf("Integridade da lista: %s\n", verificarIntegridade(agenda) ? "OK" : "ERRO");
                
                exibirLista(agenda);

                break;

            case 8:
                printf("\n=== REMOCAO POR ID ===\n");

                printf("ID da missao a remover: ");
                scanf("%d", &idRemover);

                if (removerPorId(agenda, idRemover, &removida)) {
                    printf("Missao removida: ");
                    exibirMissao(removida);
                } else {
                    printf("Nenhuma missao com ID %d encontrada. Agenda inalterada.\n", idRemover);
                }

                printf("Missoes na agenda: %d\n", tamanhoLista(agenda));
                printf("Integridade da lista: %s\n", verificarIntegridade(agenda) ? "OK" : "ERRO");
                
                exibirLista(agenda);

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