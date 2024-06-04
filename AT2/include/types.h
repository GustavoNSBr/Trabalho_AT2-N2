/* types.h */

#pragma once

#define CAMINHO_ARQUIVO "./musicas.txt"

typedef struct Musica {
    char artista[100];
    char nome[100];
    struct Musica* next;
    struct Musica* prev;
} Musica;
