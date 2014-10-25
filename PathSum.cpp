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
	void printPostSeqInner(TreeNode *node);
	void printMidSeqInner(TreeNode *node);
	void printLevelSeqInner(TreeNode *node);
    TreeNode* buildTree(const vector<int>&,int& pos);
    vector<int> initData(const string&input);
public:
    Solution(const string& input){
        int pos = 0;
        vector<int> vec = initData(input);
        root = buildTree(vec,pos);
		cout << "Test: " << hasPathSum(root,12) << endl;
    }
    void printSeq(const string& type="pre");
    bool hasPathSum(TreeNode *root, int sum);
};
bool Solution::hasPathSum(TreeNode *root,int sum){
	if(root == NULL)
		return false;
	if(root->left == NULL && root->right == NULL)
		return root->val == sum?true:false;
	if(root->left && hasPathSum(root->left,sum-root->val))
		return true;
	if(root->right && hasPathSum(root->right,sum-root->val))
		return true;
	return false;	
}
void Solution::printPreSeqInner(TreeNode* node){
    if(node == NULL)
        return;
    cout << node->val << "...";
    printPreSeqInner(node->left);
    printPreSeqInner(node->right);
}
void Solution::printSeq(const string& type){
	if(type == "pre")
	    printPreSeqInner(this->root);
	else if(type == "post")
		printPostSeqInner(this->root);
	else if(type == "mid")
		printMidSeqInner(this->root);
	else if(type == "level")
		printLevelSeqInner(this->root);
    cout << endl;
}
void Solution::printPostSeqInner(TreeNode* node){
	if(node == NULL) return;
	printPostSeqInner(node->left);
	printPostSeqInner(node->right);
	cout << node->val << "...";
}
void Solution::printMidSeqInner(TreeNode* node){
	if(node == NULL) return;
	printMidSeqInner(node->left);
	cout << node->val << "...";
	printMidSeqInner(node->right);
}
void Solution::printLevelSeqInner(TreeNode* node){
	if(node == NULL) return;
	queue<TreeNode* > levelVec;
	levelVec.push(node);
	while(!levelVec.empty()){
		TreeNode* cur = levelVec.front();
		levelVec.pop();
		cout << cur->val << "...";
		if(cur->left) levelVec.push(cur->left);
		if(cur->right) levelVec.push(cur->right);
	}
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
    return preVec;
}
TreeNode* Solution::buildTree(const vector<int>& vec,int& pos){
    TreeNode* node;
    if(pos>=vec.size() || vec[pos] == -1){
        pos++;
        return NULL;
    }
    node = new TreeNode(vec[pos++]);
    node->left = buildTree(vec,pos);
	node->right = buildTree(vec,pos);
    return node;
}

int main(){
	Solution solution("5,4,11,7,#,#,2,#,#,#,8,13,#,#,4,#,1");
    solution.printSeq();
	solution.printSeq("post");
	solution.printSeq("mid");
	solution.printSeq("level");
    system("pause");
    return 0;
}
