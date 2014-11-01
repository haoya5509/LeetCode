/**
Longest Palindromic Substring Total Accepted: 24116 Total Submissions: 116874 My Submissions Question Solution 
Given a string S, find the longest palindromic substring in S. You may assume that the maximum length of S is 1000, and there exists one unique longest palindromic substring.

Author: haoya5509
Time: 11:51PM 2014/11/1
*/

class Solution {
public:
string findPalindrome(string s,int l,int r){
    //string sub;
    if(r>=s.length()) return s.substr(l,r-l);
    while(l>=0 && r<s.length() && s[l] == s[r]){
        l--;
        r++;
    }
    return s.substr(l+1,r-l-1);
}
//O(n)
string longestPalindrome(string s){
    string sub;
    for(int i=0;i<s.length();i++){
        string tmp = findPalindrome(s,i,i);
        if(tmp.length() > sub.length())
            sub = tmp;
        tmp = findPalindrome(s,i,i+1);
        if(tmp.length() > sub.length())
            sub = tmp;
    }
    return sub;
}
};