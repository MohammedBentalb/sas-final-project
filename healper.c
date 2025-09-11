#include "header.h"


void clearInput(){
    int c;
    while((c = getchar()) != '\n' && c != EOF);
}


int acceptUserInput(){
    int number = -1;
    scanf("%d", &number);
    clearInput();
    
    return number;
}
