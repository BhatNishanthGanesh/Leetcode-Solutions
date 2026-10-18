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
        return root->left==nullptr && root->right==nullptr;
    }
    void solve(TreeNode*root,int targetSum,vector<int>&temp,vector<vector<int>>&v){
        if(!root) return;
        if(isLeaf(root) && targetSum-root->val==0){
            temp.push_back(root->val);
            v.push_back(temp);
            temp.pop_back();
            return;
        }
        temp.push_back(root->val);
        solve(root->left,targetSum-root->val,temp,v);
        solve(root->right,targetSum-root->val,temp,v);
        temp.pop_back();
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>>v;
        if(!root) return v;
        vector<int>temp;
        solve(root,targetSum,temp,v);
        return v;
    }
};