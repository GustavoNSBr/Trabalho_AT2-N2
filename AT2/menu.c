#include <stdio.h>
#include "./include/types.h"
#include "./include/functions.h"


// Menu principal do programa
void exibirMenu(FILE* arquivo, Musica** head) {
    int opcao = 0;
    Musica* atual = *head;

    do {
        limparTela();
        printf("---------- Playlist de Musica ----------\n\n");
        printf("1. Exibição da playlist pela ordem de cadastro\n");
        printf("2. Exibição da playlist ordenada pelo nome das músicas\n");
        printf("3. Inserção de novas músicas\n");
        printf("4. Remoção de uma música\n");
        printf("5. Busca por uma música\n");
        printf("6. Avançar para próxima música\n");
        printf("7. Retornar a música anterior\n");
        printf("8. Salvar alterações em arquivo\n\n");
        printf("Pressione 0 para sair do programa\n");
        printf("Digite o número da opção desejada: ");

        while (scanf("%d", &opcao) != 1) {
            printf("Opção inválida. Digite novamente: ");
            while (getchar() != '\n');
        }

        switch (opcao) {
            case 1:
                limparTela();
                exibirPlaylist(*head);
                pausarTela();
                break;
            case 2:
                limparTela();
                exibirPlaylistOrdenada(*head);
                pausarTela();
                break;
            case 3:
                limparTela();
                inserirMusica(arquivo, head);
                pausarTela();
                break;
            case 4:
                limparTela();
                removerMusica(arquivo, head);
                pausarTela();
                break;
            case 5:
                limparTela();
                buscarMusica(*head);
                pausarTela();
                break;
            case 6:
                limparTela();
                avancarMusica(&atual);
                pausarTela();
                break;
            case 7:
                limparTela();
                retornarMusica(&atual);
                pausarTela();
                break;
            case 8:
                limparTela();
                salvarAlteracoesEmArquivo(arquivo, *head);
                pausarTela();
                break;
            default:
                break;
        }
    } while (opcao != 0);
}
