#ifndef WORDLEGAME_H_INCLUDED
#define WORDLEGAME_H_INCLUDED

#define WORD_LEN 6

int read_dictoinary(char words[][WORD_LEN], const char *filename);
void feedback(char guess[], char word[]);

#endif
