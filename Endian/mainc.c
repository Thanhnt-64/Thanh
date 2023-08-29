#include <stdio.h>
#include "mathlib.h"

int main() {
    int a = 5;
    int b = 10;
    int result = sum(a, b);
    
    printf("Tổng của %d và %d là %d\n", a, b, result);
    
    return 0;
}