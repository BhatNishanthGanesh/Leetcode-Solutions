/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int Lheight(TreeNode*root){
        int depth=0;
        while(root!=NULL){
            root=root->left;
            depth++;
        } 
        return depth;
    }
    int Rheight(TreeNode*root){
        int depth=0;
        while(root!=NULL){
            root=root->right;
            depth++;
        }
        return depth;
    }
    int countNodes(TreeNode* root) {
        if(!root) return 0;
        int left=Lheight(root);
        int right=Rheight(root);
        if(left==right) return pow(2,left)-1;
        return 1+countNodes(root->left)+countNodes(root->right);
    }
};