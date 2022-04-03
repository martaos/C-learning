#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define ODPOWIEDZ "GRANT"
#define MAX 40

void duze_litery(char *);

int main(){
  char proba[MAX];
  puts("Kto jest pochowany w grobowcu Granta?");
  gets(proba);
  duze_litery(proba);
  while(strcmp(proba,ODPOWIEDZ) != 0){
    puts("Niestety to nie jest dobra odpowiedz. Sprobuj jeszcze raz");
    gets(proba);
    duze_litery(proba);
  }
  puts("Tak jest!");
  return 0;
}

void duze_litery(char * ptr){
  while(*ptr){
    *ptr = toupper(*ptr);
    ptr++;
  }
}
