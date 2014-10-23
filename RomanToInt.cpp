#include<iostream>
#include<string>
using namespace std;
class Solution{
public:
	int romanCharToInt(char ch){
		int d = 0;
		switch(ch){
			case 'I':  
				d = 1;  
				break;  
			case 'V':  
				d = 5;  
				break;  
			case 'X':  
				d = 10;  
				break;  
			case 'L':  
				d = 50;  
				break;  
			case 'C':  
				d = 100;  
				break;  
			case 'D':  
				d = 500;  
				break;  
			case 'M':  
				d = 1000;  
				break;  
		}
		return d;
	}
	int romanToInt(string s){
		if(s.size()<=0) return 0;
		int result = romanCharToInt(s[0]);
		string::size_type len = s.size();
		for(string::size_type i=1;i<len;i++){
			int pre = romanCharToInt(s[i-1]);
			int cur = romanCharToInt(s[i]);
			if(pre < cur){
				result = result - pre + (cur-pre);
			}else{
				result += cur;
			}
		}
		return result;
	}
};
int main(){
	
}