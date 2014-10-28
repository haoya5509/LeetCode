/**
Remove Element Total Accepted: 29080 Total Submissions: 88054 My Submissions Question Solution 
Given an array and a value, remove all instances of that value in place and return the new length.

The order of elements can be changed. It doesn't matter what you leave beyond the new length.

Author:haooya5509	
Time: 8:47 2014/10/28
*/

int removeElement(int A[], int n, int elem) {
    int pos=0;
    for(int i=0;i<n;i++){
        if(A[i] != elem){
            A[pos++] = A[i];
        }
    }
    return pos;
}