/**
Given an index k, return the kth row of the Pascal's triangle.

For example, given k = 3,
Return [1,3,3,1].

Note:
Could you optimize your algorithm to use only O(k) extra space?

Author:haoya5509   
Time 12:55 2014/10/24 
*/

#include<iostream>
#include<vector>
using namespace std;
class Solution{
public:
	vector<int> getRow(int rowIndex){
		vector<int> res(1,1);
		for(int i=1;i<=rowIndex;i++){
			for(int j=i-1;j>0;j--){
				res[j] = res[j]+res[j-1];
			}
			res.push_back(1);
		}
		return res;
	}
};

int main(){
    Solution solution;
    vector<int> cnt = solution.getRow(4);
    for(vector<int>::const_iterator iter=cnt.begin();iter!=cnt.end();iter++){
        cout << *iter << "..";
    }cout<<endl;
    return 0;
}