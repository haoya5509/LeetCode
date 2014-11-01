/**
Binary Tree Preorder Traversal Total Accepted: 41326 Total Submissions: 116250 My Submissions Question Solution 
Given a binary tree, return the preorder traversal of its nodes' values.

For example:
Given binary tree {1,#,2,3},
   1
    \
     2
    /
   3
return [1,2,3].

Note: Recursive solution is trivial, could you do it iteratively?

Author: haoya5509
Time: 1:11 2014/11/1
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
    vector<int> preorderTraversal(TreeNode *root) {
        vector<TreeNode *> s;
        vector<int> v;
        if(!root) return v;
        s.push_back(root);
        while(s.size()>0){
            TreeNode *node = s.back();
            s.pop_back();
            v.push_back(node->val);
            if(node->right) s.push_back(node->right);
            if(node->left) s.push_back(node->left);
        }
        return v;
    }
};