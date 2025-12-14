#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#include"WordleGame.h"

char Word[MAX_WORDS][WORD_LEN];
// mots filtrés
char Filtered[MAX_WORDS][WORD_LEN];


int match_feedback(char word[], char guess[], char fb[]) {
    char fb_actual[6];
    int used[5] = {0};

    // G
    for (int i = 0; i < 5; i++) {
        if (guess[i] == word[i]) {
            fb_actual[i] = 'G';
            used[i] = 1;
        } else {
            fb_actual[i] = '_';
        }
    }

    // Y
    for (int i = 0; i < 5; i++) {
        if (fb_actual[i] != 'G') {
            for (int j = 0; j < 5; j++) {
                if (guess[i] == word[j] && !used[j]) {
                    fb_actual[i] = 'Y';
                    used[j] = 1;
                    break;
                }
            }
        }
    }

    fb_actual[5] = '\0';

    return strcmp(fb_actual, fb) == 0;
}

void filter_words(char all_words[][WORD_LEN], int all_count,char guess[], char FB[], char new_words[][WORD_LEN], int *new_count){
    *new_count = 0;

    for (int i = 0; i < all_count; i++) {
        if (match_feedback(all_words[i], guess, FB)) {
            strcpy(new_words[*new_count], all_words[i]);
            (*new_count)++;
        }
    }
}

void play_solver() {

    int totalWords = read_dictoinary(Word, "words.txt");

    if (totalWords == 0) {
        printf("Erreur : dictionnaire vide.\n");
        return;
    }

    int possibleCount = totalWords;

    // Choisir mot secret
    srand(time(NULL));
    char secret[WORD_LEN];
    strcpy(secret, Word[rand() % totalWords]);

    printf("===== SOLVER WORDLE =====\n");
    printf("Mot secret : %s\n\n", secret);

    // Premier guess on prend le premier mot du fichier
    char guess[WORD_LEN];
    strcpy(guess, Word[0]);

    char fb[WORD_LEN];

    // ----- BOUCLE -----
    for (int attempt = 1; attempt <= MAX_ATTEMPTS; attempt++) {

        printf("Tentative %d : %s\n", attempt, guess);

        feedback(guess, secret, fb);

        if (strcmp(guess, secret) == 0) {
            printf("Solver a trouve en %d tentatives !\n", attempt);
            return;
        }

        // Filtrage des mots possibles
        filter_words(Word, possibleCount, guess, fb, Filtered, &possibleCount);

        if (possibleCount <= 0)
            break;

        strcpy(guess, Filtered[0]);

        // Copier Filtered → Word pour continuer à filtrer
        for (int i = 0; i < possibleCount; i++){
            strcpy(Word[i], Filtered[i]);
    }
    }

    printf("Solver n a pas trouve\n");
}

