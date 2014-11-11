/**
3Sum Closest Total Accepted: 20794 Total Submissions: 77141 My Submissions Question Solution 
Given an array S of n integers, find three integers in S such that the sum is closest to a given number, target. Return the sum of the three integers. You may assume that each input would have exactly one solution.

    For example, given array S = {-1 2 1 -4}, and target = 1.

    The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).

Author: haoya5509
Time: 15:04PM 2014/11/11

*/
#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;
int threeSumClosest(vector<int> &num,int target){
	int n=num.size();
	int res=num[0]+num[1]+num[2];
	sort(num.begin(),num.end());
	for(int i=0;i<n-2;i++){
		int low=i+1;
		int high=n-1;
		while(low<high){
			while(low<high&&num[i]+num[low]+num[high]<=target){
				if(abs(target-res)>abs(target-(num[i]+num[low]+num[high])))
					res=num[i]+num[low]+num[high];
				low++;
			}
			while(low<high&&num[i]+num[low]+num[high]>=target){
				if(abs(target-res)>abs(target-(num[i]+num[low]+num[high])))
					res=num[i]+num[low]+num[high];
				high--;
			}
		}
	}
	return res;
}
int main(){
	int tmp[]={1,2,4,8,16,32,64,128};
	vector<int> num(tmp,tmp+8);
	cout << threeSumClosest(num,82) << endl;
	return 0;
}