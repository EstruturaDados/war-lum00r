// ============================================================================
//         PROJETO WAR ESTRUTURADO - DESAFIO DE CÓDIGO
// ============================================================================
//        
// ============================================================================
//
// OBJETIVOS:
// - Modularizar completamente o código em funções especializadas.
// - Implementar um sistema de missões para um jogador.
// - Criar uma função para verificar se a missão foi cumprida.
// - Utilizar passagem por referência (ponteiros) para modificar dados e
//   passagem por valor/referência constante (const) para apenas ler.
// - Foco em: Design de software, modularização, const correctness, lógica de jogo.
//
// ============================================================================

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// --- Constantes Globais ---
// Definem valores fixos para o número de territórios, missões e tamanho máximo de strings, facilitando a manutenção.
#define NUM_TERRITORIOS 5
#define NUM_MISSOES 2
#define MAX_NOME 30
#define MAX_COR 10

// --- Estrutura de Dados ---
// Define a estrutura para um território, contendo seu nome, a cor do exército que o domina e o número de tropas.
typedef struct {
    char nome[MAX_NOME];
    char cor[MAX_COR];
    int tropas;
} Territorio;

// --- Protótipos das Funções ---
// Declarações antecipadas de todas as funções que serão usadas no programa, organizadas por categoria.
// Funções de setup e gerenciamento de memória:
Territorio* alocarMapa(void);
void inicializarTerritorios(Territorio *mapa);
void liberarMemoria(Territorio *mapa);
// Funções de interface com o usuário:
void exibirMenuPrincipal(void);
void exibirMapa(const Territorio *mapa);
void exibirMissao(int missao);
void faseDeAtaque(Territorio *mapa, const char *corJogador);
// Funções de lógica principal do jogo:
void simularAtaque(Territorio *mapa, int atacante, int defensor, const char *corJogador);
int sortearMissao(void);
int verificarVitoria(const Territorio *mapa, int missao, const char *corJogador);
// Função utilitária:
void limparBufferEntrada(void);

// --- Função Principal (main) ---
// Função principal que orquestra o fluxo do jogo, chamando as outras funções em ordem.
int main() {
    // 1. Configuração Inicial (Setup):
    // - Inicializa a semente para geração de números aleatórios com base no tempo atual.
    srand(time(NULL));
    // - Aloca a memória para o mapa do mundo e verifica se a alocação foi bem-sucedida.
    Territorio *mapa = alocarMapa();
    if (mapa == NULL) {
        printf("Falha na alocacao de memoria.\n");
        return 1;
    }
    // - Preenche os territórios com seus dados iniciais (tropas, donos, etc.).
    inicializarTerritorios(mapa);
    // - Define a cor do jogador e sorteia sua missão secreta.
    char corJogador[MAX_COR] = "Azul";
    int missao = sortearMissao();

    // 2. Laço Principal do Jogo (Game Loop):
    // - Roda em um loop 'do-while' que continua até o jogador sair (opção 0) ou vencer.
    int opcao;
    int vitoria = 0;
    do {
        // - A cada iteração, exibe o mapa, a missão e o menu de ações.
        exibirMapa(mapa);
        exibirMissao(missao);
        exibirMenuPrincipal();
        // - Lê a escolha do jogador e usa um 'switch' para chamar a função apropriada:
        scanf("%d", &opcao);
        limparBufferEntrada();
        switch (opcao) {
            case 1: faseDeAtaque(mapa, corJogador); break;
            case 2:
                if (verificarVitoria(mapa, missao, corJogador)) {
                    printf("Missao cumprida! Voce venceu!\n");
                    vitoria = 1;
                } else {
                    printf("Missao ainda nao cumprida.\n");
                }
                break;
            case 0: printf("Saindo...\n"); break;
            default: printf("Opcao invalida!\n");
        }
        // - Pausa a execução para que o jogador possa ler os resultados antes da próxima rodada.
        if (opcao != 0 && !vitoria) {
            printf("Pressione Enter para continuar...");
            getchar();
        }
    } while (opcao != 0 && !vitoria);

    // 3. Limpeza:
    // - Ao final do jogo, libera a memória alocada para o mapa para evitar vazamentos de memória.
    liberarMemoria(mapa);

    return 0;
}

// --- Implementação das Funções ---

// alocarMapa():
// Aloca dinamicamente a memória para o vetor de territórios usando calloc.
// Retorna um ponteiro para a memória alocada ou NULL em caso de falha.
Territorio* alocarMapa(void) {
    Territorio *mapa = (Territorio*) calloc(NUM_TERRITORIOS, sizeof(Territorio));
    if (mapa == NULL) {
        printf("Erro ao alocar memoria!\n");
    }
    return mapa;
}

// inicializarTerritorios():
// Preenche os dados iniciais de cada território no mapa (nome, cor do exército, número de tropas).
// Esta função modifica o mapa passado por referência (ponteiro).
void inicializarTerritorios(Territorio *mapa) {
    // Inicialização automática de 5 territórios com dados pré-definidos.
    strcpy(mapa[0].nome, "Alaska");
    strcpy(mapa[0].cor, "Azul");
    mapa[0].tropas = 3;

    strcpy(mapa[1].nome, "Alberta");
    strcpy(mapa[1].cor, "Verde");
    mapa[1].tropas = 2;

    strcpy(mapa[2].nome, "Mexico");
    strcpy(mapa[2].cor, "Vermelho");
    mapa[2].tropas = 4;

    strcpy(mapa[3].nome, "Brasil");
    strcpy(mapa[3].cor, "Azul");
    mapa[3].tropas = 1;

    strcpy(mapa[4].nome, "Argentina");
    strcpy(mapa[4].cor, "Verde");
    mapa[4].tropas = 3;
}

