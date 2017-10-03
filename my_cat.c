#include <stdio.h>
#include <string.h>
#include <ctype.h>

void dump_file(const char *);

int main(int argc, char **argv){
	int i;
	if(argc == 1){
		dump_file("-");
	}else {
		for(i = 1; i < argc; ++i){
			dump_file(argv[i]);
		}
	}
	return 0;
}

void dump_file(const char *name){
	FILE *fp;
	if(strcmp(name, "-") == 0){
		fp = stdin;
	}else {
		fp = fopen(name, "r");
	}
	do{
		char val = fgetc(fp);
		if (val != EOF){
			printf("%c", val);
		}
	}while(!feof(fp));
	if(fp != stdin){
		fclose(fp);
	}
	return;
}
