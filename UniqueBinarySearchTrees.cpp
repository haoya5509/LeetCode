/**
Unique Binary Search Trees Total Accepted: 30099 Total Submissions: 82328 My Submissions Question Solution 
Given n, how many structurally unique BST's (binary search trees) that store values 1...n?

For example,
Given n = 3, there are a total of 5 unique BST's.

   1         3     3      2      1
    \       /     /      / \      \
     3     2     1      1   3      2
    /     /       \                 \
   2     1         2                 3

Author: haoya5509
Time: 20:18pm 2014/11/8
*/
#include<iostream>
using namespace std;
int numTrees(int n) {
	int dp[10000];	//dp[i] stand for num i has bp[i] cases;
	dp[0]=1;
	dp[1]=1;
	for(int i=2;i<=n;i++){
		int res=0;
		for(int j=1;j<=i;j++){
			res+=dp[j-1]*dp[i-j];
		}
		dp[i]=res;
	}        
	return dp[n];
}
int main(){
	cout << numTrees(3) << endl;
	return 0;
}