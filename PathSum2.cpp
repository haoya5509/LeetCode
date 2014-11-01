/**
Path Sum II Total Accepted: 24440 Total Submissions: 90956 My Submissions Question Solution 
Given a binary tree and a sum, find all root-to-leaf paths where each path's sum equals the given sum.

For example:
Given the below binary tree and sum = 22,
              5
             / \
            4   8
           /   / \
          11  13  4
         /  \    / \
        7    2  5   1
return
[
   [5,4,11,2],
   [5,8,4,5]
]

Author: haoya5509  
Time: 12:45Am 2014/11/2
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
    void pathSumInner(TreeNode* node, int sum,vector<vector<int> >& res,vector<int> &tmp,int cnt){
    if(node->left == NULL && node->right == NULL){
        if(cnt + node->val == sum) {
            tmp.push_back(node->val);
            res.push_back(tmp);
            tmp.pop_back();
        }
    }
    if(node->left){
        tmp.push_back(node->val);
        pathSumInner(node->left,sum,res,tmp,cnt+node->val);
        tmp.pop_back();
    }
    if(node->right){
        tmp.push_back(node->val);
        pathSumInner(node->right,sum,res,tmp,cnt+node->val);
        tmp.pop_back();
    }
}
vector<vector<int> > pathSum(TreeNode *root, int sum) {
    vector<vector<int> > res;
    if(!root) return res;
    vector<int> tmp;
    pathSumInner(root,sum,res,tmp,0);
    return res;
}
};