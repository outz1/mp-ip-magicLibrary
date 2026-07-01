#ifndef ARQUIVO_H
#define ARQUIVO_H

#include "structs.h"

void salvarBiblioteca(LivroMagico **biblioteca, const char *nomeArquivo);

void carregarBiblioteca(LivroMagico **biblioteca, const char *nomeArquivo);

#endif