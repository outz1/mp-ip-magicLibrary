#ifndef STRUCTS_H
#define STRUCTS_H

#define MAX_LIVROS 100

typedef struct {
    int dia;
    int mes;
    int ano;
} Data;

typedef struct {
    char nome[100];
    Data data_nascimento;
} Autor;


typedef struct {
    int id;
    char titulo[100];
    Autor autor;
    Data data_escrita;
} LivroMagico;

#endif 