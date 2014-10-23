/**
Given numRows, generate the first numRows of Pascal's triangle.

For example, given numRows = 5,
Return

[
     [1],
    [1,1],
   [1,2,1],
  [1,3,3,1],
 [1,4,6,4,1]
]

Author:haoya5509
Time:22:41 2014/10/23 
*/


#include<iostream>
#include<vector>
using namespace std;
class Solution{
public:
	vector<vector<int> > generate(int numRows){
		vector<vector<int> > res;
		vector<int> tmp;
		tmp.push_back(1);
		if(numRows <= 0) return res;
		res.push_back(tmp);
		for(int i=2;i<=numRows;i++){
			vector<int> newTmp;
			newTmp.push_back(1);
			for(int j=1;j<i-1;j++){
				newTmp.push_back(tmp[j-1]+tmp[j]);
			}
			newTmp.push_back(1);
			tmp = newTmp;
			res.push_back(tmp);
		}
		return res;
	}
};
int main(){
	return 0;
}