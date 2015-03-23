/**
 *Reverse Bits Total Accepted: 9274 Total Submissions: 34134 My Submissions Question Solution 
 Reverse bits of a given 32 bits unsigned integer.

 For example, given input 43261596 (represented in binary as 00000010100101000001111010011100), return 964176192 (represented in binary as 00111001011110000010100101000000).

 Follow up:
 If this function is called many times, how would you optimize it?

 Related problem: Reverse Integer

Credits:
Special thanks to @ts for adding this problem and creating all test cases.

Author:	Haoya.
Time:	2015/3/23 10.24pm
 * */
#include<iostream>
using namespace std;
uint32_t reverseBits(uint32_t n) {
	uint32_t res = 0x0;
	for(int i=0;i<32;i++){
		int k = (n&(1<<(31-i)))>0?1:0;
		res |= (k * (1<<i));
	}
	return res;
}	        
int main(){
	cout << reverseBits(43261596) << endl;
	return 0;
}
