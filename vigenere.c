#include "vigenere.h"
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

//void vigenere_encrypt(char *, char *);
//void vigenere_decrypt(char *, char *);

/*int main(int argc, char **argv){
	char *input = "ABCDE WXYZ abcde wxyz";
	char *keyword = "LemoN";
	char *encoded = vigenere_encrypt(input, keyword);
	vigenere_decrypt(encoded, keyword);
	return 0;
}*/

void vigenere_encrypt(char *input, char *keyword){
	//char *out = strdup(input);
	int i;
	int shift;
	int index_key = 0;
	for(i = 0; i < strlen(input); ++i){
		if(index_key >= strlen(keyword)){
			index_key = 0;
		}
		if(islower(keyword[index_key])){
			shift = toupper(keyword[index_key]) - 38;
		}else{
			shift = keyword[index_key] - 64;
		}
		char to_encode = input[i];
		int secure = to_encode;
		if(isalpha(to_encode)){
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
			++index_key;	
		}
		input[i] = secure;
	}
	//printf("In : %s\n", input);
	//printf("Out: %s\n", out);
	return;
}

void vigenere_decrypt(char *input, char *keyword){
	//char *out = strdup(input);
	int i;
	int shift;
	int index_key = 0;
	for(i = 0; i < strlen(input); ++i){
		if(index_key >= strlen(keyword)){
			index_key = 0;
		}
		if(islower(keyword[index_key])){
			shift = toupper(keyword[index_key]) - 38;
		}else{
			shift = keyword[index_key] -64;
		}
		char to_decode = input[i];
		int secure = to_decode;
		if(isalpha(to_decode)){
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
			++index_key;
		}
		input[i] = secure;
	}
	//printf("Encoded: %s\n", input);
	//printf("Decoded: %s\n", out);
	return;
}
