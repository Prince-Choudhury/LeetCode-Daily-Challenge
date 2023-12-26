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
    TreeNode* searchBST(TreeNode* root, int val) {
        // Base cases
        if (root == nullptr || root->val == val) {
            return root;
        }

        // Recursive search in the left or right subtree based on the target value
        if (val < root->val) {
            return searchBST(root->left, val);
        } 
        else {
            return searchBST(root->right, val);
        }
    }
};
