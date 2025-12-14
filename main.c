#include <stdio.h>
#include <stdlib.h>
#include"WordleGame.h"

int main() {
    int choice;

    printf("=================================\n");
    printf("         WORDLE SOLVER      \n");
    printf("=================================\n");
    printf("1. Jouer au Wordle (mode manuel)\n");
    printf("2. Solver automatique\n");
    printf("3. Quitter\n");

    printf("Votre choix: ");
    scanf("%d", &choice);

    switch(choice) {
        case 1:
            play_game();
            break;
        case 2:
            play_solver();
            break;
        case 3:
            printf("Au revoir!\n");
            break;
        default:
            printf("Choix invalide!\n");
    }

    return 0;
}
