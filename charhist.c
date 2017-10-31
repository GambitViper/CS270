#include <stdio.h>
#include <string.h>
#include <ctype.h>

void row_orient(int *);

void col_orient(int *);

void collect_history(FILE *, int *);

int digit_count(int);

char digit_at_position(int, int);

int find_largest(int *);

int main(int argc, char **argv){
	FILE *fp;
	fp = stdin;
	int histogram[27];
	/*zero out the array*/
	int count;
	for(count = 0; count < 27; ++count){
		histogram[count] = 0;
	}
	collect_history(fp, histogram);
	/*Check for '-c' column oriented mode*/
	if(argc == 1 || strcmp(argv[1], "-r") == 0){//not specified or row oriented
		row_orient(histogram);
	}else if(strcmp(argv[1], "-c") == 0){//column oriented histogram
		col_orient(histogram);
	}
	return 0;
}

void row_orient(int *hist){
	int count;
	/*iterate through the alphabetical values of the histogram
	and associate the array value with the character*/
	for(count = 0; count < 26; ++count){
		printf("%c: %d\n", (char) (count + 65), hist[count]);
	}
	/*special *: case for non alphabetical chars*/
	printf("*: %d\n", hist[26]);
	return;	
}

void col_orient(int *hist){
	/*bottom line of column / legend*/
	int col_val = find_largest(hist);
	col_val = digit_count(col_val) - 1;
	int count;
	for(count = col_val; count >= 0; --count){
		int i;
		for(i = 0; i < 27; ++i){
			printf("%c ", digit_at_position(hist[i], count));
			if(i == 26){
				printf("\n");
			}
		}
	}
	for(count = 0; count < 26; ++count){
		printf("%c ", (char) (count + 65));
	}
	printf("*\n");
	return;
}

void collect_history(FILE *fp, int *hist){
	/*get each character in the input file (usually stdin)
	and sanitize to lowercase if alphabetical. 
	hard associate to pos 26 if non-alpha character*/
	do{
		char val = fgetc(fp);
		if(val != EOF){
			if(isalpha(val)){
				val = tolower(val);
			}
			/*calculate pos using ascii math*/
			int pos = val - 'a';
			if(!isalpha(val)){
				pos = 26;
			}
			if(!isspace(val)){
				/*increment histogram value for associated character skipping whitespace values*/
				hist[pos] += 1;
			}
		}
	}while(!feof(fp));
	return;
}

int digit_count(int val){
	/*returns the number of digits in val*/
	int num = 0;
	while(val > 0){
		val /= 10;
		++num;
	}
	return num;
}

char digit_at_position(int val, int i){
	/*return the i'th digit (0-based indexing) of val as a char*/
	char converted;
	if(i == 0){
		converted = (val % 10) + '0';
	}else {
		/*whitespace character used if i is out of range for val*/
		if(i > (digit_count(val) - 1)){
			converted = ' ';
		}else {
			int num;
			for(num = 0; num < i; ++num){
				val /= 10;
			}
			converted = (val % 10) + '0';
		}
	}
	return converted;
}

int find_largest(int *hist){
	int high = hist[0];
	int i;
	for(i = 1; i < 27; ++i){
		if(hist[i] > high){
			high = hist[i];
		}
	}
	return high;
}
