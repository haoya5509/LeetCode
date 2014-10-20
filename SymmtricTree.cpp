//
//  main.cpp
//  LeetCode
//
//  Created by 云昇 郝 on 10/20/14.
//  Copyright (c) 2014 haoya. All rights reserved.
//
#include<iostream>
#include<string>
#include<stdlib.h>
#include<cctype>
#include<queue>
using namespace std;
/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x):val(x),left(NULL),right(NULL){}
};
//solution for symmetric Tree
class Solution {
private:
public:
    TreeNode *root;
    Solution(const string input);
    bool isSymmetric(TreeNode *root);
};
Solution::Solution(const string input){
    string tmp;
    tmp.assign(input,1,input.size()-2);
    int i=0;
    queue<int> q;
    while(i<tmp.size()){
        int num = 0;
        if(tmp.at(i)==','){
            i++;
            continue;
        }
        if(tmp.at(i) == '#'){
            q.push(-1);
            i++;
            continue;
        }
        while(i<tmp.size() && isdigit(tmp.at(i))){
            num*=10;
            num+=tmp.at(i)-'0';
            i++;
        }
        q.push(num);
    }
    root = new TreeNode(q.front());
    q.pop();
    queue<TreeNode *> qTN;
    qTN.push(root);
    while(!qTN.empty()){
        //cout << root->val << endl;
        TreeNode *cur = qTN.front();
        qTN.pop();
        if(!q.empty()){
            if(q.front()!=-1)
                qTN.push(cur->left = new TreeNode(q.front()));
            q.pop();
        }
        if(!q.empty()){
            if(q.front()!=-1)
                qTN.push(cur->right = new TreeNode(q.front()));
            q.pop();
        }
    }
}
bool Solution::isSymmetric(TreeNode *root){
    queue<TreeNode *> qTN;
    TreeNode *p = root;
    if(root == NULL) return true;
    qTN.push(p);
    vector<int> v1,v2;
    v1.push_back(p->val);
    v2.push_back(p->val);
    while(!qTN.empty()){
        TreeNode *cur = qTN.front();
        //cout << cur->val << "..";
        if(cur->left!=NULL) {
            qTN.push(cur->left);
            v1.push_back(cur->left->val);
        }else{
            v1.push_back(-1);
        }
        if(cur->right!=NULL) {
            qTN.push(cur->right);
            v1.push_back(cur->right->val);
        }else{
            v1.push_back(-1);
        }
        qTN.pop();
    }
    qTN.push(root);
    while(!qTN.empty()){
        TreeNode *cur = qTN.front();
        //cout << cur->val << "..";
        if(cur->right!=NULL) {
            qTN.push(cur->right);
            v2.push_back(cur->right->val);
        }else{
            v2.push_back(-1);
        }
        if(cur->left!=NULL) {
            qTN.push(cur->left);
            v2.push_back(cur->left->val);
        }else{
            v2.push_back(-1);
        }
        qTN.pop();
    }
    return (v1 == v2);
}



int main(){
    string ss = "{1,2,2,3,4,4,3}";//"{1,2,3,#,#,4,#,#,5}";
    Solution solution(ss);
    cout << solution.isSymmetric(solution.root) << endl;
    return 0;
}

