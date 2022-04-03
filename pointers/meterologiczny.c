/*    nauka wskaźniów   */
/*    zwraca ilość opadów w danym czasie    */
#include <stdio.h>

#define MIESIACE 12
#define LATA 5

float suma_rok(const float *, int);
float suma_miesiace(const float *, int);


const float deszcz[LATA][MIESIACE] = {{10.2, 8.1, 6.8, 4.2, 2.1, 1.8, 0.2, 0.3, 1.1, 2.3, 6.1, 7.4},
                                      {9.2, 9.8, 4.4, 3.3, 2.2, 0.8, 0.4, 0.0, 0.6, 1.7, 4.3, 5.2},
                                      {6.6, 5.5, 3.8, 2.8, 1.6, 0.2, 0.0, 0.0, 0.0, 1.3, 2.6, 4.2},
                                      {4.3, 4.3, 4.3, 3.0, 2.0, 1.0, 0.2, 0.2, 0.4, 2.4, 3.5, 6.6},
                                      {8.5, 8.2, 1.2, 1.6, 2.4, 0.0, 5.2, 0.9, 0.3, 0.9, 1.4, 7.2}};
int main(){
  const float (* ptr)[MIESIACE];
  ptr = &deszcz[0];
  float suma_lata = 0;

  printf("Suma opadow dla kazdego roku\n");
  putchar('\n');
  printf("ROK\t\tSUMA [cm]\n");
  for(int i = 0; i < 5; i++){
    printf("%d\t\t%.1f\n", 1995+i, suma_rok(*(ptr+i), MIESIACE));
    suma_lata += suma_rok(*(ptr+i), MIESIACE);
  }
  putchar('\n');
  printf("Srednia roczna wynosi %.1f cm.\n", suma_lata/LATA);
  putchar('\n');
  printf("Srednia dla kazdego miesiaca\n");
  putchar('\n');
  printf("MIESIAC\t\tILOSC OPADOW [cm]\n");
  for(int i = 0; i < MIESIACE; i++){
    printf("%d\t\t%.1f\n", i+1, (suma_miesiace((*ptr + i), LATA))/LATA);
  }
  return 0;
}
float suma_rok(const float * ptr2, int n){
  float suma = 0;
  for(int i = 0; i < n; i++){
    suma += *(ptr2 + i);
  }
  return suma;
}

float suma_miesiace(const float * ptr2, int n){
  float suma = 0;
  for(int i = 0; i < n; i++){
    suma += *(ptr2 + MIESIACE*i);
    //printf("Liczba dla %d roku wynosi %.1f\n", i, *(ptr2 + i*MIESIACE));
  }
  return suma;
}
