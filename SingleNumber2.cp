#include<iostream>
using namespace std;
int singleNumber(int A[], int n) {
	int ones=0; //纪录出现一次的位
	int twos=0; //记录出现两次的位
	int res;
	for(int i=0;i<n;i++){
		twos |= ones&A[i];	//之前出现过一次后，记录到两次上
		ones^=A[i];
		res=ones&twos;
		ones &= ~res;
		twos &= ~res;
	}
	return ones;
}

int main(){
	int A[]={2,2,3,1,4,1,3};
	cout<<singleNumber(A,7)<<endl;
	return 0;
}