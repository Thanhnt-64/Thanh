#include<stdio.h>
int setBit(int n, int k){
  return (n | (1 << (k-1)));
};
int clearBit(int n, int k){
  return (n & (~(1 << (k-1))));
}
int toggleBit(int n, int k){
  return (n ^ (1 << (k-1)));
}
int main(){
  int n = 5, k = 1;//5:101
  printf("%d with %d-th bit Set: %d\n",n,k,setBit(n,k));//101
  printf("%d with %d-th bit Clear: %d\n",n,k,clearBit(n,k));//100
  printf("%d with %d-th bit Toggle: %d\n",n,k,toggleBit(n,k));//100
  return 0;
}