#include <stdio.h>
#include <math.h>

int mandel(double, double);

int main (int argc, char **argv){
	double x, y;
	double height = 20.0;
	double width = 79.0;
	/*Iterated with sizing in mind for printed area */
	for(y = -1.0; y <= 1; y += (2 / height)){
		for(x = -2.0; x <= 1; x += (3 / width)){
			int c = mandel(x, y);
			/*Checks against termination value */
			if(c == 100){
				printf("*");
			}else {
				printf(" ");
			}
		}
		/*Autolab fix */
		printf("\n");
	}
		
}

int mandel(double c_real, double c_imag){
	int iter = 0;
	double zr = 0.0;
	double zi = 0.0;
	/*Check against formula or termination value */
	while (sqrt(zr * zr + zi * zi) < 2 && iter <= 100){
		double temp_zr = zr * zr - zi * zi + c_real;
		zi = 2 * zr * zi + c_imag;
		zr = temp_zr;
		++iter;
	}
	return iter - 1;
}
