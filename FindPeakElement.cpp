/**
Find Peak Element Total Accepted: 5316 Total Submissions: 16742 My Submissions Question Solution 
A peak element is an element that is greater than its neighbors.

Given an input array where num[i] ≠ num[i+1], find a peak element and return its index.

The array may contain multiple peaks, in that case return the index to any one of the peaks is fine.

You may imagine that num[-1] = num[n] = -∞.

For example, in array [1, 2, 3, 1], 3 is a peak element and your function should return the index number 2.

click to show spoilers.

Note:
Your solution should be in logarithmic complexity.

Credits:
Special thanks to @ts for adding this problem and creating all test cases.

Author:	haoya
Time:	11:47PM 2014/12/17
*/
#include<iostream>
#include<vector>
using namespace std;

int findPeakElement(const vector<int> &num) {
	int len=num.size();
	if(len==1) return 0;
	int l=0,r=len;
	while(l<r){
		int m=l+(r-l)/2;
		if(m==len-1&&num[m]>num[m-1])
			return m;
		if(m==0&&num[m]>num[m+1])
			return m;
		if(num[m]>num[m+1]&&num[m]>num[m-1])
			return m;
		if(num[m]<num[m-1])
			r=m;
		if(num[m]>num[m-1])
			l=m+1;
	}      
	return 0;
}

int main(){
	int a[] = {1,2};
	vector<int> num(a,a+2);
	cout << findPeakElement(num) << endl;
}