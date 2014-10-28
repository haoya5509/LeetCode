/**
Length of Last Word Total Accepted: 22773 Total Submissions: 78371 My Submissions Question Solution 
Given a string s consists of upper/lower-case alphabets and empty space characters ' ', return the length of last word in the string.

If the last word does not exist, return 0.

Note: A word is defined as a character sequence consists of non-space characters only.

For example, 
Given s = "Hello World",
return 5.

Author:haoya5509
Time: 12:17AM 2014/10/29
*/

class Solution {
public:
int lengthOfLastWord(const char *s) {
    int len = 0;
    int strlen=-1;
    bool flag=true;
    while(s[++strlen]!='\0');
    for(int i=strlen-1;i>=0;i--){
        if(!isblank(s[i])){
            len++;
            flag = false;
        }else{
            if(!flag) break;
            continue;
        }
    }
    return len;
}

};