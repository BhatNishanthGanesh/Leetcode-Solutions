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
    int dfs(TreeNode*root,unordered_map<TreeNode*,int>&mp){
        if(!root) return 0;
        int left=dfs(root->left,mp);
        int right=dfs(root->right,mp);
        mp[root]=root->val+left+right;
        return mp[root];
    }
    vector<int> findFrequentTreeSum(TreeNode* root) {
        unordered_map<TreeNode*,int>mp;
        unordered_map<int,int>freq;
        dfs(root,mp);
        vector<int>v;
        for(auto it:mp){
            freq[it.second]++;
        }
        int mx=0;
        for(auto it:freq){
            mx=max(mx,it.second);
        }
        for(auto it:freq){
            if(it.second==mx){
                v.push_back(it.first);
            }
        }
        return v;
    }
};