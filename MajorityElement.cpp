/**
Majority Element Total Accepted: 7258 Total Submissions: 22380 My Submissions Question Solution 
Given an array of size n, find the majority element. The majority element is the element that appears more than ⌊ n/2 ⌋ times.

You may assume that the array is non-empty and the majority element always exist in the array.

Credits:
Special thanks to @ts for adding this problem and creating all test cases.

Author: haoya
Time:	2014.12.30 12:19
*/

int majorityElement(vector<int> &num) {
	sort(num.begin(),num.end());
	return num[num.size()/2];        
}