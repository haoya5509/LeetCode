/*
Number of 1 Bits Total Accepted: 4879 Total Submissions: 12520 My Submissions Question Solution
Write a function that takes an unsigned integer and returns the number of ¡¯1' bits it has (also known as the Hamming weight).

For example, the 32-bit integer ¡¯11' has binary representation 00000000000000000000000000001011, so the function should return 3.

Author: haoya
Time:	2015/3/13 10:50AM
*/
#include<stdio.h>

int hammingWeight(int n) {
	int res = 0;
	while (n){
		res += (n % 2 == 1) ? 1 : 0;
		n >>= 1;
	}
	return res;
}

int main(){
	printf("%d", hammingWeight(32));
}