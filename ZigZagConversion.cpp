/**
 * ZigZag Conversion Total Accepted: 32391 Total Submissions: 145280 My Submissions Question Solution 
 * The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this: (you may want to display this pattern in a fixed font for better legibility)
 *
 * P   A   H   N
 * A P L S I I G
 * Y   I   R
 * And then read line by line: "PAHNAPLSIIGYIR"
 * Write the code that will take a string and make this conversion given a number of rows:
 *
 * string convert(string text, int nRows);
 * convert("PAYPALISHIRING", 3) should return "PAHNAPLSIIGYIR".
 *
 * Author:	Haoya.
 * Time:	2015/3/23 9:20pm.
 */
#include<iostream>
#include<string>
using namespace std;
string convert(string s, int nRows) {
	string res;
	int margin = nRows*2 - 2;
	margin = margin!=0 ? margin : 1;
	int k=0;
	for(int i=0;i<nRows;i++){
		for(int j=i;j<s.length();j+=margin){
			res.push_back(s[j]);
			if(i>0 && i<nRows-1 && (j+2*(nRows-i)-2)<s.length()){
				res.push_back(s[j+2*(nRows-i)-2]);
			}
		}
	}
	cout << res.length() << endl;
	return res;
}
int main(){
	cout << convert("P",1) << endl;
	return 0;
}
