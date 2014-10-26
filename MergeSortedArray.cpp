/**
Merge Sorted Array Total Accepted: 27821 Total Submissions: 87234 My Submissions Question Solution 
Given two sorted integer arrays A and B, merge B into A as one sorted array.

Note:
You may assume that A has enough space (size that is greater or equal to m + n) to hold additional elements from B. The number of elements initialized in A and B are m and n respectively.

Author:haoya5509
Time: 11:52 2014/10/26
*/

#include<iostream>
#include<stdlib.h>
using namespace std;
void merge(int A[],int m,int B[],int n){
    int *C = (int*)malloc((m+n)*sizeof(int));
    int i=0,j=0,k=0;
    while(i<m || j<n){
        if(i == m || (j<n && A[i] > B[j])) C[k++] = B[j++];
        else C[k++] = A[i++];
    }
    for(int m=0;m<k;m++)
        A[m] = C[m];
    free(C);
}
int main(){
    //[-49,-48,-48,-47,-45,-42,-39,-36,-33,-33,-28,-28,-23,-23,-7,-4,-3,0,0,4,6,21,29,29,31,34,36,38,40,43,45,46,47], [-16,-5,-3,26,33,35,38,41]
    //int A[39] = {-49,-48,-48,-47,-45,-42,-39,-36,-33,-33,-28,-28,-23,-23,-7,-4,-3,0,0,4,6,21,29,29,31,34,36,38,40,43,45,46,47};
    //int B[6] = {2,3,6,7,8,9};
    int A[1] = {0};
    int B[0];
    merge(A,1,B,0);
    for(int i=0;i<1;i++)
        cout << A[i] << "...";
    cout << endl;
    return 0;
}