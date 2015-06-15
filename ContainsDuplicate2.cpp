#include<iostream>
#include<vector>
using namespace std;
bool containsNearbyDuplicate(vector<int> &nums, int k){
	k = (k<=nums.size())?k:nums.size();
	for(int i=0;i<=nums.size()-k;i++){
		for(int j=1;j<=k;j++){
			if(nums[i] == nums[j])
				return true;
		}
	}
	return false;
}
int main(){
	
	return 0;
}	
