/*      moja implementacja strncpy()      */
/*      dodatkowo sprawdzanie zawierania sie lancuchow */

#include <stdio.h>
#include <stdbool.h>
#include <string.h>

char * moje_strncpy(char *, const char *, int);
char * zawiera_lan(char *, char *);

int main(){
    char str_1[80] = "Ala ma kota";
    char str_2[] = " a kot ma Ale";
    fputs(moje_strncpy(str_1,str_2,strlen(str_1)), stdout);
    putchar('\n');

    char str1[] = "Ala ma kota i psa";
    char str2[] = "kot";
    char str3[] = "kotwica";
    char *ptr;
    ptr = zawiera_lan(str1,str2);
    printf("%p", ptr);
    putchar('\n');
    printf("%p\n", &str1[7]);
    ptr = zawiera_lan(str1,str3);
    printf("%p",ptr);
    putchar('\n');
    return 0;
}

char * moje_strncpy(char * str1, const char * str2, int n){
  int i = n;
  int j = 0;
  while(i <= sizeof(str1) - n && *(str2+j) != '\0'){
    *(str1+i) = *(str2+j);
    i++;
    j++;
  }
  return str1;
}

char * zawiera_lan(char * str1, char * str2){
  int i = 0, j = 0, licznik = 0;
  char * ptr;
    for(j = 0; j <= strlen(str2); j++){
        for(i = 0; i <= strlen(str1); i++){
          if(*(str2+j) == *(str1+i) && *(str2+j) != '\0'){
            ptr = (str1+i);
            licznik++;
            break;
          }
          else
            continue;
        }
    }
  if(licznik == strlen(str2)){
    return (ptr - licznik + 1);
  }
  else
    return NULL;
}