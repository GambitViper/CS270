#include "vigenere.h"
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

void vigenere_encrypt(char *input, char *keyword){
	int i;
	int shift;
	//Integar in charge of keeping track of position in the coding keyword
	int index_key = 0;
	for(i = 0; i < strlen(input); ++i){
		//Check for a loop back around in coding keyword || Input is larger than keyword
		if(index_key >= strlen(keyword)){
			index_key = 0;
		}
		//Maths to figure out shift value from the keyword
		if(islower(keyword[index_key])){
			shift = toupper(keyword[index_key]) - 38;
		}else{
			shift = keyword[index_key] - 64;
		}
		//Grab a character from the input to encode
		char to_encode = input[i];
		//Convert to int for maths
		int secure = to_encode;
		if(isalpha(to_encode)){
			int iter;
			//Loop for finding shifted position at an integar location
			for(iter = 0; iter < shift; ++iter){
				++secure;
				//Hard skips for no-go zones
				if(secure == 91){
					secure = 97;
				}
				if(secure == 123){
					secure = 65;
				}
			}
			//Advance key location for character encoding shift value
			++index_key;	
		}
		//Write out to the encoded string
		input[i] = secure;
	}
	return;
}

void vigenere_decrypt(char *input, char *keyword){
	int i;
	int shift;
	//Integar to keep track of position in keyword
	int index_key = 0;
	for(i = 0; i < strlen(input); ++i){
		//Loop back around on keyword
		if(index_key >= strlen(keyword)){
			index_key = 0;
		}
		//Maths to figure out shift value from the keyword
		if(islower(keyword[index_key])){
			shift = toupper(keyword[index_key]) - 38;
		}else{
			shift = keyword[index_key] -64;
		}
		//Grabs character from coded message to decode
		char to_decode = input[i];
		//Converts to int for maths
		int secure = to_decode;
		if(isalpha(to_decode)){
			int iter;
			//Loop for finding shifted int position
			for(iter = 0; iter < shift; ++iter){
				--secure;
				//Hard skip for no-go zones
				if(secure == 96){
					secure = 90;
				}
				if(secure == 64){
					secure = 122;
				}
			}
			//Advance lookup position in keyword
			++index_key;
		}
		//Write out to decoded
		input[i] = secure;
	}
	return;
}
