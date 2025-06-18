#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ALUNOS 100
#define TAM_NOME 100

int main() {
    struct Aluno {
        int id;
        char nome[TAM_NOME];
        float nota;
    };

    struct Aluno alunos[MAX_ALUNOS];
    int totalAlunos = 0;
    int opcao;

    do {
        printf("\n====== MENU PRINCIPAL ======\n");
        printf("1 - Cadastrar Aluno\n");
        printf("2 - Listar Alunos\n");
        printf("3 - Buscar Aluno por ID\n");
        printf("4 - Sair\n");
        printf("Escolha uma opcao: ");
        
        if (scanf("%d", &opcao) != 1) {
            printf("Entrada invalida! Tente novamente.\n");
            while(getchar() != '\n'); 
            continue;
        }

        switch(opcao) {
            case 1:
                if (totalAlunos >= MAX_ALUNOS) {
                    printf("Limite de alunos atingido!\n");
                    break;
                }

                printf("\n--- Cadastro de Aluno ---\n");
                alunos[totalAlunos].id = totalAlunos + 1;
                printf("Nome: ");
                while(getchar() != '\n'); 
                fgets(alunos[totalAlunos].nome, TAM_NOME, stdin);
                alunos[totalAlunos].nome[strcspn(alunos[totalAlunos].nome, "\n")] = '\0';

                do {
                    printf("Nota (0 a 10): ");
                    if (scanf("%f", &alunos[totalAlunos].nota) != 1 || alunos[totalAlunos].nota < 0 || alunos[totalAlunos].nota > 10) {
                        printf("Nota inválida! Digite um valor entre 0 e 10.\n");
                        while(getchar() != '\n'); 
                    } else {
                        break;
                    }
                } while(1);

                printf("Aluno cadastrado com ID %d!\n", alunos[totalAlunos].id);
                totalAlunos++;
                break;

            case 2:
                printf("\n--- Lista de Alunos ---\n");
                if (totalAlunos == 0) {
                    printf("Nenhum aluno cadastrado.\n");
                } else {
                    for (int i = 0; i < totalAlunos; i++) {
                        printf("ID: %d | Nome: %s | Nota: %.2f\n", alunos[i].id, alunos[i].nome, alunos[i].nota);
                    }
                }
                break;

            case 3:
                if (totalAlunos == 0) {
                    printf("Nenhum aluno cadastrado para buscar.\n");
                    break;
                }

                int buscaID;
                printf("Digite o ID do aluno: ");
                if (scanf("%d", &buscaID) != 1 || buscaID < 1 || buscaID > totalAlunos) {
                    printf("ID invalido!\n");
                    while(getchar() != '\n'); 
                    break;
                }

                printf("ID: %d | Nome: %s | Nota: %.2f\n", alunos[buscaID-1].id, alunos[buscaID-1].nome, alunos[buscaID-1].nota);
                break;

            case 4:
                printf("Encerrando o programa...\n");
                break;

            default:
                printf("Opção invalida! Tente novamente.\n");
        }

    } while(opcao != 4);

    return 0;
}
