#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#include"WordleGame.h"

int match_feedback(char word[], char guess[], char fb[]) {
    char fb_actual[6];

    // Générer le feedback pour ce mot
    feedback(guess, word, fb_actual);

    // Comparer avec le feedback attendu
    return strcmp(fb_actual, fb) == 0;  // Utiliser les bonnes variables
}

void filter_words(char all_words[][WORD_LEN], int all_count, char guess[], char FB[], char new_words[][WORD_LEN], int new_count){
   new_count = 0;
   for(int i=0; i<all_count; i++){
    if(match_feedback(all_words[i], guess, FB)){
        strcpy(new_words[new_count], all_words[i]);
        new_count++;
    }
   }

}
