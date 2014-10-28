/**
Implement strStr() Total Accepted: 23961 Total Submissions: 109699 My Submissions Question Solution 
Implement strStr().

Returns a pointer to the first occurrence of needle in haystack, or null if needle is not part of haystack.

Author:haoya5509
Time: 12:38 2014/10/29
*/

class Solution {
public:
    char *strStr(char *haystack, char *needle) {
    string s1(haystack),s2(needle);
    string::size_type index=s1.find(s2);
    if(index == string::npos) return NULL;
    return haystack+index;
}
};