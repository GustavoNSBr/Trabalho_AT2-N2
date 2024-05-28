#include <stdio.h>

#include "../include/types.h"
#include "../include/functions.h"

// Menu principal do programa;
void exibirMenu(FILE* arquivo, Quarto* quarto, int* qtdQuartos) {
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
				adicionarHospede(quarto, *qtdQuartos);
				pausarTela();
				break;
			}
			case 2:
			{
				limparTela();
				int qtdTotalHospedes = 0;
				Hospede* hospede = guardarHospedes(quarto, *qtdQuartos, &qtdTotalHospedes);

				if(qtdTotalHospedes) {
					quickSort(hospede, 0, qtdTotalHospedes - 1);
					exibirHospedes(hospede, qtdTotalHospedes);
				} else {
					printf("Nao ha nenhum hospede registrado.\n\n");
				}

				pausarTela();
				break;
			}
			case 3:
			{
				limparTela();
				char nome[MAX_CHAR];

				printf("Digite o nome do hospede a ser buscado: ");
				while(scanf(" %[^\n]", nome) != 1) {
					printf("Nome inválido. Digite novamente: ");
				}

				Hospede* hospede = buscarHospede(quarto, *qtdQuartos, nome);

				if(hospede != NULL) {
					printf("Hóspede encontrado: %s\n", hospede->nome);
				} else {
					printf("Hóspede não encontrado\n");
				}

				pausarTela();
				break;
			}
			case 4:
			{
				limparTela();
				char nome[MAX_CHAR];

				printf("Digite o nome do hospede a ser editado: ");
				while(scanf(" %[^\n]", nome) != 1) {
					printf("Nome inválido. Digite novamente: ");
				}

				Hospede* hospede = buscarHospede(quarto, *qtdQuartos, nome);

				if(hospede != NULL) {
					editarHospede(hospede);
				} else {
					printf("Hóspede não encontrado\n");
				}

				pausarTela();
				break;
			}
			case 5:
			{
				limparTela();
				int numQuarto = 0;
				int qtdQuartosOcupados = 0;
				exibirQuartosOcupados(quarto, *qtdQuartos, &qtdQuartosOcupados);

				if(qtdQuartosOcupados) {
					printf("Digite o número do quarto a ser liberado: ");
					while(scanf("%d", &numQuarto) != 1 || numQuarto < 1 || numQuarto > QTD_MAX_QUARTOS) {
						printf("Número de quarto inválido, tente novamente: ");
					}

					liberarQuarto(quarto, numQuarto);
				} else {
					printf("Nao ha quartos ocupados.\n");
				}
				pausarTela();
				break;
			}
			case 6:
			{
				limparTela();
				exibirQuartosVazios(quarto);
				pausarTela();
				break;
			}
			case 7:
				limparTela();
				salvarArquivo(arquivo, quarto, *qtdQuartos);
				pausarTela();
				break;

			default:
				break;
		}
	} while(opcao != 0);
}