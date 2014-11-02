/**
Find Minimum in Rotated Sorted Array Total Accepted: 10185 Total Submissions: 32228 My Submissions Question Solution 
Suppose a sorted array is rotated at some pivot unknown to you beforehand.

(i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).

Find the minimum element.

You may assume no duplicate exists in the array.

Author: haoya5509
Time: 1:00AM 2014/11/3
*/
#include<iostream>
#include<vector>
using namespace std;
//BinarySearch
int findMin(vector<int> &num) {
	int l=0,r=num.size();
	int m = l+(r-l)/2;  
	while(true){
		if(l==m) return num[m];
		if(num[m] > num[r-1] || num[m] < num[m-1] ){
			l=m;
			m = l+(r-l)/2;
		}else{
			r=m;
			m = l+(r-l)/2;
		}
	}
}
int main(){

	int data[] = {2,1};
	std::vector<int> v(data,data+2);
	cout << findMin(v) << endl;
}