/**
Decode Ways Total Accepted: 21457 Total Submissions: 132883 My Submissions Question Solution 
A message containing letters from A-Z is being encoded to numbers using the following mapping:

'A' -> 1
'B' -> 2
...
'Z' -> 26
Given an encoded message containing digits, determine the total number of ways to decode it.

For example,
Given encoded message "12", it could be decoded as "AB" (1 2) or "L" (12).

The number of ways decoding "12" is 2.

Author: haoya5509
Time: 10:32PM 2014/11/14
*/

#include<iostream>
#include<string>
using namespace std;
int numDecodings(string s) {
	if(s.size()==0 || s[0]=='0') return 0;
	int pre,pre2,res;
	res=pre=1;
	pre2=1;
	for(int i=1;i<s.size();i++){
		if(s[i]=='0'){
			if(s[i-1]!='1'&&s[i-1]!='2')
				return 0;
			res=pre2;
			pre2=pre;
			pre=res;
		}else if((s[i]-'0'+(s[i-1]-'0')*10)<=26 && s[i-1]!='0'){
			res=pre+pre2;
			pre2=pre;
			pre=res;
		}else{
			res=pre;
			pre2=pre;
			pre=res;
		}
	}    
	return res;    
}
int main(){
	cout<<numDecodings("101")<<endl;
	return 0;
}