/**
Binary Tree Level Order Traversal II Total Accepted: 21638 Total Submissions: 69758 My Submissions Question Solution 
Given a binary tree, return the bottom-up level order traversal of its nodes' values. (ie, from left to right, level by level from leaf to root).

For example:
Given binary tree {3,9,20,#,#,15,7},
    3
   / \
  9  20
    /  \
   15   7
return its bottom-up level order traversal as:
[
  [15,7],
  [9,20],
  [3]
]
confused what "{1,#,2,3}" means? > read more on how binary tree is serialized on OJ.

Author: haoya5509
Time: 10:53PM 2014/10/25
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
    vector<vector<int> > levelOrderBottom(TreeNode *root) {
        vector<vector<int> > res;
        if(root == NULL) return res;
        int level = maxLevel(root);
        for(int i=level;i>0;i--){
            vector<int> curVec;
            printNodeAtLevel(root,i,curVec);
            res.push_back(curVec);
        }
        return res;
    }
    int maxLevel(TreeNode *root){
        if(root==NULL) return 0;
        return max(maxLevel(root->left)+1,maxLevel(root->right)+1);
    }
    void printNodeAtLevel(TreeNode* root,int level,vector<int>& curVec){
        if(root == NULL) return;
        if(level == 1){
            curVec.push_back(root->val);
        }
        printNodeAtLevel(root->left, level-1,curVec);
        printNodeAtLevel(root->right, level-1,curVec);
    }
};