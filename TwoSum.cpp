/**
 *Two Sum Total Accepted: 43108 Total Submissions: 234253 My Submissions Question Solution
 Given an array of integers, find two numbers such that they add up to a specific target number.

 The function twoSum should return indices of the two numbers such that they add up to the target, where index1 must be less than index2. Please note that your returned answers (both index1 and index2) are not zero-based.

 You may assume that each input would have exactly one solution.

Input: numbers={2, 7, 11, 15}, target=9
Output: index1=1, index2=2

Author: haoya5509
Time: 11:18PM 2014/11/20
 * */
#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
using namespace std;
struct node{
	int num;
	int index;
	node(int n,int i):num(n),index(i){}
};
bool operator<(const node &a,const node &b){
    return a.num<b.num;
}
vector<int> twoSum(vector<int> &numbers, int target) {
	vector<node> vn;
    vector<int> res;
	for(int i=0;i<numbers.size();i++){
		node n(numbers[i],i+1);
		vn.push_back(n);
	}
	sort(vn.begin(),vn.end());
	int i=0,j=vn.size()-1;
	while(i<j){
        if(vn[i].num+vn[j].num==target){
            res.push_back(min(vn[i].index,vn[j].index));
            res.push_back(max(vn[i].index,vn[j].index));
            return res;
        }else if(vn[i].num+vn[j].num<target){
            i++;
        }else{
            j--;
        }
	}
	return res;
}

vector<int> twoSum2(vector<int> &numbers, int target){
	map<int,int> m;
	vector<int> res;
	for(int i=0;i<numbers.size();i++){
		if(m.find(numbers[i])==m.end()){
			m[target-numbers[i]]=i;
		}else{
			res.push_back(m[numbers[i]]+1);
			res.push_back(i+1);
		}
	}
	return res;
}

int main(){
	int a[] = {2,7,11,14};
	vector<int> dat(a,a+4);
	vector<int> res=twoSum2(dat,13);
	for(int i=0;i<res.size();i++)
		cout<<res[i]<<"...";
	cout<<endl;
	return 0;
}