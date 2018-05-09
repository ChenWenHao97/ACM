/*
会场安排问题
【问题描述】
假设要在足够多的会场里安排一批活动，并希望使用尽可能少的会场。
（这个问题实际上是著名的图着色问题。若将每一个活动作为图的一个顶点，不相容活动间用边相连。
使相邻顶点有不同颜色的最小着色数，相应于要找的最小会场数。）
【数据输入】
第一行有1个正整数k，表示有k个待安排的活动。接下来的k行中，
每行有两个正整数，分别表示k个待安排的活动开始时间和活动结束时间。时间以0点开始的分钟计。
5
1 23
12 28
25 35
27 80
36 50

max:3
*/
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
typedef struct node{
    int data;
    int flag;
}Node;
class solution{
    public:
        int num;
        int func(int num,vector<Node> things);
};
bool cmp(Node n1,Node n2)
{
    return n1.data < n2.data;//ascend order
}
int solution::func(int num,vector<Node> things)
{
    sort(things.begin(),things.end(),cmp);
    int max = 0;
    int sum = 0;
    for(Node i:things)
    {
        if(i.flag)
        {
            max++;
            if(max > sum)
                sum = max;
        }
        else 
        {
            max--;
        }
    }
    return sum;
}
int main()
{
    solution test;
    cin >> test.num;
    Node t;
    vector<Node> things;
    for(int i = 1;i <= test.num*2;i++)
    {
        cin >> t.data;
        t.flag = i%2;
        things.push_back(t);
    }
    int max = test.func(test.num,things);
    cout <<"meetings max:"<<max<<endl;
}
