#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#include"my_rectangle.h"

int main(int c, char** v) {

	if (c != 3) {
		printf("Usage: %s <num1> <num2>\n", v[0]);
		return 1;
	}

	my_rectangle fra1 = parse(v[1]);
	my_rectangle fra2 = parse(v[2]);

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
