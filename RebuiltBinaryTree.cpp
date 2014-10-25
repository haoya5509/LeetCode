/**
rebuild binary tree by preOrder and inOrder Sequence
*/

#include<iostream>
using namespace std;
struct TreeNode{
    TreeNode* left;
    TreeNode* right;
    char ch;
};
void rebuild(char *pPreOrder,char *pInOrder,int nTreeLen,TreeNode **root){
    if(nTreeLen == 0){
        *root = NULL;
        return;
    }
    *root = new TreeNode();
    char curCh = pPreOrder[0];
    (*root)->ch = curCh;
    int pos = 0;
    for(int i=0;i<nTreeLen;i++)
        if(pInOrder[i] == curCh){
            pos = i;
            break;
        }
    rebuild(pPreOrder+1,pInOrder,pos,&((*root)->left));
    rebuild(pPreOrder+pos+1,pInOrder+pos+1,nTreeLen-pos-1,&((*root)->right));
}
void postOrder(TreeNode* root){
    if(root == NULL) return;
    postOrder(root->left);
    postOrder(root->right);
    cout << root->ch << "..";

}
int main(){
    TreeNode *root;
    rebuild("abcdefghi","dcebaghif",9,&root);
    /*
     d..e..c..b..i..h..g..f..a..
     */
    postOrder(root);
    cout << endl;
    return 0;
}