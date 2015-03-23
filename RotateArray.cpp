/**
 * Rotate Array Total Accepted: 4609 Total Submissions: 25343 My Submissions Question Solution 
 * Rotate an array of n elements to the right by k steps.
 *
 * For example, with n = 7 and k = 3, the array [1,2,3,4,5,6,7] is rotated to [5,6,7,1,2,3,4].
 * Author: haoya
 * Time: 2015/3/2 9:56AM
 * */
#include<iostream>
using namespace std;
void rotateInner(int nums[],int l,int r){
	while(l<r){
		int temp=nums[l];
		nums[l]=nums[r];
		nums[r]=temp;
		l++;
		r--;
	}
}
void rotate(int nums[], int n, int k) {
	/**
	 *!!!!!!!!To ensure k<n
	 * */
	if(k>n)
		k%=n;
	rotateInner(nums,0,n-k-1);
	rotateInner(nums,n-k,n-1);
	rotateInner(nums,0,n-1);
}
int main(){
	int nums[] = {1,2};
	rotate(nums,2,0);
	for(int i =0;i<2;i++){
		cout<<nums[i]<<"...";
	}cout<<endl;
	return 0;
}
