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
    TreeNode* MoveRightEnd(TreeNode* root){
        if(!root->right) return root;
        return MoveRightEnd(root->right);
    }
    TreeNode* helper(TreeNode*root){
        if(!root->left) return root->right;
        if(!root->right) return root->left;
        TreeNode*rightChild=root->right;
        TreeNode*rightEnd=MoveRightEnd(root->left);
        rightEnd->right=rightChild;
        return root->left;
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(!root) return nullptr;
        if(root->val==key) return helper(root);
        TreeNode* curr=root;
        while(curr){
            if(curr->val<key){
                if(curr->right && curr->right->val==key){
                    curr->right=helper(curr->right);
                    break;
                }
                curr=curr->right;
            }else{
                if(curr->left && curr->left->val==key){
                    curr->left=helper(curr->left);
                    break;
                }
                curr=curr->left;
            }
        }
        return root;
    }
};