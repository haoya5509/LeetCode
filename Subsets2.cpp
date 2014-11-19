/**
Subsets II Total Accepted: 22547 Total Submissions: 83343 My Submissions Question Solution
Given a collection of integers that might contain duplicates, S, return all possible subsets.

Note:
Elements in a subset must be in non-descending order.
The solution set must not contain duplicate subsets.
For example,
If S = [1,2,2], a solution is:

[
  [2],
  [1],
  [1,2,2],
  [2,2],
  [1,2],
  []
]

Author: haoya5509
Time: 21:26PM 2014/11/19
*/

void dfs(vector<int> &S,int start,vector<vector<int> > &res,vector<int> &bit){//bitset<1000> &bit){
    vector<int> tmp;
    for(int i=0;i<S.size();i++){
        if(bit[i])
            tmp.push_back(S[i]);
    }
    res.push_back(tmp);
    for(int i=start;i<S.size();i++){
        if(i>0&&!bit[i-1]&&S[i]==S[i-1])
            continue;
        if(!bit[i]){
            bit[i]=1;
            dfs(S,i+1,res,bit);
            bit[i]=0;
        }
    }
}
vector<vector<int> > subsetsWithDup(vector<int> &S) {
    sort(S.begin(),S.end(),less<int>());//cmp);
    vector<vector<int> > res;
    //bitset<1000> bit;
    vector<int> flag(S.size());
    dfs(S,0,res,flag);
    return res;
}
