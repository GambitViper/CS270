#include <stdio.h>
#include <math.h>

void pfact(int);

void no_two_factor(int, int);

int main (int argc, char **argv){
	int num = atoi(argv[1]);
	printf("%d = ", num);
	pfact(num);
	printf("\n");
}

void pfact(int start_num){
	int sum = 0;
	/*Divide by 2 as a base check */
	while (start_num % 2 == 0){
		sum++;
		start_num /= 2;
	}
	if(sum > 1){
		printf("2^%d ", sum);
	}else if(sum == 1){
		printf("2 ");
	}
	int i;
	/*Check other divisors */
	for (i = 3; i <= start_num; i += 2){
		int sum_i = 0;
		while(start_num % i == 0){
			++sum_i;
			start_num /= i;
		}
		if (sum == 0){
			++sum;
			no_two_factor(i, sum_i);
		}else {
			/*Case 2 and 3 of printing */
			if(sum_i != 0 && sum_i > 1){
				printf("* %d^%d ", i, sum_i);
			}
			if(sum_i != 0 && sum_i == 1){
				printf("* %d ", i);
			}
		}
	}
}

void no_two_factor(int i, int sum_i){
	/*Print Statement if non-divisible by 2 */
	if(sum_i != 0 && sum_i > 1){
		printf("%d^%d ", i, sum_i);
	}
	if(sum_i != 0 && sum_i == 1){
		printf("%d ", i);
	}
}
