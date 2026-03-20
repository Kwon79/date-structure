#include<stdio.h>
#include<stdlib.h>

#include"my_rectangle.h"

my_rectangle create(int numerator, int denominator) {
	return (numerator << 16) | denominator;
}

my_rectangle perimeter(my_rectangle a, my_rectangle b) {
	int n1 = a >> 16;
	int d1 = a & 0xFFFF;

	int n2 = b >> 16;
	int d2 = b & 0xFFFF;

	if (d1 == d2) {
		int n = n1*2+n2*2;
		int d = d1;
		return (n << 16) | d;
	}
	else if (d1 != d2) {
		int n = (n1 * d2)*2 + (n2 * d1)*2;
		int d = d1 * d2;
		
		return (n << 16) | d;
	}

}
my_rectangle area(my_rectangle a, my_rectangle b) {
	int n1 = a >> 16;
	int d1 = a & 0xFFFF;

	int n2 = b >> 16;
	int d2 = b & 0xFFFF;

	int n = n1 * n2;
	int d = d1 * d2;

	return(n << 16) | d;
}
my_rectangle reduce(my_rectangle f) {
	int a = f >> 16;
	int b = f & 0xFFFF;

	int gcd = find_gcd(a, b);
	a /= gcd;
	b /= gcd;

	return create(a, b);
}
int find_gcd(int a, int b) {
	while (b != 0) {
		int tmp = b;
		b = a % b;
		a = tmp;
	}
	return a;
}

void print(my_rectangle f) {
	int n = f >> 16;
	int d = f & 0xFFFF;

	printf("%d/%d", n, d);
}
