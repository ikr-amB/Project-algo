#include <stdio.h> 
#include<stdlib.h>
#include<string.h>
#include<time.h>

#define WORD_LEN 5
#define MAX_ATTEMPTS 6
#define MAX_WORDS 1000000
 
int read_dictoinary(char W[][WORD_LEN] ){
    FILE f = fopen("words.txt" , "r");
    if( f == NULL){
        printf("erreur!!");
        return 0;
    }
int count = 0;
while(fsanf(f , "5%s", W[count]) == 1){
    for(int i = 0; i < WORD_LEN .){
        if(*p >= 'A' && *p <= 'Z'){
            *p += 32;
            count++;
        }
        if(count >= MAX_WORDS){
            break;
        }
    }
}
fclose(f);
return count;
}
