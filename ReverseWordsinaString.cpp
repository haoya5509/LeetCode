/**

Reverse Words in a String Total Accepted: 40913 Total Submissions: 292374 My Submissions Question Solution 
Given an input string, reverse the string word by word.

For example,
Given s = "the sky is blue",
return "blue is sky the".

click to show clarification.

Clarification:
What constitutes a word?
A sequence of non-space characters constitutes a word.
Could the input string contain leading or trailing spaces?
Yes. However, your reversed string should not contain leading or trailing spaces.
How about multiple spaces between two words?
Reduce them to a single space in the reversed string.

Author: haoya5509
Time: 1:27am 2014/11/4
*/

//Leetcode without cout!!!
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<sstream>
using namespace std;
void reverseWords(string &s) {
	string ss(s),rs;
	reverse(ss.begin(),ss.end());
	istringstream stream(ss);
	//ostringstream os;
	string word;
	if(stream >> word){
		reverse(word.begin(),word.end());
		rs+=word;
	}
	while(stream >> word){
		reverse(word.begin(),word.end());
		rs+=" "+word;
	}
	s=rs;
	//cout<<"]"<<endl;
}
void reverseWords1(string &s) {
    
    bool wordStart = false;
    vector<string> v;
    
    const char *pHead =s.c_str();
    const char *pStr, *pBegin, *pEnd;
   
    for (pStr=pHead; *pStr!='\0'; pStr++) {
        if (!isspace(*pStr) && wordStart == false){
            wordStart = true;
            pBegin = pStr;
            continue;
        }
        
        if(isspace(*pStr) && wordStart==true){
            wordStart=false;
            pEnd = pStr;
            v.insert(v.begin(), s.substr(pBegin-pHead, pEnd-pBegin) );
        }
        
    }

    if (wordStart==true){
        pEnd = pStr;
        v.insert(v.begin(), s.substr(pBegin-pHead, pEnd-pBegin) );
    }
    
    if (v.size()>0){
        s.clear();
        char space=' ';
        vector<string>::iterator it;
        for (it=v.begin(); it!=v.end(); ++it) {
            s = s + *it;
            s.push_back(space);
        }
        s.erase(s.end()-1);
    }else{
            s.clear();
    }
    cout << "[" << s << "]" <<endl;
}
int main(){
	string ss="aa bb";
	reverseWords(ss);
	cout<<ss<<endl;
	return 0;
}