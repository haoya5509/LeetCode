/**
Implement strStr() Total Accepted: 23961 Total Submissions: 109699 My Submissions Question Solution 
Implement strStr().

Returns a pointer to the first occurrence of needle in haystack, or null if needle is not part of haystack.

Author:haoya5509
Time: 12:38 2014/10/29
*/
#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    char *strStr(char *haystack, char *needle) {
    string s1(haystack),s2(needle);
    string::size_type index=s1.find(s2);
    if(index == string::npos) return NULL;
    return haystack+index;
}
};

char *strStr(char *haystack,char *needle){
	if(!haystack||!needle) return NULL;	
	int hl=0,nl=0;
	for(;*(haystack+hl);hl++);
	for(;*(needle+nl);nl++);
	if(nl>hl) return NULL;
	cout << nl << "   " << hl << endl;
	vector<int> failed(nl);
	failed.push_back(-1);
	for(int i=1;i<nl;i++){
		int pos = failed[i-1];
		while(pos!=-1 && needle[pos+1] != needle[i]) pos = failed[pos];
		pos = (needle[pos+1] == needle[i])?pos+1:-1;
		cout << pos << endl;
		failed.push_back(pos);
	}
	for(int i=0;i<nl;i++)
		cout << failed[i] << "..";
	cout << endl;
	int i=0,j=0;
	while(j<nl || i<=hl-nl){
		if(haystack[i] == needle[j]){
			i++;
			j++;
			continue;	
		}
		int pos = failed[j];
		if(pos == -1){
			i++;
			j=0;	
		}else{
			j=pos;
		}
	}
	if(j==nl) return haystack+i-nl;
	return NULL;
}

int main(){
	cout << strStr("abacababc","abab");
	return 0;	
}
