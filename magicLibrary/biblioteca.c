#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "biblioteca.h"

//funcoes inicializar vetor e cadastrar livro dev1

void inicializarVetor(LivroMagico **biblioteca) {
    int i;
    for (i = 0; i < MAX_LIVROS; i++) {
        biblioteca[i] = NULL;
    }
}

void cadastrarLivro(LivroMagico **biblioteca) {
    int i;
    int indiceLivre = -1;

    for (i = 0; i < MAX_LIVROS; i++) {
        if (biblioteca[i] == NULL) {
            indiceLivre = i;
            break;
        }
    }

    if (indiceLivre == -1) {
        printf("\n[ERRO] Inventario cheio! Nao e possivel cadastrar mais livros.\n");
        return;
    }

    LivroMagico *novoLivro = (LivroMagico *)malloc(sizeof(LivroMagico));
    if (novoLivro == NULL) {
        printf("\n[ERRO] Falha ao alocar memoria para o novo livro.\n");
        return;
    }

    printf("\n--- Cadastro de Livro ---\n");

    printf("Titulo do livro: ");
    lerLinha(novoLivro->titulo, sizeof(novoLivro->titulo));

    printf("Nome do autor: ");
    lerLinha(novoLivro->autor.nome, sizeof(novoLivro->autor.nome));

    lerData(&novoLivro->autor.data_nascimento, "Data de nascimento do autor");
    lerData(&novoLivro->data_escrita, "Data de escrita do livro");

    novoLivro->id = proximoIdDisponivel(biblioteca);
    biblioteca[indiceLivre] = novoLivro;

    printf("\n[OK] Livro cadastrado com sucesso! ID: %d\n", novoLivro->id);
}

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