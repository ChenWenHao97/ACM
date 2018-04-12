/*
53. 最大子序和
题目描述提示帮助提交记录社区讨论阅读解答
随机一题
给定一个序列（至少含有 1 个数），从该序列中寻找一个连续的子序列，使得子序列的和最大。

例如，给定序列 [-2,1,-3,4,-1,2,1,-5,4]，
连续子序列 [4,-1,2,1] 的和最大，为 6。


扩展练习:

若你已实现复杂度为 O(n) 的解法，尝试使用更为精妙的分治法求解。


*/
#include<iostream>
#include<vector>
#include<algorithm> 

using namespace std;
class Solution {
public:
    int maxSubArray(vector<int>& nums) 
    {
        int sum = *min_element(nums.begin(), nums.end()), last = 0;

        for (vector<int>::iterator it = nums.begin(); it != nums.end(); ++it)
        {
            if (last + *it > *it)
                last += *it;
            else
                last = *it;
            if (last > sum)
                sum = last;
        }
        return sum;
    }
};
int main()
{
    vector<int> nums { -1 };
    Solution test;
    cout <<test.maxSubArray(nums)<<endl;

    return 0;
}