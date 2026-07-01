#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cripto.h"
#include "arquivo.h"

static void paraHex(const char *origem, char *destinoHex) {
    int i;
    int len = (int)strlen(origem);
    for (i = 0; i < len; i++) {
        sprintf(destinoHex + (i * 2), "%02X", (unsigned char)origem[i]);
    }
    destinoHex[len * 2] = '\0';
}

static void deHex(const char *origemHex, char *destino) {
    int i;
    int len = (int)strlen(origemHex) / 2;
    unsigned int byte;
    for (i = 0; i < len; i++) {
        sscanf(origemHex + (i * 2), "%2x", &byte);
        destino[i] = (char)byte;
    }
    destino[len] = '\0';
}

//funções carregarBiblioteca e salvarBiblioteca dev3
void salvarBiblioteca(LivroMagico **biblioteca, const char *nomeArquivo) {
    int i;
    char tituloCriptografado[100];
    char tituloHex[200];
    FILE *arquivo = fopen(nomeArquivo, "w");

    if (arquivo == NULL) {
        printf("\nerro, nao foi possivel abrir o arquivo '%s' para salvar.\n", nomeArquivo);
        return;
    }


    for (i = 0; i < MAX_LIVROS; i++) {
        if (biblioteca[i] != NULL) {
            LivroMagico *livro = biblioteca[i];
            strcpy(tituloCriptografado, livro->titulo);
            criptografar(tituloCriptografado);
            paraHex(tituloCriptografado, tituloHex);

            fprintf(arquivo, "%d;%s;%s;%d;%d;%d;%d;%d;%d\n",
                    livro->id,
                    tituloHex,
                    livro->autor.nome,
                    livro->autor.data_nascimento.dia,
                    livro->autor.data_nascimento.mes,
                    livro->autor.data_nascimento.ano,
                    livro->data_escrita.dia,
                    livro->data_escrita.mes,
                    livro->data_escrita.ano);
        }
    }

    fclose(arquivo);
}

void carregarBiblioteca(LivroMagico **biblioteca, const char *nomeArquivo) {
    char linha[400];
    char tituloHex[200];
    int indiceVetor = 0;
    int lidos;
    FILE *arquivo = fopen(nomeArquivo, "r");

    if (arquivo == NULL) {
        return;
    }

    while (fgets(linha, sizeof(linha), arquivo) != NULL && indiceVetor < MAX_LIVROS) {
        LivroMagico *livro = (LivroMagico *)malloc(sizeof(LivroMagico));
        if (livro == NULL) {
            printf("\nErro, falha ao alocar memoria ao carregar biblioteca\n");
            break;
        }

        lidos = sscanf(linha, "%d;%[^;];%[^;];%d;%d;%d;%d;%d;%d",
                            &livro->id,
                            tituloHex,
                            livro->autor.nome,
                            &livro->autor.data_nascimento.dia,
                            &livro->autor.data_nascimento.mes,
                            &livro->autor.data_nascimento.ano,
                            &livro->data_escrita.dia,
                            &livro->data_escrita.mes,
                            &livro->data_escrita.ano);

        if (lidos != 9) {
            free(livro);
            continue;
        }

        deHex(tituloHex, livro->titulo);
        descriptografar(livro->titulo);

        while (indiceVetor < MAX_LIVROS && biblioteca[indiceVetor] != NULL) {
            indiceVetor++;
        }

        if (indiceVetor < MAX_LIVROS) {
            biblioteca[indiceVetor] = livro;
            indiceVetor++;
        } else {
            free(livro);
        }
    }
    fclose(arquivo);
}