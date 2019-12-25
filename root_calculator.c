#include <stdio.h>
#include <math.h>
#include "root_calculator.h"

void root_calculator() {
	int input_num;
	double root;
	printf("Enter a number: ");
	scanf("%d", &input_num);
	root = sqrt(input_num);
	printf("\nRoot of %d is %0.3f\n", input_num, root);
	
}

