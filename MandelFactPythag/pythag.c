#include <stdio.h>
#include <math.h>

double calc_c(int, int);

int main (int argc, char **argv){
	int a, b;
	double c;
	for(b = 1; b <= 60; ++b){
		for(a = 1; a <= 60; ++a){
			c = calc_c(a, b);
			if(c == (int) c && a < b){
				/*If checked as an integer print values */
				printf("triple: %d %d %d\n", a, b,(int) c);
			}
		}
	}
			
}

double calc_c(int a, int b){
	/*Calculation work for c */
	double c;
	c = sqrt(a * a + b * b);
	return c;
}

