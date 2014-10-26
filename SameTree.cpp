/**
Same Tree Total Accepted: 33979 Total Submissions: 81231 My Submissions Question Solution 
Given two binary trees, write a function to check if they are equal or not.

Two binary trees are considered equal if they are structurally identical and the nodes have the same value.

Author: haoya5509
Time: 12:01Am 2014/10/27
*/


class Solution {
public:
    bool isSameTree(TreeNode *p, TreeNode *q) {
        if(!p && !q) return true;
        if((p && !q) || (q && !p)) return false; 
        //if(p->val!=q && p) return false;
        return isSameTree(p->left,q->left) && isSameTree(p->right,q->right) && (p->val==q->val);
    }
};