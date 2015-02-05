/**
Excel Sheet Column Title Total Accepted: 5900 Total Submissions: 34444 My Submissions Question Solution 
Given a positive integer, return its corresponding column title as appear in an Excel sheet.

For example:

    1 -> A
    2 -> B
    3 -> C
    ...
    26 -> Z
    27 -> AA
    28 -> AB 

Author:	haoya
Time:	11:16PM 2015/1/4
*/
#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
string convertToTitle(int n) {
	string s;
	while(n>0){
		n-=1;
		s.push_back(n%26+'A');
		n/=26;
	}
	reverse(s.begin(),s.end());
	return s;        
}
int main(){
	cout << convertToTitle(28) << endl;
}
