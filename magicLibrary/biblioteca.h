#ifndef BIBLIOTECA_H
#define BIBLIOTECA_H

#include "structs.h"

void inicializarVetor(LivroMagico **biblioteca);

void cadastrarLivro(LivroMagico **biblioteca);

void deletarLivro(LivroMagico **biblioteca, int id);

void mostrarLivro(LivroMagico **biblioteca, int id);

void editarLivro(LivroMagico **biblioteca, int id);

void listarTitulos(LivroMagico **biblioteca);

#endif