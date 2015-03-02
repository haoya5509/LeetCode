/**
Excel Sheet Column Number Total Accepted: 3780 Total Submissions: 8984 My Submissions Question Solution 
Related to question Excel Sheet Column Title

Given a column title as appear in an Excel sheet, return its corresponding column number.

For example:

    A -> 1
    B -> 2
    C -> 3
    ...
    Z -> 26
    AA -> 27
    AB -> 28 

Author:	haoya
Time:	11:11PM 2015/1/4
*/

int titleToNumber(string s) {
	int res=0,fac=1;
	for(int i=s.length()-1;i>=0;i--){
		res+=fac*(s[i]-'A'+1);
		fac*=26;
	}  
	return res;      
}