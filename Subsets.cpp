/**
Subsets Total Accepted: 29251 Total Submissions: 105316 My Submissions Question Solution
Given a set of distinct integers, S, return all possible subsets.

Note:
Elements in a subset must be in non-descending order.
The solution set must not contain duplicate subsets.
For example,
If S = [1,2,3], a solution is:

[
  [3],
  [1],
  [2],
  [1,2,3],
  [1,3],
  [2,3],
  [1,2],
  []
]

Author: haoya5509
Time: 20:52PM 2014/11/19
*/
#include<vector>
#include<bitset>
#include<algorithm>
#include<iostream>
using namespace std;
int cmp(int a,int b){
    return a>b;
}
void dfs(vector<int> &S,int start,vector<vector<int> > &res,vector<int> &bit){//bitset<1000> &bit){
    vector<int> tmp;
    for(int i=0;i<S.size();i++){
        if(bit[i])
            tmp.push_back(S[i]);
    }
    res.push_back(tmp);
    for(int i=start;i<S.size();i++){
        if(!bit[i]){
            bit[i]=1;
            dfs(S,i+1,res,bit);
            bit[i]=0;
        }
    }
}
vector<vector<int> > subsets(vector<int> &S) {
    sort(S.begin(),S.end(),less<int>());//cmp);
    vector<vector<int> > res;
    //bitset<1000> bit;
    vector<int> flag(S.size());
    dfs(S,0,res,flag);
    return res;
}
int main(){
    int a[3]={1,2,3};
    vector<int> data(a,a+3);
    vector<vector<int> > res = subsets(data);
    for(int i=0;i<res.size();i++){
        for(int j=0;j<res[i].size();j++)
            cout<<res[i][j]<<"...";
        cout<<endl;
    }
}
