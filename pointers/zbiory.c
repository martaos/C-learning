/*      wzskaźniki i funkcje       */
/*      wyznaczanie wartosci w zbiorze      */
#include <stdio.h>

void kopiowanie(int *, int *, int);
void sumowanie(const int *, const int*, int *, int);
void wyswietlanie(const int *, int);
void podwajanie(int *, int);
void zapis(int *);
float srednia_zbiory(int *, int);
float srednia_wszystko(int *, int, int);
int najwieksza(int *, int, int);

int main(){
  /*int tab1[3][4] = {{10, 11, 13, 12},
                    {14, 16, 12, 17},
                    {16, 17, 19, 20}};
  int tab2[3][4];
  int * ptr1, * ptr2;
  ptr1 = tab1[0];
  ptr2 = tab2[0];
  for(int i = 0; i < 3; i++){
    kopiowanie((ptr1 + 4*i), (ptr2+4*i), 4);
  }
  for(int i = 0; i < 3; i++){
    for(int j = 0; j < 4; j++){
      printf("%d ", *((ptr2 + 4*i)+j));
    }
    putchar('\n');
  }*/
  /*int tab1[7] = {2, 5, 7, 3, 6, 2, 6};
  int tab2[3];
  int * wsk;
  wsk = tab1;
  int * wsk2;
  wsk2 = tab2;
  kopiowanie((wsk+2), wsk2, 3);
  for(int i = 0; i < 3; i++){
    printf("%d ", *(wsk2 + i));
  }
  putchar('\n');*/
  /*const int tab1[4] = {2, 4, 6, 0};
  const int tab2[4] = {-1, 6, 3, 2};
  int tab3[4];
  const int *ptr1, *ptr2;
  int *ptr3;
  ptr1 = tab1;
  ptr2 = tab2;
  ptr3 = tab3;
  sumowanie(ptr1, ptr2, ptr3, 4);
  for(int i = 0; i < 4; i++){
    printf("%d ", *(ptr3 + i));
  }
  putchar('\n');*/
  /*const tab[3][5] = {{2, 4, 7, 7, 3},
                      {1, 3 , 7, 2, 5},
                      {7, 3, 9, 0, 1}};
const int * ptr;
ptr = tab[0];
wyswietlanie(ptr, 3);*/

printf("Podaj trzy zbiory po 5 liczb kazdy\n");
int tab[3][5];
int (* ptr)[5];
ptr = &tab[0];

zapis(*ptr);
/*for(int i = 0; i < 3; i++){
  for(int j = 0; j < 5; j++){
    printf("%d ", *(*(ptr + i)+j));
  }
  putchar('\n');
}*/
for(int i = 0; i < 3; i++){
  printf("Srednia dla zbioru %d wynosi %.1f\n", i+1, srednia_zbiory(*(ptr + i), 5));
}
printf("Srednia dla wszystkich wynosi %.1f\n", srednia_wszystko(*ptr, 3, 5));
printf("Najwieksza wartosc posrod 15 wynosi %d\n", najwieksza(*ptr, 3, 5));
  return 0;
}

void kopiowanie(int * ptr1, int * ptr2, int n){
  for(int i = 0; i < n; i++){
    *(ptr2+i) = *(ptr1 + i);
  }
}

void sumowanie(const int * wsk1, const int * wsk2, int * wsk3, int n){
  for(int i = 0; i < n; i++){
    *(wsk3 + i) = *(wsk1 + i) + *(wsk2 + i);
  }
}

void zapis(int * ptr){
  int i = 0;
  while(i < 3*5 && scanf("%d", &(*(ptr + i))) == 1){
    i++;
  }
}

float srednia_zbiory(int * ptr, int n){
  int suma = 0;
  for(int i = 0; i < n; i++){
    suma += *(ptr+i);
  }
  return (float) suma/n;
}

float srednia_wszystko(int * ptr, int m, int n){
  int suma = 0;
  for(int i = 0; i < m; i++){
    for(int j = 0; j < n; j++){
      suma += *((ptr + j*i) + j);
    }

  }
  return (float) suma/(n*m);
}

int najwieksza(int * ptr, int m, int n){
  int max = *ptr;
  for(int i = 0; i < m; i++){
    for(int j = 0; j < n; j++){
      if(max < *((ptr + i*j) + j)){
        max = *((ptr + i*j) + j);
      }
      else
        continue;
    }
  }
  return max;
}
