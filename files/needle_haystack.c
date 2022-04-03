/*      szuka pierwszego wystapienia lancucha w innym lanuchu       */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(int argc, char *argv[]){
	if(argc != 3){
		exit(EXIT_FAILURE);
	}
	char *str;
	str = argv[1];
	char *plik = argv[2];
	FILE *ptr;
	char *ret, *line;
	if((ptr = fopen(plik, "r+")) == NULL){
		fprintf(stderr, "Blad przy otwieraniu pliku.\n");
		exit(EXIT_FAILURE);	
	}
	while(!feof(ptr)){
		if(fgets(line, 256, ptr) != NULL){
			if((ret = strstr(line, str)) != NULL){
				printf("%s", ret);
			}
		}
	}
	if(fclose(ptr) == EOF){
		fprintf(stderr, "Blad przy zamykaniu pliku \"slowka.txt\".\n");
	}
	return 0;
}
