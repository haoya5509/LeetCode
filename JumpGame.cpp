/**
Jump Game Total Accepted: 26922 Total Submissions: 99149 My Submissions Question Solution
Given an array of non-negative integers, you are initially positioned at the first index of the array.

Each element in the array represents your maximum jump length at that position.

Determine if you are able to reach the last index.

For example:
A = [2,3,1,1,4], return true.

A = [3,2,1,0,4], return false.

Show Tags

Author: haoya5509
Time: 22:01PM 2014/12/8
*/
#include<iostream>
using namespace std;

bool canJump(int A[], int n) {
	if(n==1) return true;
	bool can[100000]={false};
	int i=0,j=0;
	if(A[0]>0) can[j]=true;
	while(i<n){
		if(can[i])
			for(int k=j;k<i+A[i];k++){
				if(j>=n) return true;
				can[++j]=true;
			}
		i++;
	}
	return can[n-1];
}
int main(){
	int A[] = {3,2,1,0,4};//{2,3,1,1,4};//{3,2,1,0,4};
	cout << canJump(A,5) << endl;
}
