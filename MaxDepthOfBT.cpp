/**
Given a binary tree, find its maximum depth.

The maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.

Author: haoya5509
Time: 14:07 2014/10/25 Maximum depth of Binary Tree
*/

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
public:
    int maxDepth(TreeNode *root){
		if(root == NULL) return 0;
		if(root->left == NULL && root->right == NULL)
			return 1;
		int left=0,right=0;
		return (left = maxDepth(root->left)) < (right=maxDepth(root->right)) ? right+1 : left+1;
	}
};