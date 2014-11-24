/**
Binary Tree Zigzag Level Order Traversal Total Accepted: 20883 Total Submissions: 78876 My Submissions Question Solution
Given a binary tree, return the zigzag level order traversal of its nodes' values. (ie, from left to right, then right to left for the next level and alternate between).

For example:
Given binary tree {3,9,20,#,#,15,7},
    3
   / \
  9  20
    /  \
   15   7
return its zigzag level order traversal as:
[
  [3],
  [20,9],
  [15,7]
]
confused what "{1,#,2,3}" means? > read more on how binary tree is serialized on OJ.

Author: haoya5509
Time: 21:57PM 2014/11/24
*/
vector<vector<int> > zigzagLevelOrder(TreeNode *root) {
    vector<vector<int> > res;
    if(!root) return res;
    queue<pair<TreeNode *,int> > q;
    q.push(make_pair(root,1));
    int cur=0;
    vector<int> tmp;
    tmp.push_back(root->val);
    while(!q.empty()){
        //TreeNode *node=q.front();
        //q.pop();
        pair<TreeNode *,int> p=q.front();
        q.pop();
        if(p.second!=cur){
            if(cur%2)
                reverse(tmp.begin(),tmp.end());
            res.push_back(tmp);
            tmp.clear();
            cur=p.second;
        }
        if(p.first->left){
            q.push(make_pair(p.first->left,p.second+1));
            tmp.push_back(p.first->left->val);
        }
        if(p.first->right){
            q.push(make_pair(p.first->right,p.second+1));
            tmp.push_back(p.first->right->val);
        }
    }
    return res;
}
