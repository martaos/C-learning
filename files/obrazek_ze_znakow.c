/*      rysowanie obrazka ze znakow na podsawie pliku z cyframi     */
/*      wymaga pliku tablica.txt                                    */

#include <stdio.h>
#include <stdlib.h>

void poprawaJakosci(int tab[][30]);

int main(int argc, char *argv[]){
	if(argc != 2){
		exit(EXIT_FAILURE);
	}
	char *plik;
	plik = argv[1];
	FILE *ptr;
	int tab[20][30];
	int a;
	char c;

	if((ptr = fopen(plik, "r+")) == NULL){
			fprintf(stderr, "Blad przy otwieraniu pliku");
			exit(EXIT_FAILURE);
	}	
	for(int i = 0; i < 20; i++){
		for(int j = 0; j < 30; j++){
				fscanf(ptr, "%d ", &a);
				tab[i][j] = a;
		}
	}

	for(int i = 0; i < 20; i++){
		for(int j = 0; j < 30; j++){
			printf("%d ", tab[i][j]);
		}
		putchar('\n');
	}
	putchar('\n');

	if(fclose(ptr) == EOF){
			fprintf(stderr, "Blad przy zamykaniu pliku");
			exit(EXIT_FAILURE);
	}
	poprawaJakosci(tab);

	char tab2[20][31];

	for(int i = 0; i < 20; i++){
		for(int j = 0; j <30; j++){
			switch(tab[i][j]){
				case 0: c = ' '; break;
				case 1: c = '.'; break;
				case 2: c = '\''; break;
				case 3: c = ':'; break;
				case 4: c = '~'; break;
				case 5: c = '*'; break;
				case 6: c = '='; break;
				case 7: c = '$'; break;
				case 8: c = '%'; break;
				case 9: c = '#'; break;
			}
			tab2[i][j] = c;
		}
		tab2[i][30] = '\0';
	}

	if((ptr = fopen("obrazek.txt", "w+")) == NULL){
			fprintf(stderr, "Blad przy otwieraniu pliku");
			exit(EXIT_FAILURE);
	}

	for(int i = 0; i < 20; i++){
		fprintf(ptr, "%s\n", tab2[i]);
	}

	if(fclose(ptr) == EOF){
		fprintf(stderr, "Blad przy zamykaniu pliku");
		exit(EXIT_FAILURE);
	}
	
	return 0;
}

void poprawaJakosci(int tab[][30]){
	for(int i = 1; i < 19; i++){
		for(int j = 1; j < 29; j++){
			if((abs(tab[i][j] - tab[i-1][j]) > 1) && (abs(tab[i][j] - tab[i+1][j]) > 1) && (abs(tab[i][j] - tab[i][j+1]) > 1) && (abs(tab[i][j] - tab[i][j-1]) > 1)){
				tab[i][j] = (tab[i+1][j] + tab[i-1][j] + tab[i][j-1] + tab[i][j+1])/4; 
			}
		}
	}
	for(int j = 1; j < 29; j++){
		int i = 0;
		if((abs(tab[i][j] - tab[i][j+1]) > 1) && (abs(tab[i+1][j] - tab[i][j]) > 1) && (abs(tab[i][j] - tab[i][j-1]) > 1)){
				tab[i][j] = (tab[i][j+1] + tab[i+1][j] + tab[i][j-1])/3;
		}
		i = 19;
		if((abs(tab[i][j] - tab[i][j+1]) > 1) && (abs(tab[i-1][j] - tab[i][j]) > 1) && (abs(tab[i][j] - tab[i][j-1]) > 1)){
				tab[i][j] = (tab[i][j+1] + tab[i-1][j] + tab[i][j-1])/3;
		}
	}
	for(int i = 1; i < 19; i++){
		int j = 0;
		if((abs(tab[i][j] - tab[i][j+1]) > 1) && (abs(tab[i-1][j] - tab[i][j]) > 1) && (abs(tab[i][j] - tab[i+1][j]) > 1)){
				tab[i][j] = (tab[i][j+1] + tab[i+1][j] + tab[i-1][j])/3;
		}
		j = 29;
		if((abs(tab[i][j] - tab[i][j-1]) > 1) && (abs(tab[i-1][j] - tab[i][j]) > 1 )&& (abs(tab[i][j] - tab[i+1][j]) > 1 )){
				tab[i][j] = (tab[i][j-1] + tab[i-1][j] + tab[i+1][j])/3;
		}
	}
	if((abs(tab[0][0] - tab[0][1]) > 1) && (abs(tab[0][0] - tab[1][0]) > 1)){
		tab[0][0] = (tab[0][1] + tab[1][0])/2;
	}
	if((abs(tab[0][29] - tab[0][28]) > 1) && (abs(tab[0][29] - tab[1][29]) > 1)){
		tab[0][29] = (tab[0][28] + tab[1][29])/2;
	}
	if((abs(tab[19][0] - tab[19][1]) > 1) && (abs(tab[19][0] - tab[18][0]) > 1)){
		tab[19][0] = (tab[19][1] + tab[18][0])/2;
	}
	if((abs(tab[19][29] - tab[19][28]) > 1) && (abs(tab[19][29] - tab[18][29]) > 1)){
		tab[19][29] = (tab[19][28] + tab[18][29])/2;
	}
}