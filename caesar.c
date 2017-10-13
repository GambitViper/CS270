#include "caesar.h"
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

//void caesar_decode(char *, int);
//void caesar_encrypt(char *, int);

/*int main(int argc, char **argv){
	char *input = "ABCDEFGHIJKLMNOPQRSTUVWXYZ abcdefghijklmnopqrstuvwxyz";
	int shift = 25;
	char *encoded = caesar_encrypt(input, shift);
	caesar_decode(encoded, shift);
	return 0;
}*/

void caesar_encrypt(char *input, int shift){
	//char *out = strdup(input);
	int i;
	for(i = 0; i < strlen(input); ++i){
		char to_encode = input[i];
		int secure = to_encode;
		if(isalpha(to_encode)){
			/*to_encode += shift;
			if(secure > 90 && secure < 97){
				int diff = secure - 90;
				to_encode = 96 + diff + 5;
			}
			if(secure > 122){
				int diff = secure - 122;
				to_encode = 64 + diff;
			}*/
			int iter;
			for(iter = 0; iter < shift; ++iter){
				++secure;
				if(secure == 91){
					secure = 97;
				}
				if(secure == 123){
					secure = 65;
				}
			}
		}
		input[i] = secure;
	}
	//printf("In:  %s\n", input);
	//printf("Out: %s\n", out);
	return;
}
		
void caesar_decrypt(char *encoded, int shift){
	//char *decoded = strdup(encoded);
	int i;
	for(i = 0; i < strlen(encoded); ++i){
		char to_decode = encoded[i];
		int secure = to_decode;
		if(isalpha(to_decode)){
			/*
			if(secure > 90 && secure < 97){
				int diff = secure - 90;
				to_decode = 96 + diff;
			}
			if(secure > 122){
				int diff = secure - 122;
				to_decode = 64 + diff;
			}*/
			int iter;
			for(iter = 0; iter < shift; ++iter){
				--secure;
				if(secure == 96){
					secure = 90;
				}
				if(secure == 64){
					secure = 122;
				}
			}
		}
		encoded[i] = secure;
	}
	//printf("Encoded: %s\n", encoded);
	//printf("Decoded: %s\n", decoded);
	return;
}

		
		
