#include "caesar.h"
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

void caesar_encrypt(char *input, int shift){
	int i;
	for(i = 0; i < strlen(input); ++i){
		//Grab character from the input
		char to_encode = input[i];
		//Convert to int for math
		int secure = to_encode;
		if(isalpha(to_encode)){
			int iter;
			//Loop for finding new int position for encoded char
			for(iter = 0; iter < shift; ++iter){
				++secure;
				//Hard skips over no-go zones
				if(secure == 91){
					secure = 97;
				}
				if(secure == 123){
					secure = 65;
				}
			}
		}
		//Write out encoded character back at original index
		input[i] = secure;
	}
	return;
}
		
void caesar_decrypt(char *encoded, int shift){
	int i;
	for(i = 0; i < strlen(encoded); ++i){
		//Grab character from the encoded
		char to_decode = encoded[i];
		//Convert to int for math
		int secure = to_decode;
		if(isalpha(to_decode)){
			int iter;
			//Loop through in reverse shift for decoded char
			for(iter = 0; iter < shift; ++iter){
				--secure;
				//Hard skips over no-go zones
				if(secure == 96){
					secure = 90;
				}
				if(secure == 64){
					secure = 122;
				}
			}
		}
		//Write out decoded character back at original index
		encoded[i] = secure;
	}
	return;
}

		
		
