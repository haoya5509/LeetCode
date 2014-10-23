#include<iostream>
#include<stdlib.h>
#include<string>
using namespace std;
class Solution{
public:
	bool isPalindrome(string s){
		if(s.empty()) return true;
		string::size_type len = s.size();
		string sBak;
		for(string::size_type i=0;i<len;i++){
			if(isalnum(s[i]))
				sBak.push_back(tolower(s[i]));
		}
		string::size_type lenBak = sBak.size();
		int	lenBakHalf = (int)((lenBak+1)/2);
		for(int i=0;i<lenBakHalf;i++){
			if(sBak[i] != sBak[lenBak-i-1])
				return false;
		}
		return true;
	}
};
int main(){
	Solution solution;
	cout << solution.isPalindrome("    ") << endl;
	cout << solution.isPalindrome("A man, a plan, a canal: Panama") << endl;
	cout << solution.isPalindrome("race a car") << endl;
	system("pause");
	return 0;
}