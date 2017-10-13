#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include "caesar.h"
#include "vigenere.h"

int main(int argc, char **argv){
	int shift;
	char *keyword;
	FILE *fp = NULL;
	FILE *fpout = NULL;
	char *file_to_use = NULL;
	char *file_out = NULL;
	
	if(argc >= 5){
		//Assign a file to use instead of stdin
		file_to_use = argv[4];
		fp = fopen(file_to_use, "r");
	}else {
		fp = stdin;
	}
	
	if(argc >= 6){
		//Assign a file to use instead of stdout
		file_out = argv[5];
		fpout = fopen(file_out, "w");
	}

	/*if(file_to_use != NULL){
		//File location not specified ... use stdin
		fp = stdin;
	}else {
		//File location was specified ... read from file_to_use
		fp = fopen(file_to_use, "r");
	}*/
	
	char buffer[256];
	char *fgets_return = NULL;
	do {
		fgets_return = fgets(buffer, 256, fp);
		if(fgets_return != NULL){
			if(strcmp(argv[1], "-e") == 0 && strcmp(argv[2], "-c") == 0){
				//Encryption using a caesar cipher with shift of argv[3]
				shift = atoi(argv[3]);
				caesar_encrypt(buffer, shift);
			}
			if(strcmp(argv[1], "-d") == 0 && strcmp(argv[2], "-c") == 0){
				//Decryption for caesar cipher with an unshift of argv[3]
				shift = atoi(argv[3]);
				caesar_decrypt(buffer, shift);
			}
			if(strcmp(argv[1], "-e") == 0 && strcmp(argv[2], "-v") == 0){
				//Encryption using vigenere cipher with keyword of argv[3]
				keyword = argv[3];
				vigenere_encrypt(buffer, keyword);
			}
			if(strcmp(argv[1], "-d") == 0 && strcmp(argv[2], "-v") == 0){
				//Decryption for vigenere cipher with keyword of argv[3]
				keyword = argv[3];
				vigenere_decrypt(buffer, keyword);
			}
			if(argc >= 6){
				//Print out to optional external file argument
				fprintf(fpout, "%s", buffer);
			}else {
				//Print the encoded or decoded string of characters
				printf("%s", buffer);
			}
		}
	}while(fgets_return != NULL);
	if(argc >= 6){
		//Close FILE loctions
		fclose(fpout);
	}
	fclose(fp);
	return 0;
}
