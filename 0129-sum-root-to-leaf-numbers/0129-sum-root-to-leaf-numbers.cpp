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
    bool isLeaf(TreeNode* root){
        return root->left==nullptr && root->right==nullptr;
    }
    void dfs(int num,int &sum,TreeNode*root){
        if(!root) return;
        if(isLeaf(root)){
            num=num*10+root->val;
            sum+=num;
            num/=10;
            return;
        }
        num=num*10+(root->val);
        dfs(num,sum,root->left);
        dfs(num,sum,root->right);
        num/=10;
    }
    int sumNumbers(TreeNode* root) {
        if(!root) return 0;
        int sum=0;
        dfs(0,sum,root);
        return sum;
    }
};