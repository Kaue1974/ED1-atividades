#include <stdio.h>
#include "partida.h"

int main() {
    Partida historico[3] = {
        {1, "Kaue", 2500},
        {2, "Felipe", 1850},
        {3, "Mariana", 3200}
    };

    const char *nomeDoArquivo = "relatorio_partidas.txt";

    if (!salvarRelatorio(historico, 3, nomeDoArquivo)) {
        return 1;
    }

    if (!exibirRelatorio(nomeDoArquivo)) {
        return 1;
    }

    return 0;
}