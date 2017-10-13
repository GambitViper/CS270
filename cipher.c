#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include "caesar.h"
#include "vigenere.h"

int main(int argc, char **argv){
	int shift;
	char *keyword;
	FILE *fp;
	FILE *fpout;
	char *file_to_use;
	char *file_out;

	if(argc >= 4){
		if(strcmp(argv[1], "-e") == 0 && strcmp(argv[2], "-c") == 0){
		//Encryption with a caesar cipher
			shift = atoi(argv[3]);
		}else if(strcmp(argv[1], "-d") == 0 && strcmp(argv[2], "-c") == 0){
		//Decryption for a caesar cipher
			shift = atoi(argv[3]);
		}else if(strcmp(argv[1], "-e") == 0 && strcmp(argv[2], "-v") == 0){
		//Encryption with a vigenere cipher
			keyword = argv[3];
		}else if(strcmp(argv[1], "-d") == 0 && strcmp(argv[2], "-v") == 0){
		//Decryption for a vigenere cipher
			keyword = argv[3];
		}else {
			printf("invalid syntax ...");
			return -1;
		}
	}
	
	if(argc == 5){
		file_to_use = argv[4];
	}
	
	if(argc == 6){
		file_out = argv[5];
		fpout = fopen(file_out, "w");
	}

	if(file_to_use == NULL){
		fp = stdin;
	}else {
		fp = fopen(file_to_use, "r");
	}
	
	char buffer[256];
	char *fgets_return = NULL;
	do
	{
		fgets_return = fgets(buffer, 256, fp);
		if(fgets_return != NULL){
			if(strcmp(argv[1], "-e") == 0 && strcmp(argv[2], "-c") == 0){
				//shift = atoi(argv[3]);
				caesar_encrypt(buffer, shift);
			}
			if(strcmp(argv[1], "-d") == 0 && strcmp(argv[2], "-c") == 0){
				//shift = atoi(argv[3]);
				caesar_decrypt(buffer, shift);
			}
			if(strcmp(argv[1], "-e") == 0 && strcmp(argv[2], "-v") == 0){
				//keyword = argv[3];
				vigenere_encrypt(buffer, keyword);
			}
			if(strcmp(argv[1], "-d") == 0 && strcmp(argv[2], "-v") == 0){
				//keyword = argv[3];
				vigenere_decrypt(buffer, keyword);
			}
			if(argc == 6){
				fprintf(fpout, "%s", buffer);
			}else {
				printf("%s", buffer);
			}
		}
	}while(fgets_return != NULL);
	if(file_out != NULL){
		fclose(fpout);
	}
	return 0;
}
