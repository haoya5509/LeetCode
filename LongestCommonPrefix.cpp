/**
Longest Common Prefix Total Accepted: 21543 Total Submissions: 79494 My Submissions Question Solution 
Write a function to find the longest common prefix string amongst an array of strings.

Author:haoya5509
Time:22:24 2014/10/23
*/


#include<iostream>
#include<vector>
#include<string>
using namespace std;
class Solution{
public:
	string longestCommonPrefix(vector<string>& strs){
		if(strs.size() <= 0) return "";
		string prefix;
		string shortest = strs[0];
		string::size_type shortestLen = strs[0].size();
		for(vector<string>::size_type i=0;i<strs.size();i++){
			if(strs[i].size() < shortestLen){
				shortestLen = strs[i].size();
				shortest = strs[i];
			}
		}
		for(string::size_type i=0;i<=shortestLen;i++){
			string new_prefix = shortest.substr(0,i);
			vector<string>::size_type j=0;
			for(;j<strs.size();j++){
				if(new_prefix != strs[j].substr(0,i))
					break;
			}
			if(j>=strs.size())
				prefix = new_prefix;
			else
				break;
		}
		return prefix;
	}
};
int main(){
	Solution solution;
	vector<string> vec;
	vec.push_back("flower");
	vec.push_back("flow");
	vec.push_back("flight");
	cout << solution.longestCommonPrefix(vec);
	system("pause");
	return 0;
}