#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "biblioteca.h"

// dev 2

static void limparBufferEntrada(void) {
    int c;
    while ((c = getchar()) != '\n' && c != EOF) {
    }
}


static void lerLinha(char *destino, int tamanho) {
    if (fgets(destino, tamanho, stdin) != NULL) {
        size_t len = strlen(destino);
        if (len > 0 && destino[len - 1] == '\n') {
            destino[len - 1] = '\0';
        }
    } else {
        destino[0] = '\0';
    }
}

static void lerData(Data *data, const char *rotulo) {
    printf("%s (dia mes ano): ", rotulo);
    scanf("%d %d %d", &data->dia, &data->mes, &data->ano);
    limparBufferEntrada();
}

static int buscarIndicePorId(LivroMagico **biblioteca, int id) {
    int i;
    for (i = 0; i < MAX_LIVROS; i++) {
        if (biblioteca[i] != NULL && biblioteca[i]->id == id) {
            return i;
        }
    }
    return -1;
}

static int proximoIdDisponivel(LivroMagico **biblioteca) {
    int i;
    int maiorId = 0;
    for (i = 0; i < MAX_LIVROS; i++) {
        if (biblioteca[i] != NULL && biblioteca[i]->id > maiorId) {
            maiorId = biblioteca[i]->id;
        }
    }
    return maiorId + 1;
}

void mostrarLivro(LivroMagico **biblioteca, int id) {
    int indice = buscarIndicePorId(biblioteca, id);

    if (indice == -1) {
        printf("\n[ERRO] Nenhum livro encontrado com o ID %d.\n", id);
        return;
    }

    LivroMagico *livro = biblioteca[indice];

    printf("\n-----------------------------------\n");
    printf(" ID: %d\n", livro->id);
    printf(" Titulo:       %s\n", livro->titulo);
    printf(" Autor:        %s\n", livro->autor.nome);
    printf(" Nascimento:   %02d/%02d/%04d\n",
        livro->autor.data_nascimento.dia,
        livro->autor.data_nascimento.mes,
        livro->autor.data_nascimento.ano);
printf(" Data Escrita: %02d/%02d/%04d\n",
        livro->data_escrita.dia,
        livro->data_escrita.mes,
        livro->data_escrita.ano);
    printf("-----------------------------------\n");
}

void editarLivro(LivroMagico **biblioteca, int id) {
    int indice = buscarIndicePorId(biblioteca, id);

    if (indice == -1) {
        printf("\n[ERRO] Nenhum livro encontrado com o ID %d.\n", id);
        return;
    }

    LivroMagico *livro = biblioteca[indice];

    printf("\n--- Editando livro ID %d (deixe os dados novos prontos) ---\n", id);

    printf("Novo titulo: ");
    lerLinha(livro->titulo, sizeof(livro->titulo));

    printf("Novo nome do autor: ");
    lerLinha(livro->autor.nome, sizeof(livro->autor.nome));

    lerData(&livro->autor.data_nascimento, "Nova data de nascimento do autor");
    lerData(&livro->data_escrita, "Nova data de escrita do livro");

    printf("\n[OK] Livro com ID %d atualizado com sucesso.\n", id);
}

void listarTitulos(LivroMagico **biblioteca) {
    int i;
    int total = 0;

    printf("\n=== Livros na Biblioteca ===\n");
    for (i = 0; i < MAX_LIVROS; i++) {
        if (biblioteca[i] != NULL) {
            printf("[ID %d] %s\n", biblioteca[i]->id, biblioteca[i]->titulo);
            total++;
        }
    }
    printf("Total: %d livro(s) cadastrado(s)\n", total);
}

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