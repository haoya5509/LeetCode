/*
House Robber Total Accepted: 1408 Total Submissions: 5109 My Submissions Question Solution
You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed, the only constraint stopping you from robbing each of them is that adjacent houses have security system connected and it will automatically contact the police if two adjacent houses were broken into on the same night.

Given a list of non-negative integers representing the amount of money of each house, determine the maximum amount of money you can rob tonight without alerting the police.

Author: haoya
Time:   2015/4/1 16:04
*/
#include<iostream>
#include<vector>
using namespace std;

int rob(vector<int> &num){
    if(num.size()==0)
        return 0;
    if(num.size()==1)
        return num[0];
    vector<int> dp(num.size());
    dp[0] = num[0];
    dp[1] = max(num[0],num[1]);
    for(size_t i=2;i<num.size();i++){
        dp[i] = max(dp[i-2]+num[i],dp[i-1]);
    }
    return dp[num.size()-1];
}

int main(void){
    int mynum[] = {5,4,3,2,1,8};
    vector<int> num(mynum,mynum+sizeof(mynum)/sizeof(int));
    cout << rob(num) <<endl;
    return 0;
}
