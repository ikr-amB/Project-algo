#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "wordleGame.h"

#define WORD_LEN 6
#define MAX_ATTEMPTS 6
#define MAX_WORDS 1000000

// éviter stack overflow → tableau global
char word[MAX_WORDS][WORD_LEN];

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

// procedure feedback
void feedback(char guess[], char word[]){
    for(int i = 0; i < 5; i++){
        if(guess[i] == word[i]){
            printf("%c est dans le mot et dans la bonne position\n", guess[i]);
        }
        else {
            int found = 0;
            for(int j = 0; j < 5; j++){
                if(guess[i] == word[j]){
                    found = 1;
                    break;
                }
            }

            if(found)
                printf("%c est dans le mot mais a la mauvaise place\n", guess[i]);
            else
                printf("%c ne se trouve pas dans le mot\n", guess[i]);
        }
    }
}

int main(){
    int count = read_dictoinary(word, "words.txt");
    if(count == 0){
        return 1;
    }

    // choisir aleatoirement un mot du fichier
    srand(time(NULL));

    char tragect[WORD_LEN];
    strcpy(tragect , word[rand() % count]);

    printf("======WORDLE GAME====== \n");
    printf("vous avez %d tentative pour deviner le mot secret. \n", MAX_ATTEMPTS);

    for(int attempt = 0; attempt < MAX_ATTEMPTS; attempt++) {
        char guess[WORD_LEN];
        printf("tentative %d : ", attempt + 1);
        scanf("%5s", guess);
        feedback(guess, tragect);
        if (strcmp(tragect , guess) == 0){
            printf("BRAVO!, vous avez trouve le mot '%s' \n", tragect);
            return 0;
        }
    }

    printf("PERDU, le mot etait : %s", tragect);

    return 0;
}
