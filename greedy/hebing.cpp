/*
最优合并问题

     给定k个排好序的序列s1,s2,…,sk，用2路合并算法将这k个序列合并成一个序列。
     假设所采用的2路合并算法合并两个长度分别为m和n的序列需要m+n-1次比较。]
     试设计一个算法确定合并这个序列的最优合并顺序，使所需要的总比较次数最少。

测试用例：

4（序列数）

5 1211 2（序列中的元素数）

输出：

    78（最差情况）

    52（最优情况）
解：

最优合并问题：
当取最小值保证每次的2个加数为最小便可，最大值同理取当前最大的两个值便可
请看下面序列
3,6,5,12,7
如果排好序之后依次按照，找最小连个数进行相加
排好序之后3,5,6,7,12
最小值3+5 = 8   8,6,7,12 按照排序的思路此时不能保证当前数组中前两位是最小值，所以还要排序
6,7,8,12    6+7 = 13     -->13,8,12
继续排序
最后按照题意m和n的序列需要m+n-1 次比较
所以在比较中每次减一。 
这样便求出了最小值
*/
#include<iostream>
#include<algorithm>
using namespace std;
#define n 4
int a[n]={5,12,11,2};

int getmin(int *a)
{
    int number=n,result=0,s[n];
    int i,j,temp;

    for(i=0; i<n; i++){
        s[i]=a[i];
    }
    sort(s,s+number);
        s[0]=s[0]+s[1];
        result+=s[0]-1;//n+m-1
        number--;
        for(i=1;i<number;i++)
            s[i]=s[i+1];
    return result;
}
int getmax(int *a)
{
    int number=n,result=0,s[n];
    int i,j,temp;
    for(i=0;i<n;i++){
        s[i]=a[i];
    }
    sort(s,s+number);
        s[0]=s[0]+s[1];
        result+=s[0]-1;
        number--;
        for(i=1;i<number;i++)
            s[i]=s[i+1];
    return result;
}
int main(){
    cout <<"最优情况"<<getmin(a)<<endl;  
    cout<<"最差情况"<<getmax(a)<<endl;
    return 0;
}