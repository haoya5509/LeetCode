/**
Given an array of integers, every element appears twice except for one. Find that single one.

Note:
Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?

Author: haoya5509
Time: 11:51Pm 2014/11/5
*/

#include<iostream>
using namespace std;
int singleNumber(int A[], int n) {
	int res=0;
	for(int i=0;i<n;i++)
		res ^= A[i];
	return res;
}

int main(){
	int A[]={2,2,3,1,4,1,3};
	cout<<singleNumber(A,7)<<endl;
	return 0;
}