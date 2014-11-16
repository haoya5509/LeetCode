/**
Word Break Total Accepted: 29922 Total Submissions: 140276 My Submissions Question Solution 
Given a string s and a dictionary of words dict, determine if s can be segmented into a space-separated sequence of one or more dictionary words.

For example, given
s = "leetcode",
dict = ["leet", "code"].

Return true because "leetcode" can be segmented as "leet code".

Author: haoya5509
Time: 10:37AM 2014/11/15
*/
#include<iostream>
#include<string>
#include<set>
bool wordBreak(string s, unordered_set<string> &dict){
	bool dp[10000];
	for(int i=0;i<s.size();i++) dp[i]=false;
	for(int i=0;i<s.size();i++){
		for(int j=i;j>=0;j--){
			string tmp(s.begin()+j,s.begin()+i+1);
			if(dict.find(tmp)!=dict.end()){
				if(j==0) dp[i]=true;
				if(j>0&&dp[j-1]){
					dp[i]=true;
					break;
				}
			}
		}			
	}
	return dp[s.size()-1];
}
