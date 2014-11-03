/**
Maximum Subarray Total Accepted: 31491 Total Submissions: 92694 My Submissions Question Solution 
Find the contiguous subarray within an array (containing at least one number) which has the largest sum.

For example, given the array [−2,1,−3,4,−1,2,1,−5,4],
the contiguous subarray [4,−1,2,1] has the largest sum = 6.

click to show more practice.

More practice:
If you have figured out the O(n) solution, try coding another solution using the divide and conquer approach, which is more subtle.

Author: haoya5509
Time: 11:45PM 2014/11/3
*/

#include<iostream>
#include<cstdlib>
using namespace std;
int maxSubArray_DP(int A[], int n) {
	const int Len = n;
	int dp[Len],maxV;
	maxV=dp[0]=A[0];
	for(int i=1;i<n;i++){
		dp[i]=max(dp[i-1]+A[i],A[i]);
		maxV=max(dp[i],maxV);
	}
	return maxV;
}
int maxSubArray_DividInner(int *A,int l,int r){
	if(l+1==r) return A[l];
	int m=l+(r-l)/2;
	int max1=max(maxSubArray_DividInner(A,l,m),maxSubArray_DividInner(A,m,r));
	int lmax=A[m-1],rmax=A[m],tmp=0;
	for(int i=m-1;i>=l;i--){
		tmp+=A[i];
		if(tmp>lmax) lmax=tmp;
	}tmp=0;
	for(int i=m;i<r;i++){
		tmp+=A[i];
		if(tmp>rmax) rmax=tmp;
	}
	//cout<<"l:"<<l<<" r:"<<r<<" "<<max(max1,lmax+rmax)<<endl;
	return max(max1,lmax+rmax);
}
int maxSubArray_Divid(int A[],int n){
	return maxSubArray_DividInner(A,0,n);
}
int maxSubArray(int A[],int n){
	srand(time(NULL));
	int option=0;//rand()%2;
	if(option)
		return maxSubArray_DP(A,n);
	else
		return maxSubArray_Divid(A,n);
}
int main(){
	int A[] = {1,2,-1,-2,2,1,-2,1};
	cout<<maxSubArray(A,8)<<endl;
	return 0;
}