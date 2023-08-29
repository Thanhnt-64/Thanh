#include <stdio.h>
int main(){
    int a =10, a1;
    int b =5, b1;
    a1 = ++a;
    b1 = b++;
    printf("Pre-increment: first ++a => a = %d, then a1 = a = %d\n",a,a1);
    printf("Post-increment: first b1 = b = %d, then b++ => b = %d\n",b1,b);
    return 0;
}