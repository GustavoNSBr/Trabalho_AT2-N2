/* functions.c */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <malloc.h>

#include "./include/types.h"
#include "./include/functions.h"

void limparTela() {
    #ifdef _WIN32
    system("cls");
    #elif __linux__
    system("clear");
    #endif
}

void pausarTela() {
    printf("Pressione ENTER para continuar...\n");
    while(getchar() != '\n');
    getchar();
}

void configurarAmbiente() {
    #ifdef _WIN32
    system("color 0A");
    system("title Playlist de Música");
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

void lerArquivo(FILE* arquivo, Musica** head) {
    char linha[256];
    while (fgets(linha, sizeof(linha), arquivo)) {
        Musica* novaMusica = (Musica*)malloc(sizeof(Musica));
        sscanf(linha, "%[^;];%[^\n]", novaMusica->artista, novaMusica->nome);
        novaMusica->next = novaMusica->prev = NULL;

        if (*head == NULL) {
            *head = novaMusica;
            novaMusica->next = novaMusica->prev = novaMusica;
        } else {
            Musica* tail = (*head)->prev;
            tail->next = novaMusica;
            novaMusica->prev = tail;
            novaMusica->next = *head;
            (*head)->prev = novaMusica;
        }
    }
}

void exibirPlaylist(Musica* head) {
    if (head == NULL) {
        printf("Playlist vazia.\n");
        return;
    }

    Musica* atual = head;
    do {
        printf("Artista: %s, Música: %s\n", atual->artista, atual->nome);
        atual = atual->next;
    } while (atual != head);
}

int compararMusicas(const void* a, const void* b) {
    Musica* musicaA = *(Musica**)a;
    Musica* musicaB = *(Musica**)b;
    return strcmp(musicaA->nome, musicaB->nome);
}

void exibirPlaylistOrdenada(Musica* head) {
    if (head == NULL) {
        printf("Playlist vazia.\n");
        return;
    }

    int count = 0;
    Musica* atual = head;
    do {
        count++;
        atual = atual->next;
    } while (atual != head);

    Musica** arrayMusicas = (Musica**)malloc(count * sizeof(Musica*));
    atual = head;
    for (int i = 0; i < count; i++) {
        arrayMusicas[i] = atual;
        atual = atual->next;
    }

    qsort(arrayMusicas, count, sizeof(Musica*), compararMusicas);
    for (int i = 0; i < count; i++) {
        printf("Artista: %s, Música: %s\n", arrayMusicas[i]->artista, arrayMusicas[i]->nome);
    }
    free(arrayMusicas);
}

void inserirMusica(FILE* arquivo, Musica** head) {
    Musica* novaMusica = (Musica*)malloc(sizeof(Musica));
    printf("Digite o nome do artista: ");
    scanf(" %[^\n]", novaMusica->artista);
    printf("Digite o nome da música: ");
    scanf(" %[^\n]", novaMusica->nome);
    novaMusica->next = novaMusica->prev = NULL;

    if (*head == NULL) {
        *head = novaMusica;
        novaMusica->next = novaMusica->prev = novaMusica;
    } else {
        Musica* tail = (*head)->prev;
        tail->next = novaMusica;
        novaMusica->prev = tail;
        novaMusica->next = *head;
        (*head)->prev = novaMusica;
    }

    arquivo = fopen(CAMINHO_ARQUIVO, "a");
    if (arquivo != NULL) {
        fprintf(arquivo, "%s;%s\n", novaMusica->artista, novaMusica->nome);
        fclose(arquivo);
    }
}

void removerMusica(FILE* arquivo, Musica** head) {
    char nome[100];
    printf("Digite o nome da música a ser removida: ");
    scanf(" %[^\n]", nome);

    Musica* atual = *head;
    Musica* anterior = NULL;

    do {
        if (strcmp(atual->nome, nome) == 0) {
            if (atual->next == atual) {
                *head = NULL;
            } else {
                atual->prev->next = atual->next;
                atual->next->prev = atual->prev;
                if (atual == *head) {
                    *head = atual->next;
                }
            }
            free(atual);
            break;
        }
        anterior = atual;
        atual = atual->next;
    } while (atual != *head);

    salvarAlteracoesEmArquivo(arquivo, *head);
}

void buscarMusica(Musica* head) {
    char nome[100];
    printf("Digite o nome da música a ser buscada: ");
    scanf(" %[^\n]", nome);

    Musica* atual = head;
    do {
        if (strcmp(atual->nome, nome) == 0) {
            printf("Música encontrada: Artista: %s, Música: %s\n", atual->artista, atual->nome);
            return;
        }
        atual = atual->next;
    } while (atual != head);

    printf("Música não encontrada.\n");
}

void avancarMusica(Musica** atual) {
    if (*atual != NULL) {
        *atual = (*atual)->next;
        printf("Artista: %s, Música: %s\n", (*atual)->artista, (*atual)->nome);
    }
}

void retornarMusica(Musica** atual) {
    if (*atual != NULL) {
        *atual = (*atual)->prev;
        printf("Artista: %s, Música: %s\n", (*atual)->artista, (*atual)->nome);
    }
}

void salvarAlteracoesEmArquivo(FILE* arquivo, Musica* head) {
    arquivo = fopen(CAMINHO_ARQUIVO, "w");
    if (arquivo != NULL) {
        Musica* atual = head;
        do {
            fprintf(arquivo, "%s;%s\n", atual->artista, atual->nome);
            atual = atual->next;
        } while (atual != head);
        fclose(arquivo);
    }
}
