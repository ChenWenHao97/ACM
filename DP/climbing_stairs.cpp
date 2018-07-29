/*
70. 爬楼梯
题目描述提示帮助提交记录社区讨论阅读解答
随机一题
你正在爬楼梯。需要 n 步你才能到达顶部。

每次你可以爬 1 或 2 个台阶。你有多少种不同的方式可以爬到楼顶呢？

注意：给定 n 将是一个正整数。

示例 1：

输入： 2
输出： 2
说明： 有两种方法可以爬到顶端。

1.  1 步 + 1 步
2.  2 步
 

示例 2：

输入： 3
输出： 3
说明： 有三种方法可以爬到顶端。

1.  1 步 + 1 步 + 1 步
2.  1 步 + 2 步
3.  2 步 + 1 步

*/
#include<iostream>
using namespace std;
class Solution {  
    public:
    //可以想想成f(n) = f(n-1)+f(n-2)，在fn时，走一步的方法数和走两步的方法数就是现在的方法数
     int climbStairs(int n) {  
        int ways[] = {1, 1};  
        for (int i = 1; i < n; i++) {  
            int temp = ways[1];  
            ways[1] += ways[0];  
            ways[0] = temp;  
        }  
        return ways[1];  
    }  
};
int main()
{
    int n;
    Solution test;
    cin >>n;
    cout << test.climbStairs(n);

    return 0;

}