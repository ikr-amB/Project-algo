#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "wordleGame.h"

 char Word[MAX_WORDS][WORD_LEN];

// fonction pour lire des mots d un fichier
int read_dictoinary(char Words[][WORD_LEN], char *filename){
    FILE *f = fopen(filename , "r");
    if( f == NULL){
        printf("erreur!!");
        return 0;
    }

    int count = 0;

    while(fscanf(f , "%5s", Words[count]) != EOF){

        // convertir en minuscules
        for(char *p = Words[count]; *p; p++){
            if(*p >= 'A' && *p <= 'Z'){
                *p += 32;
            }
        }

        count++;
        if(count >= MAX_WORDS){
            break;
        }
    }

    fclose(f);
    return count;
}

// Version avec affichage
void feedback(char guess[], char word[], char fb[]) {
    // Tableau pour marquer les lettres du secret déjà "utilisées"
    int used[5] = {0};  // 0 = non utilisé, 1 = utilisé

    // D'abord, marquer les lettres exactes (G)
    for (int i = 0; i < 5; i++) {
        if (guess[i] == word[i]) {
            fb[i] = 'G';
            used[i] = 1;  // Cette lettre du secret est utilisée
        } else {
            fb[i] = '_';  // Initialisation temporaire
        }
    }

    // Ensuite, marquer les lettres présentes mais mal placées (Y)
    for (int i = 0; i < 5; i++) {
        if (fb[i] != 'G') {  // Si pas déjà G
            for (int j = 0; j < 5; j++) {
                // Si la lettre existe dans le secret ET n'a pas déjà été utilisée
                if (guess[i] == word[j] && !used[j]) {
                    fb[i] = 'Y';
                    used[j] = 1;  // Marquer comme utilisée
                    break;
                }
            }
            // Si aucune correspondance trouvée, reste '_'
        }
    }

    fb[5] = '\0';    // terminer la chaîne
    printf("Feedback: %s\n", fb);
}

// le wordle game
void play_game() {
    int count;

    // Charger le dictionnaire
    count = read_dictoinary(Word, "words.txt");

    if (count == 0) {
        printf("Erreur : dictionnaire vide.\n");
        return;
    }

    // Choisir un mot secret aléatoire
    srand(time(NULL));
    char target[WORD_LEN];
    strcpy(target, Word[rand() % count]);

    printf("====== WORDLE GAME ======\n");
    printf("Vous avez %d tentatives pour deviner le mot secret.\n", MAX_ATTEMPTS);

    char fb[6];  // tableau pour stocker le feedback

    for (int attempt = 0; attempt < MAX_ATTEMPTS; attempt++) {
        char guess[WORD_LEN];
        printf("Tentative %d : ", attempt + 1);
        scanf("%5s", guess);

        // Vérifier que le mot fait exactement 5 caractères
        if (strlen(guess) != 5) {
            printf("Erreur : le mot doit faire exactement 5 lettres.\n");
            attempt--;  // ne pas compter cette tentative
            continue;
        }

        // Calcul et affichage du feedback
        feedback(guess, target, fb);

        // Vérification du mot
        if (strcmp(target, guess) == 0) {
            printf("BRAVO ! Vous avez trouvé le mot '%s'\n", target);
            return;
        }
    }

    printf("PERDU ! Le mot etait : %s\n", target);
}

