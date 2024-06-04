/* functions.h */

#pragma once

#include <stdio.h>
#include "../include/types.h"

/* Declaração das funções */

// Limpa a tela do console
void limparTela();

// Pausa a tela do console
void pausarTela();

// Configura o ambiente de execução
void configurarAmbiente();

// Lê o arquivo e armazena os dados na lista circular duplamente encadeada
void lerArquivo(FILE* arquivo, Musica** head);

// Exibe a playlist pela ordem de cadastro
void exibirPlaylist(Musica* head);

// Exibe a playlist ordenada pelo nome das músicas
void exibirPlaylistOrdenada(Musica* head);

// Insere uma nova música
void inserirMusica(FILE* arquivo, Musica** head);

// Remove uma música
void removerMusica(FILE* arquivo, Musica** head);

// Busca por uma música
void buscarMusica(Musica* head);

// Avança para a próxima música
void avancarMusica(Musica** atual);

// Retorna para a música anterior
void retornarMusica(Musica** atual);

// Salva as alterações no arquivo
void salvarAlteracoesEmArquivo(FILE* arquivo, Musica* head);

// Exibe o menu principal
void exibirMenu(FILE* arquivo, Musica** head);
