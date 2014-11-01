/**
Flatten Binary Tree to Linked List Total Accepted: 27239 Total Submissions: 96622 My Submissions Question Solution 
Given a binary tree, flatten it to a linked list in-place.

For example,
Given

         1
        / \
       2   5
      / \   \
     3   4   6
The flattened tree should look like:
   1
    \
     2
      \
       3
        \
         4
          \
           5
            \
             6
click to show hints.

Hints:
If you notice carefully in the flattened tree, each node's right child points to the next node of a pre-order traversal.

Author: haoya5509
Time: 1:03Am 2014/11/2
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
    void preVisit(TreeNode *node, vector<TreeNode *>& v){
    if(!node) return;
    v.push_back(node);
    preVisit(node->left,v);
    preVisit(node->right,v);
}
void flatten(TreeNode *root) {
    if(!root) return;
    vector<TreeNode *> v;
    preVisit(root,v);
    for(int i=0;i!=v.size()-1;i++){
        v[i]->right = v[i+1];
        v[i]->left = NULL;
    }
    v[v.size()-1]->right = NULL;
    v[v.size()-1]->left = NULL;
}
};