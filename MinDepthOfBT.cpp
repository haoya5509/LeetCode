/**
Given a binary tree, find its minimum depth.

The minimum depth is the number of nodes along the shortest path from the root node down to the nearest leaf node.

Auther: haoya5509
Time: 13:18 2014/10/25 Minimum Depth of Binary Tree
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
};
