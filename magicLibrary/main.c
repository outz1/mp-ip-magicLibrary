#include <stdio.h>
#include <stdlib.h>
#include "structs.h"
#include "biblioteca.h"
#include "arquivo.h"

static void limparBufferEntrada(void) {
    int c;
    while ((c = getchar()) != '\n' && c != EOF) {
    }
}

static void exibirMenu(void) {
    printf("\n");
    printf("======================================\n");
    printf("      BIBLIOTECA MAGICA\n");
    printf("======================================\n");
    printf("  [1] Cadastrar livro\n");
    printf("  [2] Deletar livro\n");
    printf("  [3] Mostrar livro\n");
    printf("  [4] Editar livro\n");
    printf("  [5] Listar titulos\n");
    printf("  [6] Sair\n");
    printf("======================================\n");
    printf("Escolha uma opcao: ");
}

static void liberarBiblioteca(LivroMagico **biblioteca) {
    int i;
    for (i = 0; i < MAX_LIVROS; i++) {
        if (biblioteca[i] != NULL) {
            free(biblioteca[i]);
            biblioteca[i] = NULL;
        }
    }
}
int main(int argc, char *argv[]) {

    if (argc != 2) {
        printf("Uso correto: %s <nome_do_arquivo>\n", argv[0]);
        printf("Exemplo: %s dados.txt\n", argv[0]);
        return 1;
    }

    const char *nomeArquivo = argv[1];

    LivroMagico *biblioteca[MAX_LIVROS];

    inicializarVetor(biblioteca);
    carregarBiblioteca(biblioteca, nomeArquivo);

    int opcao;
    int idDigitado;
    int continuar = 1;

    while (continuar) {
        exibirMenu();

        if (scanf("%d", &opcao) != 1) {
            limparBufferEntrada();
            printf("\n[ERRO] Opcao invalida. Digite um numero de 1 a 6.\n");
            continue;
        }
        limparBufferEntrada();

        switch (opcao) {
            case 1:
                cadastrarLivro(biblioteca);
                salvarBiblioteca(biblioteca, nomeArquivo);
                break;

            case 2:
                printf("Digite o ID do livro a deletar: ");
                scanf("%d", &idDigitado);
                limparBufferEntrada();
                deletarLivro(biblioteca, idDigitado);
                salvarBiblioteca(biblioteca, nomeArquivo);
                break;
            case 3:
                printf("Digite o ID do livro a mostrar: ");
                scanf("%d", &idDigitado);
                limparBufferEntrada();
                mostrarLivro(biblioteca, idDigitado);
                break;

            case 4:
                printf("Digite o ID do livro a editar: ");
                scanf("%d", &idDigitado);
                limparBufferEntrada();
                editarLivro(biblioteca, idDigitado);
                salvarBiblioteca(biblioteca, nomeArquivo);
                break;

            case 5:
                listarTitulos(biblioteca);
                break;

            case 6:
                salvarBiblioteca(biblioteca, nomeArquivo);
                liberarBiblioteca(biblioteca);
                printf("\nDados salvos. Ate a proxima!\n");
                continuar = 0;
                break;

            default:
                printf("\n[ERRO] Opcao invalida. Digite um numero de 1 a 6.\n");
                break;
        }
    }

    return 0;
}