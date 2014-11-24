/**
Total Accepted: 30451 Total Submissions: 138118 My Submissions Question Solution
Given a string, find the length of the longest substring without repeating characters. For example, the longest substring without repeating letters for "abcabcbb" is "abc", which the length is 3. For "bbbbb" the longest substring is "b", with the length of 1.

Author: haoya5509
Time: 19:23PM 2014/11/21
*/
#include<iostream>
#include<string>
using namespace std;
int lengthOfLongestSubstring(string s) {
	int len=0;
	for(int i=s.size()/2;i>0;i--){
		for(int j=0;j<s.size()-i;j++){
			int m,k;
			for(m=1;m<i;m++){
                if(s[m+j]!=s[j]){
                    break;
                }
			}
			cout<<m<<"..."<<i<<endl;
			if(m==i)
                continue;
			for(k=0;k<i;k++){
				if(k+j+i>=s.size()||s[k+j]!=s[k+j+i])
					break;
			}
			if(k==i)
				return i;
		}
	}
	return len;
}
int main(){
	string s("bbbbbb");
	cout<<s.size()<<endl;
	cout<<lengthOfLongestSubstring(s)<<endl;
}
