/**
3Sum Total Accepted: 28918 Total Submissions: 172970 My Submissions Question Solution 
Given an array S of n integers, are there elements a, b, c in S such that a + b + c = 0? Find all unique triplets in the array which gives the sum of zero.

Note:
Elements in a triplet (a,b,c) must be in non-descending order. (ie, a ≤ b ≤ c)
The solution set must not contain duplicate triplets.
    For example, given array S = {-1 0 1 2 -1 -4},

    A solution set is:
    (-1, 0, 1)
    (-1, -1, 2)

Author: haoya5509
Time: 14:45Pm 2014/11/11
*/
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


vector<vector<int> > threeSum(vector<int> &num) {

    vector< vector<int> > result;

    //sort the array, this is the key
    sort(num.begin(), num.end());

    int n = num.size();

    for (int i=0; i<n-2; i++) {
        //skip the duplication
        if (i>0 && num[i-1]==num[i]) continue;
        int a = num[i];
        int low = i+1;
        int high = n-1;
        while ( low < high ) {
            int b = num[low];
            int c = num[high];
            if (a+b+c == 0) {
                //got the soultion
                vector<int> v;
                v.push_back(a);
                v.push_back(b);
                v.push_back(c);
                result.push_back(v);
                // Continue search for all triplet combinations summing to zero.
                //skip the duplication
                while(low<n && num[low]==num[low+1]) low++; 
                while(high>0 && num[high]==num[high-1]) high--; 
                low++;
                high--;
            } else if (a+b+c > 0) {
                //skip the duplication
                while(high>0 && num[high]==num[high-1]) high--;
                high--;
            } else{
                //skip the duplication
                while(low<n && num[low]==num[low+1]) low++;
                low++;
            } 
        }
    }
    return result;
}


int main(){
	//int tmp[]={-1,0,1,2,-1,-4};
	int tmp[]={};
	vector<int> num(tmp,tmp);
	vector<vector<int> > res=threeSum(num);
	for(int i=0;i<res.size();i++){
		for(int j=0;j<res[i].size();j++){
			cout<<res[i][j]<<"..";
		}
		cout<<endl;
	}
	return 0;
}