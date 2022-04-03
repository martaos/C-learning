/*          sprawdzanie ile razy znak wystapil w plikach        */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]){
  if(argc < 2){
    exit(EXIT_FAILURE);
  }
  else if(argc == 2){
    char c = *argv[1];
    char str[256];
    int i = 0;
    int licznik = 0;
    while(fgets(str, 256, stdin) != NULL){
	while(i++ < strlen(str)){
        	if(*(str+i) == c)
        		 licznik++;
        	
       	 	else
         		continue;
       	}
	i = 0;
    }
    printf("%c wystapilo %d razy\n", c, licznik);
  }
  else{
 
   FILE *ptr;
   int j = 0, licznik = 0;
   char c = *argv[1];
   char str[256];

   for(int i = 2; i < argc; i++){
	if((ptr = fopen(argv[i], "r")) != NULL){
	
	
	while(fgets(str, 256, ptr) != NULL){
		while(j++ < strlen(str)){
			if(*(str+j) == c) licznik++;
			else continue;
		}
		j = 0;
	}

	printf("%c wystapilo %d razy w pliku %s\n", c, licznik, argv[i]);
	licznik = 0;

	if(fclose(ptr) == EOF){
		fprintf(stderr, "Blad przy zamykaniu pliku %s\n", argv[i]);
		exit(EXIT_FAILURE);
	}
	}
   }
}
  return 0;
}