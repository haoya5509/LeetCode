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
	TreeNode* buildTree(const vector<int>&,int);
	vector<int> initData(const string&input);
public:
	//input just as "1,2,#,#,3,4,#,5"
	Solution(const string& input){
		vector<int> vec = initData(input);
		root = buildTree(vec,0);
	}
	void printPreSeq();
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
TreeNode* Solution::buildTree(const vector<int>& vec,int i){
	TreeNode* node;
	if(i>=vec.size() || vec[i] == -1)
		return NULL;
	node = new TreeNode(vec[i]);
	node->left = buildTree(vec,i+1);
	node->right = buildTree(vec,i+2);
	return node;
}

int main(){
	cout << "asdf" << endl;
	Solution solution("1,2,#,#,3,4,#,5");
	cout << "~~" << endl;
	solution.printPreSeq();
	system("pause");
	return 0;
}