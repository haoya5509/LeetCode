/**
Triangle Total Accepted: 23623 Total Submissions: 89033 My Submissions Question Solution 
Given a triangle, find the minimum path sum from top to bottom. Each step you may move to adjacent numbers on the row below.

For example, given the following triangle
[
		[2],
	   [3,4],
	  [6,5,7],
	 [4,1,8,3]
]
The minimum path sum from top to bottom is 11 (i.e., 2 + 3 + 5 + 1 = 11).

Note:
Bonus point if you are able to do this using only O(n) extra space, where n is the total number of rows in the triangle.

Author: haoya5509
Time: 14:05 2014/11/15
*/
#include<iostream>
#include<vector>
using namespace std;
int minimumTotal(vector<vector<int> > &triangle){
	vector<int> sum(triangle[triangle.size()-1].size());
	for(int i=0;i<triangle.size();i++){
		//sum[triangle[i].size()-1]=sum[triangle[i].size()-2];
		for(int j=triangle[i].size()-1;j>0;j--){
			if(j==triangle[i].size()-1&&j>0)
				sum[j]=sum[j-1]+triangle[i][j];
			else
				sum[j]=min(sum[j-1],sum[j])+triangle[i][j];
		}
		sum[0]=sum[0]+triangle[i][0];
	}
	int res=sum[0];
	for(int i=1;i<sum.size();i++)
		if(sum[i]<res) res=sum[i];
	return res;
}
int main(){
	return 0;
}
