/**
Maximum Product Subarray Total Accepted: 11980 Total Submissions: 73885 My Submissions Question Solution 
Find the contiguous subarray within an array (containing at least one number) which has the largest product.

For example, given the array [2,3,-2,4],
the contiguous subarray [2,3] has the largest product = 6.

Author: haoya5509
Time: 12:23AM 2014/11/13
*/
#include<iostream>
#include<cstring>
using namespace std;
int maxProduct(int A[], int n) {
	int dp[100000+10][2];   
	memset(dp,0,sizeof(dp));     
	dp[0][0]=dp[0][1]=A[0];
	for(int i=1;i<n;i++){
		if(A[i]>0){
			dp[i][0]=max(dp[i-1][0]*A[i],A[i]);
			dp[i][1]=min(dp[i-1][1]*A[i],A[i]);
		}
		if(A[i]<0){
			dp[i][0]=max(dp[i-1][1]*A[i],A[i]);
			dp[i][1]=min(dp[i-1][0]*A[i],A[i]);
		}
	}
	int res=A[0];
	for(int i=0;i<n;i++){
		for(int j=0;j<2;j++)
			if(dp[i][j]>res)
				res=dp[i][j];
	}
	return res;
}

int main(){
	int A[] = {2,3,-2,4};
	cout << maxProduct(A,4) << endl;
	return 0;
}