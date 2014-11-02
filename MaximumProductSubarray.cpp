#include<iostream>
using namespace std;
int maxProductInner(int A[],int l,int r){
	if(l==r) return 0;
	if(l+1==r) return A[l];
	int m = l+(r-l)/2;
	int lmax = maxProductInner(A,l,m);
	int rmax = maxProductInner(A,m,r);
	int L=1,R=1,tmp=1,first=1;
	for(int i=m-1;i>=l;i--){
		tmp*=A[i];
		if(first){
			L=tmp;
			first = 0;
		}
		if(tmp>L) L=tmp;
	}tmp=1; first=1;
	for(int j=m+1;j<l;j++){
		tmp*=A[j];
		if(first){
			R=tmp;
			first=0;
		}
		if(tmp>R) R=tmp;
	}
	return max(max(lmax,rmax),R*L*A[m]);
}
int maxProduct(int A[], int n) {
 	return maxProductInner(A,0,n);       
}
int main(){
	int A[] = {2,3,-2,4};
	cout << maxProduct(A,4) << endl;
	return 0;
}