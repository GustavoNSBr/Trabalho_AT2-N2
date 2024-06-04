/* main.c */

#include <stdio.h>
#include <stdlib.h>

#include "./include/types.h"	
#include "./include/functions.h"

int main(void) {
    configurarAmbiente();

    FILE* arquivo = fopen(CAMINHO_ARQUIVO, "r+");
    if (arquivo == NULL) {
        printf("Não foi possível abrir o arquivo. Encerrando o programa...\n");
        return 1;
    }

    Musica* head = NULL;
    lerArquivo(arquivo, &head);
    exibirMenu(arquivo, &head);

    // Liberando memória alocada
    Musica* atual = head;
    if (head != NULL) {
        do {
            Musica* prox = atual->next;
            free(atual);
            atual = prox;
        } while (atual != head);
    }

    fclose(arquivo);
    printf("Programa encerrado com sucesso!\n");
    return 0;
}
