#ifndef WORDLEGAME_H_INCLUDED
#define WORDLEGAME_H_INCLUDED

#define WORD_LEN 6
#define MAX_ATTEMPTS 6
#define MAX_WORDS 1000000

//PART1:WORDLE GAME
int read_dictoinary(char words[][WORD_LEN], const char *filename);
void feedback(char guess[], char word[], char fb[]);

void play_game();

//PART2:SOLVER
int match_feedback(char word[], char guess[], char fb[]);
#endif
