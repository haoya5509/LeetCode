/**
Add Binary Total Accepted: 21077 Total Submissions: 82544 My Submissions Question Solution 
Given two binary strings, return their sum (also a binary string).

For example,
a = "11"
b = "1"
Return "100".

Author: haoya5509   
Time: 11:48Pm 2014/10/28
*/

class Solution {
public:
    string addBinary(string a, string b) {
    string res;
    if(a.size()<b.size())
        swap(a,b);
    string::reverse_iterator itera=a.rbegin(),iterb=b.rbegin();
    int step=0;
    while(iterb!=b.rend()){
        int sum = *(itera++)-'0'+*(iterb++)-'0'+step;
        res.insert(res.begin(),(sum)%2+'0');
        step=sum/2;
    }
    while(itera!=a.rend()){
        int sum = *(itera++)-'0' + step;
        res.insert(res.begin(),sum%2+'0');
        step=sum/2;
    }
    if(step) res.insert(res.begin(),'1');
    return res;
}
};