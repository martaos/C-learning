/*      moja wlasna implementacja strlen()      */
/*      odwracanie lancuchow i usuwanie znakow z nich   */

#include <stdio.h>
#include <string.h>

int strlen_moj(char *);
char * odwroc(char *);
char * usun(char *);

int main(){
    char zdanie[] = "Marta Gralak jest okej.";
    printf("Dlugosc łancucha wg gotowej funkcji: %ld\n", strlen(zdanie));
    printf("Długość łańcucha: %d\n", strlen_moj(zdanie));

    char str[] = "Natasza";
    printf("%ld", strlen(str));
    fputs(odwroc(str), stdout);
    putchar('\n');*/

    char str1[81];
  do{
    fgets(str1, sizeof(str1), stdin);
    fputs(usun(str1), stdout);
  } while(*str1 != '\n');

  return 0;
}

int strlen_moj(char * ptr){
  int i = 0;
  while(*(ptr++)){
    i++;
  }
  return i;
}

char * odwroc(char * str){
  int temp;
  int i;
  int n = strlen(str)-1;
    for(i = 0; n%2 ? i <= n/2. : i < n/2.; i++){
      temp = *(str+n-i);
      *(str+n-i) = *(str+i);
      *(str+i) = temp;
    }

  return str;
}

char * usun(char * str){
  int i = 0, j;
  for(i = 0; i < strlen(str); i++){
    if(*(str+i) == ' '){
    j = i;
      while(j < strlen(str)){
      if(*(str+j+1) != '\0'){
        *(str+j) = *(str+j+1);
      }
      else{
        *(str+j) = '\0';
      }
      j++;
      }
    }
    else
      continue;
  }
  return str;
}