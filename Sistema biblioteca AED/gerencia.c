#include <stdio.h>
#include <stdlib.h>
#include "estrutura.h"
#include "livro.h"

int main() {
    Livro* livros = NULL;
    int total_livros = 0;
    int opcao;

    do {
        printf("\nSistema de Gestao de Biblioteca\n");
        printf("1. Adicionar livro\n");
        printf("2. Listar livros\n");
        printf("0. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                livros = adicionar_livro(livros, &total_livros);
                break;
            case 2:
                listar_livros(livros, total_livros);
                break;
            case 0:
                printf("Saindo...\n");
                break;
            default:
                printf("Opcao invalida!\n");
                break;
        }
    } while (opcao != 0);

    free(livros);
    return 0;
}
