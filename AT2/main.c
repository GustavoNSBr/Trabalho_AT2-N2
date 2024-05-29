#include <stdio.h>
#include <malloc.h>

#include "./include/types.h"
#include "./include/functions.h"

// Função principal;
int main(void) {
	// Configurando o ambiente de execução;
	configurarAmbiente();

	FILE* arquivo = fopen(CAMINHO_ARQUIVO, "r");

	if(arquivo == NULL) {
		printf("Não foi possível abrir o arquivo. Encerrando o programa...\n");
		return 1;
	} else {
		Musica* musica = (Musica*) malloc(QTD_MAX_MUSICAS * sizeof(Musica));

		if(musica == NULL) {
			printf("Não foi possível alocar a memória. Encerrando o programa...\n");
			return 1;
		} else {
			int qtdMusicas = 0;

			// Lendo o arquivo e salvando as informações na struct Musica;
			lerArquivo(arquivo, musica, &qtdMusicas);

			// Exibindo o menu principal;
			exibirMenu(arquivo, musica, &qtdMusicas);
		}

		// Liberando memória alocada;
		free(musica);
	}

	// Fechando o arquivo e encerrando o programa;
	fclose(arquivo);
	printf("Programa encerrado com sucesso!\n");
	return 0;
}
