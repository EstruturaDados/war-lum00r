#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NOME 30
#define MAX_COR 10

typedef struct {
    char nome[MAX_NOME];
    char cor[MAX_COR];
    int tropas;
} Territorio;

// ======= Funções =======
Territorio* alocarMapa(int n);
void cadastrarTerritorios(Territorio *mapa, int n);
void exibirMapa(const Territorio *mapa, int n);
void liberarMapa(Territorio *mapa);
void limparBufferEntrada();

// ======= Programa Principal =======
int main() {
    int opcao, n;
    Territorio *mapa = NULL;

    printf("Digite o número de territórios: ");
    scanf("%d", &n);
    limparBufferEntrada();

    mapa = alocarMapa(n);

    do {
        printf("\n=== MENU PRINCIPAL ===\n");
        printf("1 - Cadastrar Territórios\n");
        printf("2 - Exibir Mapa\n");
        printf("0 - Sair\n");
        printf("Escolha: ");
        scanf("%d", &opcao);
        limparBufferEntrada();

        switch(opcao) {
            case 1: cadastrarTerritorios(mapa, n); break;
            case 2: exibirMapa(mapa, n); break;
            case 0: printf("Saindo...\n"); break;
            default: printf("Opção inválida!\n");
        }
    } while(opcao != 0);

    liberarMapa(mapa);
    return 0;
}

// ======= Implementações =======
Territorio* alocarMapa(int n) {
    Territorio *mapa = (Territorio*) malloc(n * sizeof(Territorio));
    if (!mapa) {
        printf("Erro ao alocar memória!\n");
        exit(1);
    }
    return mapa;
}

void cadastrarTerritorios(Territorio *mapa, int n) {
    for (int i = 0; i < n; i++) {
        printf("\n--- Território %d ---\n", i+1);

        printf("Nome: ");
        fgets(mapa[i].nome, MAX_NOME, stdin);
        mapa[i].nome[strcspn(mapa[i].nome, "\n")] = '\0';

        printf("Cor do exército: ");
        fgets(mapa[i].cor, MAX_COR, stdin);
        mapa[i].cor[strcspn(mapa[i].cor, "\n")] = '\0';

        printf("Quantidade de tropas: ");
        scanf("%d", &mapa[i].tropas);
        limparBufferEntrada();
    }
}

void exibirMapa(const Territorio *mapa, int n) {
    printf("\n=== Estado Atual do Mapa ===\n");
    for (int i = 0; i < n; i++) {
        printf("Território %d\n", i+1);
        printf("Nome: %s\n", mapa[i].nome);
        printf("Cor do Exército: %s\n", mapa[i].cor);
        printf("Tropas: %d\n", mapa[i].tropas);
        printf("-----------------------------\n");
    }
}

void liberarMapa(Territorio *mapa) {
    free(mapa);
}

void limparBufferEntrada() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}
