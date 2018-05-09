/*
删数问题
Time Limit: 1000MS Memory Limit: 65536KB
Submit Statistic
Problem Description
 键盘输入一个高精度的正整数n（≤100位），去掉其中任意s个数字后剩下的数字按照原来的左右次序组成一个新的正整数。
 编程对给定的n与s，寻找一种方案，使得剩下的数字组成的新数最小。
Input
  输入有多组 每组包括原始数n，要去掉的数字数s；
Output
 输出去掉s个数后最小的数
Example Input
178543  4
Example Output
13
*/
#include<iostream>
 #include<string>
 using namespace std;
 int main()
 {
    string n;
    int s,i,x,l,m;
    while(cin>>n>>s)
    {
         i=0,m=0,x=0;
         l=n.length(); 
         while(x<s&&m==0)
          {
              if(n[i]>n[i+1])//出现递减,删除递减的首数字 
               {
                   n=n.erase(i,1);
                   x++;// x统计删除数字的个数 
                   i=0;//从头开始查递减区间 
               } 
              if(i==l-x-1&&x<s)
                m=1;//已经无递减区间,m=1脱离循环 
            i++;
          } 
      cout<<n.substr(0,l-s+x)<<endl;//只打印剩下的左边l-(s-x)个数字 
    } 
    return 0;
 }   