/**
Combinations Total Accepted: 24249 Total Submissions: 80637 My Submissions Question Solution 
Given two integers n and k, return all possible combinations of k numbers out of 1 ... n.

For example,
If n = 4 and k = 2, a solution is:

[
  [2,4],
  [3,4],
  [2,3],
  [1,2],
  [1,3],
  [1,4],
]

Author: haoya5509
Time: 12:50Am 2014/10/30
*/

class Solution {
public:
    void dfs(int n,int k,int t,int min,vector<int> &cnt,vector<bool> &flag,vector<vector<int> >& res){
    if(t == k){
        res.push_back(cnt);
        return;
    }
    for(int i=min;i<=n;i++){
        if(!flag[i-1]){
            cnt.push_back(i);
            flag[i-1] = true;
            t+=1;
            dfs(n,k,t,i,cnt,flag,res);
            flag[i-1] = false;
            cnt.pop_back();
            t-=1;
        }
    }
}
vector<vector<int> > combine(int n, int k) {
    vector<vector<int> > res;
    vector<bool> flag;
    for(int i=0;i<n;i++)
        flag.push_back(false);
    vector<int> cnt;
    dfs(n,k,0,1,cnt,flag,res);
    return res;
}
};