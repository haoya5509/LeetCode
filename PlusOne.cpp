/**
Plus One Total Accepted: 23801 Total Submissions: 75643 My Submissions Question Solution 
Given a non-negative number represented as an array of digits, plus one to the number.

The digits are stored such that the most significant digit is at the head of the list.

Author: haoya5509
Time: 11:34 2014/10/28
*/

class Solution {
public:
    vector<int> plusOne(vector<int> &digits){
    vector<int> res;
    int plus = 1;
    for(size_t i=0;i != digits.size();i++){
        int x = digits[digits.size()-i-1];
        x+=plus;
        res.insert(res.begin(),x%10);
        plus=x/10;
    }
    if(plus) res.insert(res.begin(),1);
    return res;
}
};