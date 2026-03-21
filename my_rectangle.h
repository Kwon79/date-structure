typedef unsigned int my_rectangle;

extern my_rectangle create(int numerator, int denominator);
extern my_rectangle perimeter(my_rectangle a, my_rectangle b);
extern my_rectangle area(my_rectangle a, my_rectangle b);
extern my_rectangle reduce(my_rectangle f);
extern my_rectangle parse(char* str);
extern int find_gcd(int a, int b);
extern void print(my_rectangle f);