// liberarMemoria():
// Libera a memória previamente alocada para o mapa usando free.
void liberarMemoria(Territorio *mapa) {
    free(mapa);
}

// exibirMenuPrincipal():
// Imprime na tela o menu de ações disponíveis para o jogador.
void exibirMenuPrincipal(void) {
    printf("\n=== Menu Principal ===\n");
    printf("1 - Atacar\n");
    printf("2 - Verificar Missao\n");
    printf("0 - Sair\n");
    printf("Escolha: ");
}

// exibirMapa():
// Mostra o estado atual de todos os territórios no mapa, formatado como uma tabela.
// Usa 'const' para garantir que a função apenas leia os dados do mapa, sem modificá-los.
void exibirMapa(const Territorio *mapa) {
    printf("\n=== Estado Atual do Mapa ===\n");
    for (int i = 0; i < NUM_TERRITORIOS; i++) {
        printf("Territorio %d: %s - Cor: %s - Tropas: %d\n", i + 1, mapa[i].nome, mapa[i].cor, mapa[i].tropas);
    }
    printf("-----------------------------\n");
}

// exibirMissao():
// Exibe a descrição da missão atual do jogador com base no ID da missão sorteada.
void exibirMissao(int missao) {
    printf("\n=== Sua Missao ===\n");
    if (missao == 1) {
        printf("Destruir o exercito Verde.\n");
    } else if (missao == 2) {
        printf("Conquistar 3 territorios.\n");
    }
}

// faseDeAtaque():
// Gerencia a interface para a ação de ataque, solicitando ao jogador os territórios de origem e destino.
// Chama a função simularAtaque() para executar a lógica da batalha.
void faseDeAtaque(Territorio *mapa, const char *corJogador) {
    int atacante, defensor;
    printf("Escolha o territorio atacante (1 a %d, seu e com pelo menos 2 tropas): ", NUM_TERRITORIOS);
    scanf("%d", &atacante);
    limparBufferEntrada();
    atacante--;  // Converte para índice 0-based

    // Validação do atacante
    if (atacante < 0 || atacante >= NUM_TERRITORIOS || strcmp(mapa[atacante].cor, corJogador) != 0 || mapa[atacante].tropas < 2) {
        printf("Territorio atacante invalido!\n");
        return;
    }

    printf("Escolha o territorio defensor (1 a %d, inimigo): ", NUM_TERRITORIOS);
    scanf("%d", &defensor);
    limparBufferEntrada();
    defensor--;  // Converte para índice 0-based

    // Validação do defensor
    if (defensor < 0 || defensor >= NUM_TERRITORIOS || strcmp(mapa[defensor].cor, corJogador) == 0) {
        printf("Territorio defensor invalido!\n");
        return;
    }

    simularAtaque(mapa, atacante, defensor, corJogador);
}

// simularAtaque():
// Executa a lógica de uma batalha entre dois territórios.
// Realiza validações, rola os dados, compara os resultados e atualiza o número de tropas.
// Se um território for conquistado, atualiza seu dono e move uma tropa.
void simularAtaque(Territorio *mapa, int atk, int def, const char *corJogador) {
    // Rola um dado para atacante e defensor (1 a 6)
    int dadoAtk = rand() % 6 + 1;
    int dadoDef = rand() % 6 + 1;
    printf("\n=== Resultado da Batalha ===\n");
    printf("Dado do atacante: %d\n", dadoAtk);
    printf("Dado do defensor: %d\n", dadoDef);

    if (dadoAtk >= dadoDef) {  // Atacante vence (incluindo empate)
        mapa[def].tropas--;
        printf("Defensor perde 1 tropa! Tropas restantes: %d\n", mapa[def].tropas);
        if (mapa[def].tropas <= 0) {
            printf("Territorio conquistado!\n");
            strcpy(mapa[def].cor, corJogador);
            mapa[def].tropas = 1;  // Move 1 tropa do atacante para o conquistado
            mapa[atk].tropas--;
        }
    } else {
        printf("Ataque falhou! Defensor vence.\n");
    }
}

// sortearMissao():
// Sorteia e retorna um ID de missão aleatório para o jogador.
int sortearMissao(void) {
    return (rand() % NUM_MISSOES) + 1;
}

// verificarVitoria():
// Verifica se o jogador cumpriu os requisitos de sua missão atual.
// Implementa a lógica para cada tipo de missão (destruir um exército ou conquistar um número de territórios).
// Retorna 1 (verdadeiro) se a missão foi cumprida, e 0 (falso) caso contrário.
int verificarVitoria(const Territorio *mapa, int missao, const char *corJogador) {
    if (missao == 1) {  // Destruir o exército Verde
        for (int i = 0; i < NUM_TERRITORIOS; i++) {
            if (strcmp(mapa[i].cor, "Verde") == 0 && mapa[i].tropas > 0) {
                return 0;  // Ainda há territórios Verde com tropas
            }
        }
        return 1;
    } else if (missao == 2) {  // Conquistar 3 territórios
        int count = 0;
        for (int i = 0; i < NUM_TERRITORIOS; i++) {
            if (strcmp(mapa[i].cor, corJogador) == 0) {
                count++;
            }
        }
        return (count >= 3);
    }
    return 0;
}

// limparBufferEntrada():
// Função utilitária para limpar o buffer de entrada do teclado (stdin), evitando problemas com leituras consecutivas de scanf e getchar.
void limparBufferEntrada(void) {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}