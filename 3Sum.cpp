/**
 3Sum Total Accepted: 28925 Total Submissions: 173006 My Submissions Question Solution
 Given an array S of n integers, are there elements a, b, c in S such that a + b + c = 0? Find all unique triplets in the array which gives the sum of zero.
 
 Note:
 Elements in a triplet (a,b,c) must be in non-descending order. (ie, a ≤ b ≤ c)
 The solution set must not contain duplicate triplets.
 For example, given array S = {-1 0 1 2 -1 -4},
 
 A solution set is:
 (-1, 0, 1)
 (-1, -1, 2)
 
 Author: haoya5509
 Time: 11:12PM 2014/11/10
 */
#include<iostream>
#include<vector>
using namespace std;
void dfs(int start,int level,int sum,vector<int> &num,vector<vector<int> > &res,vector<int> &cur){
    if(level==3){
        if(!sum){
            vector<int> tmp(cur.begin(),cur.end());
            sort(tmp.begin(),tmp.end());
            res.push_back(tmp);
            //cur.pop_back();
            return;
        }
    }
    for(int i=start;i<num.size();i++){
        cur.push_back(num[i]);
        dfs(i+1,level+1,sum+num[i],num,res,cur);
        cur.pop_back();
    }
}
vector<vector<int> > threeSum2(vector<int> &num) {
    vector<vector<int> > res;
    vector<int> cur;
    for(int i=0;i<num.size();i++){
        cur.push_back(num[i]);
        dfs(i+1,1,num[i],num,res,cur);
        cur.pop_back();
    }
    vector<vector<int> > trueRes;
    for(int i=0;i<res.size();i++){
        vector<vector<int> >::iterator iter=find(res.begin(),res.begin()+i,res[i]);
        if(iter==res.begin()+i)
            trueRes.push_back(res[i]);
    }
    return trueRes;
}
vector<vector<int> > threeSum1(vector<int> &num){
	vector<vector<int> > res;
    vector<int> cur;
    for(int i=0;i<num.size();i++){
    	for(int j=i+1;j<num.size();j++){
    		for(int k=j+1;k<num.size();k++){
    			if(num[i]+num[j]+num[k]==0){
    				cur.push_back(num[i]);
    				cur.push_back(num[j]);
    				cur.push_back(num[k]);
    				sort(cur.begin(),cur.end());
			        vector<vector<int> >::iterator iter=find(res.begin(),res.end()+i,cur);
    				if(iter==res.begin()+i)
    					res.push_back(cur);
    				cur.clear();
    			}
    		}
    	}
    }
    return res;
}
vector<vector<int> > threeSum(vector<int> &num){
	vector<vector<int> > res;
    vector<int> cur;
    vector<int> rem;
    for(int i=0;i<num;i++){
    	rem.push_back(-num[i]);
    }
    for(int i=1;i<num.size();i++){
    	for(int j=i+1;j<num.size();j++){
    		if(num[i]+num[j]=)
    	}
    }
}
int main(){
    int num[]={-1,0,1,2,-1,4};
    vector<int> tmp(num,num+6);
    vector<vector<int> > res=threeSum1(tmp);
    //cout<<res.size()<<endl;
    for(int i=0;i<res.size();i++){
        for(int j=0;j<res[i].size();j++)
            cout<<res[i][j]<<"..";
        cout<<endl;
    }
    return 0;
}