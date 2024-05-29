#include <stdio.h>

#include "../include/types.h"
#include "../include/functions.h"

// Menu principal do programa;
void exibirMenu(FILE* arquivo, Musica* musica, int* qtdMusicas) {
	int opcao = 0;

	do {
		limparTela();
		printf("---------- Playlist de Musica ----------\n\n");
		printf("1. Exibição da playlist pela ordem de cadastro\n2. Exibição da playlist ordenada pelo nome das musicas\n3. Insercao de novas musicas\n");
		printf("4. Remocao de uma musica\n5. Busca por uma musica\n6. Avançar para proxima musica\n7. Retornar a musica anterio\n8. Salvar alteracoes em arquivo.\n\n");
		printf("Pressione 0 para sair do programa\n");
		printf("Digite o numero da opcao desejada: ");

		while(scanf("%d", &opcao) != 1) {
			printf("Opção invalida. Digite novamente: ");
			while(getchar() != '\n');
		}

		switch(opcao) {
			case 1:
			{
				limparTela();
				
				pausarTela();
				break;
			}
			case 2:
			{
				limparTela();
				
				pausarTela();
				break;
			}
			case 3:
			{
				limparTela();
				
				pausarTela();
				break;
			}
			case 4:
			{
				limparTela();

				pausarTela();
				break;
			}
			case 5:
			{
				limparTela();
				
				pausarTela();
				break;
			}
			case 6:
			{
				limparTela();
				
				pausarTela();
				break;
			}
			case 7:
			{
				limparTela();
				
				pausarTela();
				break;
			}
			case 8:
				limparTela();
				
				pausarTela();
				break;

			default:
				break;
		}
	} while(opcao != 0);
}