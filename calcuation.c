#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

#include"my_rectangle.h"

int main(int c, char** v) {

	if (c != 3) {
		printf("Usage: %s <num1> <num2>\n", v[0]);
		return 1;
	}

	int n1,d1=0;
	int n2, d2 = 0;

	sscanf(v[1], "%d/%d", &n1, &d1);
	sscanf(v[2], "%d/%d", &n2, &d2);


	if (d1 == 0 || d2 == 0) {
		printf("error");
		return 1;
	}
	if (n1 < 0 || d1 < 0 || n2 < 0 || d2 < 0) {
    printf("error");
    return 1;
}

	my_rectangle fra1=create(n1,d1);
	my_rectangle fra2= create(n2, d2);

	my_rectangle Area=area(fra1, fra2);
	my_rectangle Perimeter = perimeter(fra1, fra2);

	my_rectangle resultArea = reduce(Area);
	my_rectangle resultPerimeter = reduce(Perimeter);

	printf("Perimeter:");
	print(resultPerimeter);
	printf(", Area:");
	print(resultArea);
	return 0;
}
