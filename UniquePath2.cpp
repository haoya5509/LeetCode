/**
Unique Paths II Total Accepted: 19371 Total Submissions: 69591 My Submissions Question Solution 
Follow up for "Unique Paths":

Now consider if some obstacles are added to the grids. How many unique paths would there be?

An obstacle and empty space is marked as 1 and 0 respectively in the grid.

For example,
There is one obstacle in the middle of a 3x3 grid as illustrated below.

[
  [0,0,0],
  [0,1,0],
  [0,0,0]
]
The total number of unique paths is 2.

Note: m and n will be at most 100.

Author: haoya5509
Time: 11:48PM 2014/11/13
*/

#include<iostream>
#include<vector>
using namespace std;

int uniquePathsWithObstacles(vector<vector<int> > &obstacleGrid) {
	int dp[100+10][100+10];
	dp[0][0]=(obstacleGrid[0][0]==0)?1:0;
	for(int i=1;i<obstacleGrid.size();i++)
		dp[i][0]=(obstacleGrid[i][0]==1)?0:dp[i-1][0];
	for(int i=1;i<obstacleGrid[0].size();i++)
		dp[0][i]=(obstacleGrid[0][i]==1)?0:dp[0][i-1];
	for(int i=1;i<obstacleGrid.size();i++)
		for(int j=1;j<obstacleGrid[0].size();j++)
			dp[i][j]=(obstacleGrid[i][j]==1)?0:(dp[i-1][j]+dp[i][j-1]);
	return dp[obstacleGrid.size()-1][obstacleGrid[0].size()-1];        
}

int main(){
	vector<vector<int> > grid;
	int data[]={0};
	vector<int> tmp(data,data+1);
	grid.push_back(tmp);
	cout<<uniquePathsWithObstacles(grid)<<endl;
	return 0;
}