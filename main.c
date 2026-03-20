#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

#include"my_math.h"

int main() {
	char input[100];
	printf("input two number: ");
	fgets(input, sizeof(input), stdin);

	int a, b;

	int iserror=sscanf(input, "%d %d", &a,&b);

	if (iserror!= 2) {
		printf("error");
		return 1;
	}

	if (a <0 || b <0) {
		printf("error");
		return 1;
	}
	if (a == 0 && b == 0) {
		printf("error");
		return 1;
	}

	my_math gcd = find_Gcd(a, b);
	my_math Lcm = find_Lcm(a, b);
	
	printf("GCD: %d,LCM: %d", gcd, Lcm);
	
	return 0;
}
