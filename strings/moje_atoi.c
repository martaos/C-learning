/* definiowanie wlasnych funkcji z bibliotek */
/*      poczatek          */
/* moje atoi()      */

#include <stdio.h>
#include <ctype.h>
#include <string.h>

void liczydlo(char *, int);
void odwroc(char *, int);
double potegowanie(double, int);
int moje_atoi(char *, int);

int main(){
  /*char str[81];
  fgets(str, sizeof(str), stdin);
  liczydlo(str, strlen(str));*/

   /*char str[81];
  fgets(str, sizeof(str), stdin);
  odwroc(str, strlen(str));
  return 0;*/

   /*printf("Podaj wykladnik i podstawe liczby\n");
  double index;
  int base;
  scanf("%lf %d", &index, &base);
  printf("Liczba %d do potegi %.1lf wynosi %.1lf\n", base, index, potegowanie(index, base));*/

 
  char str[81];
  printf("Podaj lancuch do konwersji\n");
  fgets(str, sizeof(str), stdin);
  printf("%spo konwersji to %d\n", str, moje_atoi(str, strlen(str)));
}

void liczydlo(char *ptr, int n){
  int slowa = 0, liczby = 0, male = 0, duze = 0, znaki = 0;
  for(int i = 0; i < n; i++){
    if(*(ptr+i) == ' '){
      slowa++;
    }
    else if(isdigit(*(ptr+i))){
      liczby++;
    }
    else if(ispunct(*(ptr+i))){
      znaki++;
    }
    else if(isupper(*(ptr+i))){
      duze++;
    }
    else if(islower(*(ptr+i))){
      male++;
    }
    else
      continue;
  }
  slowa++;
  printf("Liczba slow %d\nLiczba wielkich liter %d\nLiczba malych liter %d\n", slowa, duze, male);
  printf("Liczba znakow przestankowych %d\nLiczba cyfr %d\n", znaki, liczby);
}
void odwroc(char * ptr, int n){
  int koniec = n-2, start;

  for(int i = n-2; i >= 0; i--){
    if(*(ptr+i) == ' ' || i == 0){
      if(i == 0){
        start = 0;
      }
      else{
        start = i+1;
      }
      for(int j = start; j <= koniec; j++){
        printf("%c", *(ptr+j));
      }
      koniec = i-1;
      putchar(' ');
    }
  }
}
double potegowanie(double index, int base){
  double wynik = 1;
   if(index >= 1){
     for(int i = 1; i <= index; i++){
       wynik *= base;
     }
    return wynik;
   }
   else if(index == 0){
     return 1;
   }
   else if(index < -1){
     for(int i = index; i <= -1; i++){
       wynik *= (1./base);
     }
     return wynik;
   }
   else if(base == 0){
     return 0;
   }
}
int moje_atoi(char * ptr, int n){
  int i = 0;
  int val = 0;
  while(i < n-1){
    if(isalnum(*(ptr+0))){
      if(isdigit(*(ptr+i))){
        val = val*10 + *(ptr+i) - '0';
      }
    }
    else{
      return 0;
    }
    i++;
  }
  return val;
}
