#include <stdio.h>
#include<stdlib.h>
struct myName{
    char *name;
    int age;
    long int myPhone;
}thanh;
int main()
{
    
    printf("Nhap ten vao thang ngu:");
    scanf("%[^\n]",&thanh.name);
    fflush(stdin);
    printf("\nNhap tuoi vao nhoc:");
    scanf("%d",&thanh.age);
    printf("\nNhap so dien thoai vao:");
    scanf("%ld",&thanh.myPhone);

    FILE *p;
    p = fopen("thanh.txt","w");
    fprintf(p,"%d",thanh.age);
    fscanf(p,"%d",&thanh.age);
    fclose(p);
    system("cls");
    printf("%d",thanh.age);
    return 0;
}