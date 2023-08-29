#include<stdio.h>
void myfunc(int *para1, 
            const int *para2,
            const int *para3, 
            const int *para4)
{
    *para1 = *para2 + *para3 + *para4;
    
    printf("%d\n", *para1);
}
int main(){
    int a;
    const int b = 5;
    const int c = 6;
    const int d = 7;
    myfunc(&a,&b,&c,&d);
    return 0;
}