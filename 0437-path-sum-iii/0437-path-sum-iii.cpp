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
    long long calc(TreeNode*root,long long targetSum){
        if(!root) return 0;
        long long cnt=(targetSum==0)?1:0;
        if(root->left) cnt+=calc(root->left,targetSum-root->left->val);
        if(root->right) cnt+=calc(root->right,targetSum-root->right->val);
        return cnt;
    }
    void solve(TreeNode* root,long long targetSum,int &cnt){
        if(!root) return;
        cnt+=calc(root,targetSum-root->val);
        solve(root->left,targetSum,cnt);
        solve(root->right,targetSum,cnt);
    }
    int pathSum(TreeNode* root, int targetSum) {
        int cnt=0;
        solve(root,targetSum,cnt);
        return cnt;
    }
};