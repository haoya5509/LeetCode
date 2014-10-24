/**
Given a binary tree and a sum, determine if the tree has a root-to-leaf path such that adding up all the values along the path equals the given sum.

For example:
Given the below binary tree and sum = 22,
              5
             / \
            4   8
           /   / \
          11  13  4
         /  \      \
        7    2      1
return true, as there exist a root-to-leaf path 5->4->11->2 which sum is 22.

Author:haoya5509
Time 11:51PM 2014/10/24 PathSum.cpp
*/

#include<iostream>
#include<string>
#include<vector>
#include<queue>
#include<stdlib.h>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution{
private:
    TreeNode *root;
    void printPreSeqInner(TreeNode *node);
    TreeNode* buildTree(const vector<int>&);
    vector<int> initData(const string&input);
    int pos;
public:
    //input just as "1,2,#,#,3,4,#,5"
    Solution(const string& input){
        pos = 0;
        vector<int> vec = initData(input);
        root = buildTree(vec);
        pos = 0;
        cout << "..." << hasPathSum(root,3);
    }
    void printPreSeq();
    bool hasPathSum(TreeNode *root, int sum) {
        if(root==NULL) return false;
        return dfs(root,0,sum);
    }
    bool dfs(TreeNode* node,int sum,int res){
        bool flag = false;
        if(node->left == NULL && node->right == NULL)
            return (sum+node->val == res)?true:false;
        if(node->left)
            flag = dfs(node->left,sum+node->val,res);
        if(node->right)
            flag = flag || dfs(node->right,sum+node->val,res);
        return flag;
    }
};
void Solution::printPreSeqInner(TreeNode* node){
    if(node == NULL)
        return;
    cout << node->val << "...";
    printPreSeqInner(node->left);
    printPreSeqInner(node->right);
}
void Solution::printPreSeq(){
    printPreSeqInner(this->root);
    cout << endl;
}
vector<int> Solution::initData(const string& input){
    vector<int> preVec;
    for(size_t i=0;i<input.size();i++){
        if(input[i] == '#'){
            preVec.push_back(-1);
            continue;
        }
        if(input[i] == ',')
            continue;
        int sum = 0;
        while(i<input.size() && isdigit(input[i])){
            sum *= 10;
            sum += input[i] - '0';
            i++;
        }
        preVec.push_back(sum);
    }
    for(size_t i=0;i<preVec.size();i++){
        cout << preVec[i] << "...";
    }
    return preVec;
}
TreeNode* Solution::buildTree(const vector<int>& vec){
    TreeNode* node;
    if(pos>=vec.size() || vec[pos] == -1){
        pos++;
        return NULL;
    }
    node = new TreeNode(vec[pos++]);
    node->left = buildTree(vec);
    node->right = buildTree(vec);
    return node;
}

int main(){
    //Solution solution("5,4,11,7,#,#,2,#,#,8,13,#,#,4,#,1");
    Solution solution("1,2");
    solution.printPreSeq();
    system("pause");
    return 0;
}
