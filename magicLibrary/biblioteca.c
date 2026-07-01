#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "biblioteca.h"

//função deletarLivro dev3
void deletarLivro(LivroMagico **biblioteca, int id) {
    int indice;

    indice = buscarIndicePorId(biblioteca, id);
    if (indice == -1) {
        printf("\nerro, nenhum livro encontrado com o ID %d.\n", id);
        return;
    }

    free(biblioteca[indice]);
    biblioteca[indice] = NULL;

    printf("\n Livro com ID %d deletado do inventario.\n", id);
}