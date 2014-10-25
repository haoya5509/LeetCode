/**
Balanced Binary Tree Total Accepted: 29151 Total Submissions: 89439 My Submissions Question Solution 
Given a binary tree, determine if it is height-balanced.

For this problem, a height-balanced binary tree is defined as a binary tree in which the depth of the two subtrees of every node never differ by more than 1.

Auther: haoya5509
Time: 14:03 2014/10/25 Balanced Binary Tree
*/
#include<iostream>
#include<queue>
#include<algorithm>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution{
	int minDepthLen;
public:
	int minDepth(TreeNode *root){
		if(root == NULL) return 0;
		int minDepthLen = -1;
		queue<pair<TreeNode*,int> > treeQueue;
		treeQueue.push(make_pair(root,1));
		while(!treeQueue.empty()){
			TreeNode* node = treeQueue.front().first;
			int len = treeQueue.front().second;
			treeQueue.pop();
			if(node->left == NULL && node->right == NULL){
				minDepthLen = (minDepthLen == -1?len:(minDepthLen<len?minDepthLen:len));
			}
			if(node->left)
				treeQueue.push(make_pair(node->left,len+1));
			if(node->right)
				treeQueue.push(make_pair(node->right,len+1));
		}
		return minDepthLen;
	}
	int maxDepth(TreeNode *root){
		if(root == NULL) return 0;
		if(root->left == NULL && root->right == NULL)
			return 1;
		int left=0,right=0;
		return (left = maxDepth(root->left)) < (right=maxDepth(root->right)) ? right+1 : left+1;
	}
	bool isBalanced(TreeNode* root){
		if(root == NULL) return true;
		bool flag = true;
		flag = isBalanced(root->left) && isBalanced(root->right);
		return flag && (abs(maxDepth(root->left) - maxDepth(root->right)) <=1 ? true : false);
	}
};
