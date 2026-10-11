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
    pair<int,int> solve(TreeNode*root){
        if(!root) return {0,0};
        auto [L1,L2]=solve(root->left);
        auto [R1,R2]=solve(root->right);
        int take=root->val+L2+R2;
        int skip=max(L1,L2)+max(R1,R2);
        return {take,skip};
    }
    int rob(TreeNode* root) {
        auto[L,R]=solve(root);
        return max(L,R);
    }
};