#include <stdio.h>
#include <string.h>

// Definição da struct Territorio
// Cada território tem nome, cor do exército e quantidade de tropas
typedef struct {
    char nome[30];
    char cor[10];
    int tropas;
} Territorio;

int main() {
    // Vetor estático de 5 elementos para armazenar os territórios
    Territorio mapa[5];

    printf("=== Cadastro de Territórios ===\n");

    // Laço para cadastrar os 5 territórios
    for (int i = 0; i < 5; i++) {
        printf("\nTerritório %d:\n", i + 1);

        printf("Digite o nome do território: ");
        // fgets lê a string (inclusive espaços), mas armazena o '\n' no final
        fgets(mapa[i].nome, sizeof(mapa[i].nome), stdin);
        mapa[i].nome[strcspn(mapa[i].nome, "\n")] = '\0'; // remove '\n'

        printf("Digite a cor do exército: ");
        fgets(mapa[i].cor, sizeof(mapa[i].cor), stdin);
        mapa[i].cor[strcspn(mapa[i].cor, "\n")] = '\0'; // remove '\n'

        printf("Digite a quantidade de tropas: ");
        scanf("%d", &mapa[i].tropas);
        getchar(); // consome o '\n' que sobra do scanf
    }

    // Exibição dos territórios cadastrados
    printf("\n=== Estado Atual do Mapa ===\n");
    for (int i = 0; i < 5; i++) {
        printf("Território %d\n", i + 1);
        printf("Nome: %s\n", mapa[i].nome);
        printf("Cor do Exército: %s\n", mapa[i].cor);
        printf("Tropas: %d\n", mapa[i].tropas);
        printf("-----------------------------\n");
    }

    return 0;
}
