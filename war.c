#include <stdio.h>
#include <string.h>
#include <time.h>
#include <locale.h>
#include <stdlib.h>

#define NUM_TERRITORIOS 5
#define NUM_MISSOES 2
#define MAX_STRING 50

struct Territorio {
    char nome[MAX_STRING];
    char corExercito[MAX_STRING];
    int numTropas;
};

int main() {

    setlocale(LC_ALL, "Portuguese");

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

    int opcao;

    do {
        printf("\n==================================================\n");
        printf("                     INÍCIO DA PARTIDA                     \n");
        printf("==================================================\n\n");
        
        printf("Opção 1: Iniciar a fase de ataque.\n");
        printf("Opção 2: Verificar condição de vitória.\n");
        printf("Opção 0: Sair do jogo.\n");
        printf("__________________________________________________\n");
        printf("\nEscolha uma opcao: ");
        
        scanf("%d", &opcao);
        switch (opcao) {
            case 1:
                printf(" ----- Atacar ----- \n");
                printf("Pressione Enter para continuar...\n");
                break;
            case 2:
                printf("Pressione Enter para continuar...\n");
                break;
            case 0:
                printf("Saindo do jogo. Obrigado por jogar!\n");
                break;
            default:
                printf("\nOpção inválida. Tente novamente.\n");
        }
        printf("\n");

    } while (opcao != 0/* condição para continuar o jogo */);

    return 0;
}