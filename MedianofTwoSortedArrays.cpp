/**
Median of Two Sorted Arrays Total Accepted: 43491 Total Submissions: 243557 My Submissions Question Solution
There are two sorted arrays A and B of size m and n respectively. Find the median of the two sorted arrays. The overall run time complexity should be O(log (m+n)).

Author: haoya
TimeL:  2015/4/3 9:59am
*/
double findMedianSortedArrays(int A[], int m, int B[], int n) {
    int length=m+n;
    if(length%2)return findkth(A, m, B, n, length/2+1);
    else return (double(findkth(A, m, B, n, length/2))+findkth(A, m, B, n, length/2+1))/2;
}
int findkth(int A[],int m,int B[], int n, int k){
    if(m>n)
        return findkth(B, n, A, m,k);
    if(m==0)return B[k-1];
    if(k==1)return A[0]<B[0]?A[0]:B[0];
    int pa=k/2<m?k/2:m;
    int pb=k-pa;
    if(A[pa-1]==B[pb-1]){return A[pa-1];}
    if(A[pa-1]<B[pb-1])
        return findkth(A+pa, m-pa, B, pb, k-pa);
    else
        return findkth(A,pa,B+pb,n-pb,k-pb);
}
