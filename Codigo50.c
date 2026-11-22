#include <stdio.h>
#include "agenda50.h"

#define TOTAL_MISSOES 3

int main() {
    Lista *agenda;
    Missao disponiveis[TOTAL_MISSOES];
    Missao lote[MAX_LOTE];
    Missao removida;
    int proxima = 0;
    int opcao;
    int idReferencia;
    int idRemover;
    int resultado;
    int idAlterar;
    int novaPrioridade;
    char novoTitulo[TAM_TITULO];
    int quantidade;
    int antes;

    disponiveis[0] = criarMissao(1, "Resgatar o mensageiro", 5);
    disponiveis[1] = criarMissao(2, "Mapear a caverna", 3);
    disponiveis[2] = criarMissao(3, "Entregar suprimentos", 4);


    lote[0] = criarMissao(11, "Reparar a ponte", 2);
    lote[1] = criarMissao(12, "Escoltar o mercador", 3);
    lote[2] = criarMissao(13, "Vigiar a muralha", 4);
    lote[3] = criarMissao(14, "Coletar ervas", 1);
    lote[4] = criarMissao(15, "Caçar o lobo", 5);

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
        printf("9 - Remover missao depois de uma referencia\n");
        printf("10 - Remover missao antes de uma referencia\n");
        printf("11 - Limpar agenda\n");
        printf("12 - Alterar missao\n");
        printf("13 - Contar missoes pendentes\n");
        printf("14 - Importar lote de missoes\n");
        printf("15 - Ordenar agenda por prioridade\n");
        printf("16 - Salvar agenda em arquivo\n");
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

            case 9:
                printf("\n=== REMOCAO DEPOIS DE UMA REFERENCIA ===\n");

                printf("ID da missao de referencia: ");
                scanf("%d", &idReferencia);

                resultado = removerDepois(agenda, idReferencia, &removida);

                if (resultado == 1) {
                    printf("Missao removida: ");
                    exibirMissao(removida);
                } else if (resultado == 0) {
                    printf("A missao %d e a ultima. Nao ha missao depois dela.\n", idReferencia);
                } else {
                    printf("Missao %d nao encontrada. Agenda inalterada.\n", idReferencia);
                }

                printf("Missoes na agenda: %d\n", tamanhoLista(agenda));
                printf("Integridade da lista: %s\n", verificarIntegridade(agenda) ? "OK" : "ERRO");

                exibirLista(agenda);

                break;

            case 10:
                printf("\n=== REMOCAO ANTES DE UMA REFERENCIA ===\n");

                printf("ID da missao de referencia: ");
                scanf("%d", &idReferencia);

                resultado = removerAntes(agenda, idReferencia, &removida);

                if (resultado == 1) {
                    printf("Missao removida: ");
                    exibirMissao(removida);
                } else if (resultado == 0) {
                    printf("A missao %d e a primeira. Nao ha missao antes dela.\n", idReferencia);
                } else {
                    printf("Missao %d nao encontrada. Agenda inalterada.\n", idReferencia);
                }

                printf("Missoes na agenda: %d\n", tamanhoLista(agenda));
                printf("Integridade da lista: %s\n", verificarIntegridade(agenda) ? "OK" : "ERRO");

                exibirLista(agenda);

                break;

            case 11:
                printf("\n=== LIMPEZA DA AGENDA ===\n");

                limparLista(agenda);

                printf("Agenda limpa.\n");
                printf("Missoes na agenda: %d\n", tamanhoLista(agenda));
                printf("Integridade da lista: %s\n", verificarIntegridade(agenda) ? "OK" : "ERRO");

                exibirLista(agenda);

                break;

            case 12:
                printf("\n=== ALTERACAO DE MISSAO ===\n");

                printf("ID da missao a alterar: ");
                scanf("%d", &idAlterar);
               
                printf("Novo titulo: ");
                scanf(" %39[^\n]", novoTitulo);

                printf("Nova prioridade (1 a 5): ");
                scanf("%d", &novaPrioridade);

                resultado = alterarMissao(agenda, idAlterar, novoTitulo, novaPrioridade);

                if (resultado == 1) {
                    printf("Missao %d alterada (o ID foi preservado).\n", idAlterar);
                } else if (resultado == 0) {
                    printf("Missao %d nao encontrada. Agenda inalterada.\n", idAlterar);
                } else {
                    printf("Dados invalidos. Agenda inalterada.\n");
                }

                exibirLista(agenda);

                break;

            case 13:
                printf("\n=== MISSOES PENDENTES ===\n");

                printf("Missoes pendentes: %d\n", contarMissoes(agenda));

                break;

            case 14:
                printf("\n=== IMPORTACAO DE LOTE ===\n");

                printf("Quantas missoes do lote importar (1 a %d)? ", MAX_LOTE);
                scanf("%d", &quantidade);

                antes = contarMissoes(agenda);
                printf("Tamanho antes da importacao: %d\n", antes);

                resultado = inserirLote(agenda, lote, quantidade);

                if (resultado == -1) {
                    printf("Quantidade invalida. Agenda inalterada.\n");
                } else if (resultado < quantidade) {
                    printf("Falha de memoria: apenas %d de %d missoes foram importadas.\n", resultado, quantidade);
                } else {
                    printf("%d missoes importadas, na ordem do lote.\n", resultado);
                }

                printf("Tamanho depois da importacao: %d\n", contarMissoes(agenda));
                printf("Integridade da lista: %s\n", verificarIntegridade(agenda) ? "OK" : "ERRO");

                exibirLista(agenda);

                break;

            case 15:
                printf("\n=== ORDENACAO POR PRIORIDADE ===\n");

                antes = contarMissoes(agenda);
                printf("Missoes antes da ordenacao: %d\n", antes);

                if (ordenarLista(agenda)) {
                    printf("Agenda ordenada (maior prioridade primeiro, empate pelo menor ID).\n");
                } else {
                    printf("Erro ao ordenar a agenda.\n");
                }

                printf("Missoes depois da ordenacao: %d\n", contarMissoes(agenda));
                printf("Integridade da lista: %s\n", verificarIntegridade(agenda) ? "OK" : "ERRO");

                exibirLista(agenda);

                break;

            case 16:
                printf("\n=== SALVAR AGENDA ===\n");

                resultado = salvarLista(agenda, NOME_ARQUIVO);

                if (resultado >= 0) {
                    printf("%d missoes salvas em \"%s\".\n", resultado, NOME_ARQUIVO);
                } else if (resultado == -1) {
                    printf("Erro: nao foi possivel abrir o arquivo \"%s\".\n", NOME_ARQUIVO);
                } else {
                    printf("Erro ao gravar no arquivo \"%s\".\n", NOME_ARQUIVO);
                }

                break;

            case 0:
                printf("\nEncerrando o programa...\n");
                break;

            default:
                printf("\nOpcao invalida!\n");
        }

    } while (opcao != 0);

    limparLista(agenda);
    destruirLista(agenda);

    return 0;
}