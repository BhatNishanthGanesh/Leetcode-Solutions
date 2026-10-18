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
    bool isLeaf(TreeNode*root){
        return root!=nullptr && root->left==nullptr && root->right==nullptr;
    }
    bool solve(TreeNode*root,int targetSum){
        if(!root) return false;
        if(isLeaf(root) && targetSum==0) return true;
        bool left=false;
        if(root->left) left=solve(root->left,targetSum-root->left->val);
        bool right=false;
        if(root->right) right=solve(root->right,targetSum-root->right->val);
        return left||right;
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(!root) return false;
        return solve(root,targetSum-root->val);
    }
};