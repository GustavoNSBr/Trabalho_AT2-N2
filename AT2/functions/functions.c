#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include <malloc.h>

#include "../include/types.h"
#include "../include/functions.h"





// Limpa a tela do console;
void limparTela() {
	#ifdef _WIN32
	system("cls");
	#elif __linux__
	system("clear");
	#endif
}

// Pausa a tela do console;
void pausarTela() {
	printf("Pressione ENTER para continuar...\n");
	while(getchar() != '\n');
	getchar();
}

// Configura o ambiente de execução;
void configurarAmbiente() {
	#ifdef _WIN32
	system("color 0A");
	system("title Gerenciamento de Hotel");
	#endif

	char* local = setlocale(LC_ALL, "");

	if(local == NULL || strcmp(local, "Portuguese_Brazil.1252") != 0) {
		#ifdef _WIN32
		setlocale(LC_ALL, "Portuguese");
		#elif __linux__
		setlocale(LC_ALL, "pt_BR.UTF-8");
		#endif
	}
}

//-------------------------------------------------------------------------------------------------------------------//
