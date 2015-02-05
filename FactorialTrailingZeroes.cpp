/**
Factorial Trailing Zeroes Total Accepted: 1010 Total Submissions: 2607 My Submissions Question Solution 
Given an integer n, return the number of trailing zeroes in n!.

Note: Your solution should be in logarithmic time complexity.

Credits:
Special thanks to @ts for adding this problem and creating all test cases.

Author:	haoya
Time: 2014.12.31 12:07
*/
int trailingZeroes(int n) {
	int res=0;
	for(int i=n/5;i>0;i/=5)
		res+=i;
	return res;       
}