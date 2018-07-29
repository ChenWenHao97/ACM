/*
解决汽车加油问题
2017年12月13日 20:46:44
阅读数：417
问题描述：试用贪心算法求解汽车加油问题：已知一辆汽车加满油后可行驶d（如d=7）公里，而旅途中有若干个加油站。
试设计一个有效算法，指出应在哪些加油站停靠加油使加油次数最少。
用数组a存放各加油站之间的距离，如a[ ]={2,7,3,6}，表示共有4个加油站，起点到1号加油站的距离为2km，
1号到2号加油站的距离为7km，2号到3号加油站的距离为3km，3号到4号加油站的距离为6km。
*/
#include<iostream>
#include<vector>
using namespace std;
int main()
{
    int able,num;
    cin >> able >>num;
    vector<int> miles;
    int value;
    for(int i = 0;i <=num;i++)
    {
        cin >>value;
        miles.push_back(value);
    }
    int result = 0;
    int left = able;
    for(int i=0;i<=num;i++)
    {

        if(left-miles[i]>0)
            left -= miles[i];
        else  
        {
            result++;
            left = able-miles[i];

        }
    }
    if(result)
        cout <<"result is:"<<result;
    else 
        cout <<"No solution"<<endl;
}
