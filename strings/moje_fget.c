/*          moje fget()         */


#include <stdio.h>
#include <stdbool.h>
#include <string.h>

char * moje_fget(char *, int, FILE *);

int main(){
    int n;
    char zdanie[81], *ptr;
    ptr = moje_fget(zdanie, sizeof(zdanie), stdin);
    fputs(zdanie, stdout);
    return 0;
}

char * moje_fget(char * str, int n, FILE * input){
  int i = 0, c;
  if(n <= 0){
    return str;
  }
  while(i < n -1 && (c = getc(input)) != EOF){
    *(str+i) = c;
    i++;
    if(c == '\n' || c == '\t' || c == ' ')
      break;
  }
  *(str+i) = '\0';
  if(i > 0){
    return str;
  }
  else
    return NULL;
}