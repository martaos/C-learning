/*  dodawanie linijek z dwoch plikow na zakladke */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, int argv[]){
    if(argc != 3){
  exit(EXIT_FAILURE);
}

FILE *first, *second;
char str1[255], str2[255];
char * ptr1,  * ptr2;

if(((first = fopen(argv[1], "r")) == NULL) || ((second = fopen(argv[2], "r")) == NULL)){
  fprintf(stderr, "Blad przy otwieraniu plikow %s i %s\n", argv[1], argv[2]);
  exit(EXIT_FAILURE);
}

while(1){
  ptr1 = fgets(str1, 255, first);
  ptr2 = fgets(str2, 255, second);

  if(!(ptr1 || ptr2)){
    exit(EXIT_SUCCESS);
  }
  else{
    if(ptr1 != NULL && ptr2 != NULL){
        fputs(str1, stdout);
        fputs(str2, stdout);
    }
    else if(ptr1 == NULL){
      fputs(str2, stdout);
    }
    else if(ptr2 == NULL){
      fputs(str1, stdout);
    }
  }

    return 0;
}
