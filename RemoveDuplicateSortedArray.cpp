/**
Remove Duplicates from Sorted Array Total Accepted: 31154 Total Submissions: 96445 My Submissions Question Solution 
Given a sorted array, remove the duplicates in place such that each element appear only once and return the new length.

Do not allocate extra space for another array, you must do this in place with constant memory.

For example,
Given input array A = [1,1,2],

Your function should return length = 2, and A is now [1,2].

Author: haoya5509
Time: 12:41 2014/10/28
*/
#include <iostream>
#include<stack>
using namespace std;
int removeDuplicates(int A[], int n) {
    if(!n) return 0;
    int *B = new int[n];
    B[0] = A[0];
    int k=1;
    for(int i=1;i<n;i++){
        if(A[i] == A[i-1])
            continue;
        else
            B[k++] = A[i];
    }
    for(int i=0;i<k;i++){
        A[i] = B[i];
    }
    delete []B;
    return k;
}
int main(){
    int A[4] = {1,1,2,3};
    cout << removeDuplicates(A, 4);
    return 0;
}