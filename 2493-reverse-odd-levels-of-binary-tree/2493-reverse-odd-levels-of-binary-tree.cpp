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

    void reverse(TreeNode* left, TreeNode* right, int level){
        if(left==NULL) return;

        if(level&1) swap(left->val,right->val);

        reverse(left->left, right->right, level+1);
        reverse(left->right, right->left, level+1);
    }

    TreeNode* reverseOddLevels(TreeNode* root) {
        reverse(root->left,root->right,1);
        return root;
    }
};