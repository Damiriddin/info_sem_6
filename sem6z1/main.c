#include <stdio.h>

// T - is type of var;

#define SWAP(x, y, T) do { T temp = x; x = y; y = temp; } while(0)

int main() {

    //For T == int
   int a = 10, b = 20;
   SWAP(a, b, int);
   printf("a = %d, b = %d\n", a, b);

    //For T == double
   double c = 3.14, d = 2.71;
   SWAP(c, d, double);
   printf("c = %.2f, d = %.2f\n", c, d);

    // For T == char
   char e = 'a', f = 'b';
   SWAP(e, f, char);
   printf("e = %c, f = %c\n", e, f);

   return 0;
}
