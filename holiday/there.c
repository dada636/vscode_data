// 对于给定的正整数N，需要你计算 S=1!+2!+3!+...+N!。
// 输入格式：
// 输入在一行中给出一个不超过10的正整数N。
// 输出格式：
// 在一行中输出S的值。
// 输入样例：
// 3
// 输出样例：
// 9

#include <stdio.h>

int func(int n)
{
  int sum = 1;
  for (int i = 1; i <= n; i++)
    {
      sum = sum * i;
    }
    return sum;
}

int main()
{
  int n;
  int sum = 0;
  int temp ;
  scanf("%d", &n);

  while(1){
  if(n != 0)
   {temp =  func(n);
   sum = temp + sum;
   n--;
   }
  else
  {
    break;
  }
  }

    
  printf("%d", sum);
}