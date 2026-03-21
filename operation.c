#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#include"my_fraction.h"

int main() {
    char input[100];

    printf("Please enter the fraction calculation (Available characters:+,-,*,/): ");
    fgets(input, sizeof(input), stdin);
    input[strcspn(input, "\n")] = 0;

    char* token1 = strtok(input, " ");
    char* token2 = strtok(NULL, " ");
    char* token3 = strtok(NULL, " ");

    if (token1 == NULL || token2 == NULL || token3 == NULL) {
        printf("error");
        return 1;
    }

    my_fraction fra1 = parse(token1);
    char op = token2[0];
    my_fraction fra2 = parse(token3);

    my_fraction result = 0;

    switch (op) {
    case '+':
        result = add(fra1, fra2);
        break;
    case '-':
        result = minus(fra1, fra2);
        break;
    case '*':
        result = mult(fra1, fra2);
        break;
    case '/':
        result = divid(fra1, fra2);
        break;
    default:
        printf("error operator!");
        return 1;
    }

    my_fraction final = reduce(result);
    print(final);

    return 0;
}
