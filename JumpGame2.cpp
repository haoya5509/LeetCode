/**
Jump Game II Total Accepted: 23604 Total Submissions: 95773 My Submissions Question Solution
Given an array of non-negative integers, you are initially positioned at the first index of the array.

Each element in the array represents your maximum jump length at that position.

Your goal is to reach the last index in the minimum number of jumps.

For example:
Given array A = [2,3,1,1,4]

The minimum number of jumps to reach the last index is 2. (Jump 1 step from index 0 to 1, then 3 steps to the last index.)

Author: haoya5509
Time: 22:18PM 2014/12/8
*/
#include<iostream>
using namespace std;

int jump(int A[], int n) {
    int minStep[100000]={0};
    int i=0,j=0;
    if(n==1) return 0;
	if(A[0]>0) minStep[j++]=1;
	while(i<n-1){
		if(minStep[i]>0)
			for(int k=j;k<=i+A[i];k++){
				if(j>=n) return minStep[n-1]-1;
				minStep[j++]=minStep[i]+1;
			}
		i++;
	}
	return minStep[n-1]-1;
}

int main(){
	int A[] = {2,1};//3,1,1,4};//{3,2,1,0,4};
	cout << jump(A,2) << endl;
}

