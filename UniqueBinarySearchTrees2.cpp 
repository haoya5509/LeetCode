/**
Unique Binary Search Trees II Total Accepted: 17713 Total Submissions: 64913 My Submissions Question Solution 
Given n, generate all structurally unique BST's (binary search trees) that store values 1...n.

For example,
Given n = 3, your program should return all 5 unique BST's shown below.

   1         3     3      2      1
    \       /     /      / \      \
     3     2     1      1   3      2
    /     /       \                 \
   2     1         2                 3
confused what "{1,#,2,3}" means? > read more on how binary tree is serialized on OJ.

Author: haoya5509
Time: 18:01pm 2014/11/10
*/

#include<vector>
#include<iostream>
using namespace std;
/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
	int dp[10000];
	void numTrees(int n) {
		//int dp[10000];	//dp[i] stand for num i has bp[i] cases;
		dp[0]=1;
		dp[1]=1;
		for(int i=2;i<=n;i++){
			int res=0;
			for(int j=1;j<=i;j++){
				res+=dp[j-1]*dp[i-j];
			}
			dp[i]=res;
		}        
		//return dp[n];
	}
	TreeNode *copyTrees(TreeNode *root,int bv){
		if(!root)
			return NULL;
		TreeNode *nroot=new TreeNode(bv+root->val);
		nroot->left=copyTrees(root->left,bv);
		nroot->right=copyTrees(root->right,bv);
	}
	public:
	vector<TreeNode *> generateTrees(int n) {
		numTrees(n);
		vector<vector<TreeNode *> > allTrees;
		vector<TreeNode *> curTree;
		curTree.push_back(NULL);
		allTrees.push_back(curTree);
		curTree.clear();
		TreeNode *root1=new TreeNode(1);
		curTree.push_back(root1);
		allTrees.push_back(curTree);
		for(int i=2;i<=n;i++){
			curTree.clear();
			for(int j=1;j<=i;j++){
				for(int p=0;p<dp[j-1];p++){
					for(int q=0;q<dp[i-j];q++){
						TreeNode *root=new TreeNode(j);
						root->left=copyTrees(allTrees[j-1][p],0);
						root->right=copyTrees(allTrees[i-j][q],j);
						curTree.push_back(root);
					}
				}
			}
			allTrees.push_back(curTree);
		}
		return allTrees[n];
	}
};