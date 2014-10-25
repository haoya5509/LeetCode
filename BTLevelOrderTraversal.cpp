/**
Binary Tree Level Order Traversal Total Accepted: 26137 Total Submissions: 85227 My Submissions Question Solution 
Given a binary tree, return the level order traversal of its nodes' values. (ie, from left to right, level by level).

For example:
Given binary tree {3,9,20,#,#,15,7},
    3
   / \
  9  20
    /  \
   15   7
return its level order traversal as:
[
  [3],
  [9,20],
  [15,7]
]
confused what "{1,#,2,3}" means? > read more on how binary tree is serialized on OJ.

Author: haoya5509
Time: 14:24 2014/10/25 
*/

#include<iostream>
#include<queue>
#include<vector>
using namespace std;
struct TreeNode { 
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution{
public:
	vector<vector<int> > levelOrder(TreeNode* root){
		vector<vector<int> > res;
		if(root == NULL) return res;
		queue<pair<TreeNode*,int>> treeQueue;
		treeQueue.push(make_pair(root,1));
		int curLevel = 1;
		vector<int> curVec;
		while(!treeQueue.empty()){
			TreeNode* node = treeQueue.front().first;
			int level = treeQueue.front().second;
			treeQueue.pop();
			if(level == curLevel)
				curVec.push_back(node->val);
			else{
				curLevel++;
				res.push_back(curVec);
				curVec.resize(0);
				curVec.push_back(node->val);
			}
			if(node->left) treeQueue.push(make_pair(node->left,level+1));
			if(node->right) treeQueue.push(make_pair(node->right,level+1));
		}
		res.push_back(curVec);
		return res;
	}
};