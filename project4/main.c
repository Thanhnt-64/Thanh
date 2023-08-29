#include<stdio.h>
enum Color{red, blue, green};
static const int max =5;
void print_color(){
    enum Color{red = 2, blue =3, green =4};
    printf("print by print_color function: %d\n",red);
    int max = 3;
    printf("%d\n",max);
}
int main(){
    print_color();
    printf("print by main: %d", red);
    return 0;
}