#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

#include"my_rectangle.h"

my_rectangle create(int numerator, int denominator) {
	return (numerator << 16) | denominator;
}

my_rectangle parse(char* str) {
	int n=0,d = 0;

	if (strchr(str, '/')) {
		sscanf(str,"%d/%d",&n, &d);
		if (d == 0) {
			printf("error!");
			exit(1);
		}
	}
	else if (strchr(str, '.')) {
		double val;
		sscanf(str, "%lf", &val);
		char* dot = strchr(str, '.');
		int count = (int)strlen(dot)-1;
		d = 1;
		for (int i = 0; i < count;i++) {
			d *= 10;
		}
		n = (int)round(val * d);
	}
	else {
		sscanf(str, "%d", &n);
		d = 1;
	}

	if (n <= 0 || d <= 0) {
		printf("error");
		exit(1);
	}

	return create(n, d);
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


	if (d == 1) { printf("%d", n); }
	else { printf("%d/%d", n, d); }
}
