// // 一个整数“犯二的程度”定义为该数字中包含2的个数与其位数的比值。如果这个数是负数，则程度增加0.5倍；如果还是个偶数，则再增加1倍。例如数字-13142223336是个11位数，其中有3个2，并且是负数，也是偶数，则它的犯二程度计算为：3/11×1.5×2×100%，约为81.82%。本题就请你计算一个给定整数到底有多二。

// // 输入格式：
// // 输入第一行给出一个不超过50位的整数N。

// // 输出格式：
// // 在一行中输出N犯二的程度，保留小数点后两位。

// // 输入样例：
// // -13142223336
// // 输出样例：
// // 81.82%

// #include <stdio.h>
// #include<math.h>
// int main()
// {
//   float  m, i;
//   long n;
//   int co = 0;
//   scanf("%lld", &n);

//   if (n < 0)
//   {
//     n = -n;
//     long long temp = n;
//     while (1)
//     {
//       if (temp != 0)
//       { 
//         float q = 10;
//         m = fmodf(temp,q);
//                 printf("first:%d\n",m);

//         temp =temp / 10;
//            printf("two:%d\n",temp);

//         co = co + 1;
//         printf("three:%d\n",co);
//         if (m - 2. <0.01 || 2. - m > 0.01)
//         {
//           i++;
//           printf("four:%d\n",i);
//         }
//       }
//       else
//         break;
//     }
//     long long temp2 = n;
//     int m2 = temp2 % 10;
//     if(m2 % 2 == 0)
//     {
//     //  printf("%.2f%%",); 
//     }
//      int p = ((i / co ) * (1.5 * 2 ))/ 100;
//      printf("%f",p);

//   }
// }
#include<stdio.h>
//水题大家可以练习下
int main(){
  char Input[1000];
  float flag =1; int oushu =1, i, n = 0;
  float out;
  scanf("%s", &Input);
  if (Input[0] =='-'){//判断负号
    flag = 1.5;
  }
  for (i =0; Input[i] !='\0'; i++){//判断输入位数
  if (Input[i] =='2')
    n++;
  }
  if ((Input[i -1] - 48) % 2 ==0){//判断偶数
    oushu = 2;
  }
  if (flag ==1.5){//如果偶数，即-号占了位置
    i--;
  }
  out = (float)n / (float)i*flag*oushu*100;//输出
  printf("%.2f%%",out);
}



