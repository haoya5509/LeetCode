/**
Minimum Path Sum Total Accepted: 22009 Total Submissions: 70842 My Submissions Question Solution 
Given a m x n grid filled with non-negative numbers, find a path from top left to bottom right which minimizes the sum of all numbers along its path.

Note: You can only move either down or right at any point in time.

Author: haoya5509
Time: 11:25PM 2014/11/13
*/

#include<iostream>
#include<vector>
#include<cstring>
using namespace std;
int minPathSum(vector<vector<int> > &grid) {
	int dp[1000][1000];
	memset(dp,0,sizeof(dp));
	dp[0][0]=grid[0][0];
	for(int i=1;i<grid[0].size();i++)
		dp[0][i]=dp[0][i-1]+grid[0][i];
	for(int j=1;j<grid.size();j++)
		dp[j][0]=dp[j-1][0]+grid[j][0];
	for(int i=1;i<grid.size();i++)
		for(int j=1;j<grid[i].size();j++)
			dp[i][j]=min(dp[i-1][j],dp[i][j-1])+grid[i][j];
	return dp[grid.size()-1][grid[0].size()-1];
}
int main(){
	vector<vector<int> > grid;
	int data[]={0};
	vector<int> tmp(data,data+1);
	grid.push_back(tmp);
	cout<<minPathSum(grid)<<endl;
	return 0;
}