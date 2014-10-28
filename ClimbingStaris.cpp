/**
Climbing Stairs Total Accepted: 28563 Total Submissions: 83859 My Submissions Question Solution 
You are climbing a stair case. It takes n steps to reach to the top.

Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?

Author: haoya5509
Time 8:39 2014/10/28
*/

int climbStairs(int n) {
        int *dp = new int[n];
        dp[0]=1,dp[1]=2;
        for(int i=2;i<n;i++)
            dp[i] = dp[i-1]+dp[i-2];
        int res = dp[n-1];
        delete []dp;
        return res;
}

int climbStairs(int n) {
        int a=1,b=1,c=a;
        for(int i=1;i<n;i++){
            c = a+b;
            a = b;
            b = c;
        }
        return c;
    }