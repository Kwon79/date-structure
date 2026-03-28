#include<stdio.h>
#include<stdlib.h>

#include"my_math.h"

my_math find_Gcd(my_math a, my_math b) {
	while ( b!= 0) {
		int tmp = b;
		b = a % b;
		a = tmp;
	}
	return a;
}
my_math find_Lcm(my_math a, my_math b) {
	
		int gcd = find_Gcd(a, b);
		int Lcm = a / gcd * b;
		return Lcm;
	
}

