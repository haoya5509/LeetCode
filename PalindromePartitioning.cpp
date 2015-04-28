/**
Palindrome Partitioning Total Accepted: 30678 Total Submissions: 117745 My Submissions Question Solution 
Given a string s, partition s such that every substring of the partition is a palindrome.

Return all possible palindrome partitioning of s.

For example, given s = "aab",
Return

  [
    ["aa","b"],
    ["a","a","b"]
  ]

Author:	haoya.
Time:	2015/02/05 12:12:49
*/
#include<iostream>
#include<vector>
#include<string>
using namespace std;

vector<vector<string> > partition(string s) {
	int size = s.size();
 	vector<vector<string> > res;
	vector<string> tmp;

	vector<vector<bool> > flag(size);
	for (int i = 0; i < m; ++i){
		vector<bool> row(m + 1, 0);
		row[0] = row[1] = true;
		flag[i] = row;
	}


	return res;
}