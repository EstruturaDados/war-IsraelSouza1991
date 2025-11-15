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

//OK// Inclusão das bibliotecas padrão necessárias para entrada/saída, alocação de memória, manipulação de strings e tempo.
#include <stdio.h> // responsável pelas operações de entrada e saída.
#include <string.h> // responsável pelas operações com strings.
#include <time.h> // responsável pela manipulação de tempo e geração de números aleatórios.
#include <locale.h> // responsável pela configuração de localidade (idioma).
#include <stdlib.h> //responsável pela manipulação da alocação de memória.

// --- Constantes Globais ---
//OK// Definem valores fixos para o número de territórios, missões e tamanho máximo de strings, facilitando a manutenção.
#define NUM_TERRITORIOS 5
#define NUM_MISSOES 2
#define MAX_STRING 50

// --- Estrutura de Dados ---
// Define a estrutura para um território, contendo seu nome, a cor do exército que o domina e o número de tropas.
struct Territorio {
    char nome[MAX_STRING];
    char corExercito[MAX_STRING];
    int numTropas;
};
// --- Protótipos das Funções ---
// Declarações antecipadas de todas as funções que serão usadas no programa, organizadas por categoria.
// Funções de setup e gerenciamento de memória:
// Funções de interface com o usuário:
// Funções de lógica principal do jogo:
// Função utilitária:

// --- Função Principal (main) ---
// Função principal que orquestra o fluxo do jogo, chamando as outras funções em ordem.
int main() {
    // 1. Configuração Inicial (Setup):
    // - Define o locale para português.
    setlocale(LC_ALL, "Portuguese");
    // - Inicializa a semente para geração de números aleatórios com base no tempo atual.
    srand((unsigned int)time(NULL));
    // - Aloca a memória para o mapa do mundo e verifica se a alocação foi bem-sucedida.
    // - Preenche os territórios com seus dados iniciais (tropas, donos, etc.).

    printf("==================================================\n");
    printf("                     JOGO WAR                     \n");
    printf("==================================================\n");

    struct Territorio territorio [NUM_TERRITORIOS];
    


    printf("\n\nVamos cadastrar os 5 territórios do nosso mundo.\n\n");
    
    
    for (int i = 0; i < NUM_TERRITORIOS; i++) {
        printf("Nome do território %d\n Digite: ", i + 1);
        fgets(territorio[i].nome, MAX_STRING, stdin);
        territorio[i].nome[strcspn(territorio[i].nome, "\n")] = 0; // Remove o '\n' do final da string

        printf("Cor do exército que domina o território %d\n Digite: ", i + 1);
        fgets(territorio[i].corExercito, MAX_STRING, stdin);
        territorio[i].corExercito[strcspn(territorio[i].corExercito, "\n")] = 0; // Remove o '\n' do final da string

        printf("Número de tropas no território %d\n Digite: ", i + 1);
        scanf("%d", &territorio[i].numTropas);
        getchar(); // Limpa o buffer de entrada
    }
    printf("\nPronto. Cadastro de territórios concluído...\n\n");

    for (int i = 0; i < NUM_TERRITORIOS; i++){
        printf("-----------------------------------------------\n");
        printf("Território: %d\n", i+1);
        printf("Nome do território: %s\n", territorio[i].nome);
        printf("Cor do exército: %s\n", territorio[i].corExercito);
        printf("Número de tropas: %d\n", territorio[i].numTropas);    
    }

    // - Define a cor do jogador e sorteia sua missão secreta.

    // 2. Laço Principal do Jogo (Game Loop):
    // - Roda em um loop 'do-while' que continua até o jogador sair (opção 0) ou vencer.
    // - A cada iteração, exibe o mapa, a missão e o menu de ações.
    // - Lê a escolha do jogador e usa um 'switch' para chamar a função apropriada:
    //   - Opção 1: Inicia a fase de ataque.
    //   - Opção 2: Verifica se a condição de vitória foi alcançada e informa o jogador.
    //   - Opção 0: Encerra o jogo.
    int opcao;

    do {
        printf("==================================================\n");
        printf("                     JOGO WAR                     \n");
        printf("==================================================\n");
        printf("Opcoes:\n");
        printf("Opção 1: Inicia a fase de ataque.\n");
        printf("Opção 2: Verifica condição de vitória.\n");
        printf("Opção 0: Sair do jogo.\n");
        printf("__________________________________________________\n");
        printf("Escolha uma opcao: ");
        
        scanf("%d", &opcao);
        switch (opcao) {
            case 1:
                printf(" ----- Atacar ----- \n");
                //// Chama a função para iniciar a fase de ataque.
                printf("Pressione Enter para continuar...\n");
                break;
            case 2:
                //// Chama a função para verificar a condição de vitória.
                printf("Pressione Enter para continuar...\n");
                break;
            case 0:
                printf("Saindo do jogo. Obrigado por jogar!\n");
                break;
            default:
                printf("\nOpção inválida. Tente novamente.\n");
        }
        printf("\n");
        /////// Exibe o estado atual do mapa.
        /////// Exibe a missão atual do jogador.
        /////// Exibe o menu principal de ações.
        /////// Lê a escolha do jogador.

        ////// Executa a ação correspondente com base na escolha.
    } while (opcao != 0/* condição para continuar o jogo */);

    // - Pausa a execução para que o jogador possa ler os resultados antes da próxima rodada.

    // 3. Limpeza:
    // - Ao final do jogo, libera a memória alocada para o mapa para evitar vazamentos de memória.

    return 0;
}

// --- Implementação das Funções ---

// alocarMapa():
// Aloca dinamicamente a memória para o vetor de territórios usando calloc.
// Retorna um ponteiro para a memória alocada ou NULL em caso de falha.

// inicializarTerritorios():
// Preenche os dados iniciais de cada território no mapa (nome, cor do exército, número de tropas).
// Esta função modifica o mapa passado por referência (ponteiro).

// liberarMemoria():
// Libera a memória previamente alocada para o mapa usando free.

// exibirMenuPrincipal():
// Imprime na tela o menu de ações disponíveis para o jogador.

// exibirMapa():
// Mostra o estado atual de todos os territórios no mapa, formatado como uma tabela.
// Usa 'const' para garantir que a função apenas leia os dados do mapa, sem modificá-los.

// exibirMissao():
// Exibe a descrição da missão atual do jogador com base no ID da missão sorteada.

// faseDeAtaque():
// Gerencia a interface para a ação de ataque, solicitando ao jogador os territórios de origem e destino.
// Chama a função simularAtaque() para executar a lógica da batalha.

// simularAtaque():
// Executa a lógica de uma batalha entre dois territórios.
// Realiza validações, rola os dados, compara os resultados e atualiza o número de tropas.
// Se um território for conquistado, atualiza seu dono e move uma tropa.

// sortearMissao():
// Sorteia e retorna um ID de missão aleatório para o jogador.

// verificarVitoria():
// Verifica se o jogador cumpriu os requisitos de sua missão atual.
// Implementa a lógica para cada tipo de missão (destruir um exército ou conquistar um número de territórios).
// Retorna 1 (verdadeiro) se a missão foi cumprida, e 0 (falso) caso contrário.

// limparBufferEntrada():
// Função utilitária para limpar o buffer de entrada do teclado (stdin), evitando problemas com leituras consecutivas de scanf e getchar.
