/*
贪心(多处最优服务次序问题)
2016年04月22日 16:16:53
阅读数：1549
问题：

设有N个顾客同时等待一项服务，顾客i需要的服务时间为ti（1<=i<=N）共有S处可以提供此项服务，

应如何安排N个顾客需要的服务次序才能使平均等待时间达到最小？平均等待时间等于N个顾客等待服务的总时间除以N。

输入：

第一行两个正整数N和S表示N个顾客S处服务，接下来N个顾客需要的服务时间

输出：

平均等待时间，保留3位小数。

输入样例：

10 2

56 12 1 99 1000 23433 55 99 812

输出样例：

336.000
*/
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
    int num=0,place=0;
    vector<int> use;
    cin >>num>>place;
    int in;
    for(int i=0;i < num;i++)
        {
            cin >> in;
            use.push_back(in);
        }
        sort(use.begin(),use.end());
        for(int i = place;i < num;i++)
        {
            use[i] += use[i-place];
        }
        int sum = 0;
        for(int i = 0 ;i < num;i++)
            sum+=use[i];
        cout <<"result is " <<sum/num <<endl;
}