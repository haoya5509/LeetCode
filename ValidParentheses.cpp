/**
Valid Parentheses Total Accepted: 22834 Total Submissions: 80788 My Submissions Question Solution 
Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

The brackets must close in the correct order, "()" and "()[]{}" are all valid but "(]" and "([)]" are not.

Author:haoya5509    
Time: 12:02Am 2014/10/28
*/

#include <iostream>
#include<stack>
using namespace std;
bool isValid(string s){
    char st[1000000];
    int index=-1;
    //stack<char> chStack;
    for(size_t i=0;i<s.size();i++){
        if(s[i]=='('||s[i]=='['||s[i]=='{')
            st[++index] = (s[i]);
        else if(s[i]==')'||s[i]==']'||s[i]=='}'){
            if(index<0) return false;
            char curCh= st[index--];
            if(s[i]==')'&&curCh!='(') return false;
            if(s[i]==']'&&curCh!='[') return false;
            if(s[i]=='}'&&curCh!='{') return false;
        }
    }
    if(index>=0) return false;
    return true;
}
int main(){
    cout << isValid("[]({)");
    return 0;
}