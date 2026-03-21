#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

#include"my_fraction.h"

my_fraction create(int numerator, int denominator) {
    if (denominator < 0) {
        numerator = -numerator;
        denominator = -denominator;
    }
    return (numerator << 16) | (denominator&0xFFFF);
}

int find_gcd(int a, int b) {
    while (b != 0) {
        int tmp = b;
        b = a % b;
        a = tmp;
    }
    return a;
}

my_fraction reduce(my_fraction f) {
    int n = (short)(f >> 16);
    int d = f & 0xFFFF;
    int gcd = find_gcd(n, d);
    n /= gcd;
    d /= gcd;
    return create(n, d);
}

my_fraction parse(char* str) {
    int n, d;
    if (strchr(str, '/')) {
        sscanf(str, "%d/%d", &n, &d);
        if (d == 0) {
            printf("error");
            exit(1);
        }
    }
    else if (strchr(str, '.')) {
        double val;
        sscanf(str, "%lf", &val);
        char* dot = strchr(str, '.');
        int count = (int)strlen(dot) - 1;
        d = 1;
        for (int i = 0; i < count; i++) {
            d *= 10;
        }
        n = (int)round(val * d);
    }
    else {
        sscanf(str, "%d", &n);
        d = 1;
    }
    return create(n, d);
}

my_fraction add(my_fraction i, my_fraction j) {
    int n1 = (short)(i >> 16), d1 = i & 0xFFFF;
    int n2 = (short)(j >> 16), d2 = j & 0xFFFF;
    if (d1 == d2) return ((n1 + n2) << 16) | d1;
    return ((n1 * d2 + n2 * d1) << 16) | (d1 * d2);
}

my_fraction minus(my_fraction i, my_fraction j) {
    int n1 = (short)(i >> 16), d1 = i & 0xFFFF;
    int n2 = (short)(j >> 16), d2 = j & 0xFFFF;
    if (d1 == d2) return ((n1 - n2) << 16) | d1;
    return ((n1 * d2 - n2 * d1) << 16) | (d1 * d2);
}

my_fraction mult(my_fraction i, my_fraction j) {
    int n1 = (short)(i >> 16), d1 = i & 0xFFFF;
    int n2 = (short)(j >> 16), d2 = j & 0xFFFF;
    return ((n1 * n2) << 16) | (d1 * d2);
}

my_fraction divid(my_fraction i, my_fraction j) {
    int n1 = (short)(i >> 16), d1 = i & 0xFFFF;
    int n2 = (short)(j >> 16), d2 = j & 0xFFFF;
    return ((n1 * d2) << 16) | (n2 * d1);
}

void print(my_fraction f) {
    int n = (short)(f >> 16);
    int d = f & 0xFFFF;
    if (d == 1)
        printf("%d", n);
    else
        printf("%d/%d", n, d);
}
