#include <stdio.h>
#include  <string.h>

int menu();
void wyswietl(char *[], int);
void kolejnoscASCII(char *[], int);
void dlugosc(char *[], int);
void dlugosc_pierwsze(char *[], int);

int main(){
	char str[10][81];
	char * ptr[10];
	int i = 0;
	int opcja = 0;
fputs("Podaj mksymalnie 10 lancuchow lub pusta linie zeby zakonczyc wpisywanie\n", stdout);
while(i < 10 && fgets(str[i], sizeof(*str), stdin) && strlen(str[i]) != 1){ //wczytywanie lancuchow
	ptr[i] = str[i];
	i++;
}
while(opcja != 5){
	opcja = menu();
	switch(opcja){
		case 1:	wyswietl(ptr, i);
						break;
		case 2:	kolejnoscASCII(ptr, i);
						wyswietl(ptr, i);
						break;
		case 3: dlugosc(ptr, i);
						wyswietl(ptr, i);
						break;
		case 4: dlugosc_pierwsze(ptr, i);
						wyswietl(ptr, i);
						break;
		case 5: break;
		default: printf("Podaj liczbe w zakresie 1-5!\n");
	}
}
	return 0;
}

int menu(){
	int a;
	printf("Wybierz jedna z pieciu opcji\n");
	printf("1)wyswietlenie pierwotnej listy lancuchow\n2)wyswietlnenie lancuchow w kolejnosci ASCII\n");
	printf("3)wyswietlenie lanuchow wedlug dlugosci (rosnaco)\n4)wyswietlenie lancuchow wedlug dlugosci pierwszego slowa\n5)koniec\n");
	scanf("%d", &a);
	return a;
}
void wyswietl(char * ptr[], int i){
	for(int j = 0; j < i; j++){
		fputs(*(ptr+j), stdout);
	}
}
void kolejnoscASCII(char * ptr[], int i){
	char * temp;
	for(int j = 0; j < i-1; j++){
		for(int k = j+1; k < i; k++){
			if(strcmp(*(ptr+j),*(ptr+k))>0){
				temp = *(ptr+j);
				*(ptr+j) = *(ptr+k);
				*(ptr+k) = temp;
			}
		}
	}
}
void dlugosc(char * ptr[], int i){
	char * temp;
	for(int j = 0; j < i-1; j++){
		for(int k = j+1; k < i; k++){
			if(strlen(*(ptr+j))>strlen(*(ptr+k))){
				temp = *(ptr+k);
				*(ptr+k) = *(ptr+j);
				*(ptr+j) = temp;
			}
			else
				continue;
		}
	}

}
void dlugosc_pierwsze(char * ptr[], int i){
	char *  temp;
	int litery = 0, kolejnosc[i];
	for(int j = 0; j < i; j++){
		for(int l = 0; l < strlen(*(ptr+j)); l++){
			if(*(*(ptr+j)+l) != ' '){
				litery++;
			}
			else
				break;
		}
			kolejnosc[j] = litery;
			litery = 0;
	}
	for(int m = 0; m < i-1; m++){
		for(int n = m; n < i; n++){
			if(kolejnosc[n] < kolejnosc[m]){
				temp = *(ptr+n);
				*(ptr+n) = *(ptr+m);
				*(ptr+m) = temp;
			}
		}
	}
}
