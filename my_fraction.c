#include<stdio.h>
#include<stdlib.h>

#include"my_fraction.h"

my_fraction create(int numerator, int denominator) {
	return(numerator << 16) | denominator;
}
extern int find_gcd(int a, int b) {
	while (b != 0) {
		int tmp = b;
		b = a%b;
		a = tmp;
	}
	return a;
}

my_fraction reduce(my_fraction f) {
	int n = f >> 16;
	int d = f & 0xFFFF;

	int gcd = find_gcd(n, d);
	n /= gcd;
	d /= gcd;

	return create(n, d);
}

my_fraction add(my_fraction i, my_fraction j) {
	int n1 = i >> 16;
	int d1 = i & 0xFFFF;

	int n2 = j >> 16;
	int d2 = j & 0xFFFF;

	if (d1 == d2) {
		int n = n1 + n2;
		int d = d1;
		return (n << 16) | d;
	}
	else if (d1 != d2) {
		int n = n1 * d2 + n2 * d1;
		int d = d1 * d2;
		return (n << 16) | d;
	}

}
my_fraction minus(my_fraction i, my_fraction j) {
	int n1 = i >> 16;
	int d1 = i & 0xFFFF;

	int n2 = j >> 16;
	int d2 = j & 0xFFFF;

	if (d1 == d2) {
		int n = n1 - n2;
		int d = d1;
		return (n << 16) | d;
	}
	else if (d1 != d2) {
		int n = n1 * d2 - n2 * d1;
		int d = d1 * d2;
		return (n << 16) | d;
	}
}
my_fraction mult(my_fraction i, my_fraction j) {
	int n1 = i >> 16;
	int d1 = i & 0xFFFF;

	int n2 = j >> 16;
	int d2 = j & 0xFFFF;

	int n = n1 * n2;
	int d = d1 * d2;

	return(n << 16) | d;
}
my_fraction divid(my_fraction i, my_fraction j) {
	int n1 = i >> 16;
	int d1 = i & 0xFFFF;

	int n2 = j >> 16;
	int d2 = j & 0xFFFF;

	int n = n1 * d2;
	int d = n2 * d1;

	return (n << 16) | d;
}
void print(my_fraction f) {
	int n = f >> 16;
	int d = f& 0xFFFF;
	
	printf("%d/%d", n, d);
}
