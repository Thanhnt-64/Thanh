#include<stdio.h>
int sum(const int *p, int n){
    int sum_a = 0;
    for(int i = 0; i < n; i ++){
        sum_a += p[i];
    }
    return sum_a;
}
int main(){
    int n = 10;
    int a[10];
    for (int i = 0; i < n; i++){
        a[i] = i+1;
    }
    int b = sum(a,n);
    printf("%d\n", b);
    return 0;
}