#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "estrutura.h"
#include "livro.h"

int main() {
    Livro* livros = NULL;
    int total_livros = 0;
    int opcao;
    char busca[100];

    do {
        printf("\nSistema de Gestao de Biblioteca\n");
        printf("1. Adicionar livro\n");
        printf("2. Listar livros\n");
        printf("3. Buscar por titulo\n");
        printf("4. Buscar por autor\n");
        printf("5. Buscar por ISBN\n");
        printf("6. Emprestar livro\n");
        printf("7. Devolver livro\n");
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
            case 3:
                printf("Digite o titulo do livro: ");
                getchar();
                fgets(busca, 100, stdin);
                strtok(busca, "\n");
                buscar_por_titulo(livros, total_livros, busca);
                break;
            case 4:
                printf("Digite o autor do livro: ");
                getchar();
                fgets(busca, 100, stdin);
                strtok(busca, "\n");
                buscar_por_autor(livros, total_livros, busca);
                break;
            case 5:
                printf("Digite o ISBN do livro: ");
                getchar();
                fgets(busca, 100, stdin);
                strtok(busca, "\n");
                buscar_por_ISBN(livros, total_livros, busca);
                break;
            case 6:
                printf("Digite o titulo do livro para emprestimo: ");
                getchar();
                fgets(busca, 100, stdin);
                strtok(busca, "\n");
                emprestar_livro(livros, total_livros, busca);
                break;
            case 7:
                printf("Digite o título do livro para devolucao: ");
                getchar();
                fgets(busca, 100, stdin);
                strtok(busca, "\n");
                devolver_livro(livros, total_livros, busca);
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