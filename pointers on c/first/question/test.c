#include<stdio.h>

int add(int a,int b){
  int d = a + b;
  return d;
}

int main()
{
  int c = add(1,2);
  printf("%d",c);
  return 0;
}

