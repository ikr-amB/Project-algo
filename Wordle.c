#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "wordleGame.h"


// fonction pour lire des mots d un fichier
int read_dictoinary(char Words[][WORD_LEN], const char *filename){
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

// Procedure feedback - Version avec affichage direct
void feedback(char guess[], char word[], char fb[]) {
    for (int i = 0; i < 5; i++) {
        if (guess[i] == word[i]) {
            fb[i] = 'G';  // lettre correcte à la bonne position
        } else {
            int found = 0;
            for (int j = 0; j < 5; j++) {
                if (guess[i] == word[j]) {
                    found = 1;
                    break;
                }
            }
            if (found)
                fb[i] = 'Y';  // lettre présente mais mauvaise position
            else
                fb[i] = '_';  // lettre absente
        }
    }
    fb[5] = '\0';  // ajout de cette ligne
    printf("%s\n", fb);  // affiche le feedback
}

// le wordle game
void play_game() {
    char Words[MAX_WORDS][WORD_LEN];
    int count;

    // Charger le dictionnaire
    count = read_dictoinary(Words, "words.txt");

    if (count == 0) {
        printf("Erreur : dictionnaire vide.\n");
        return;
    }

    // Choisir un mot secret aléatoire
    srand(time(NULL));
    char target[WORD_LEN];
    strcpy(target, Words[rand() % count]);

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

    printf("PERDU ! Le mot était : %s\n", target);
}
