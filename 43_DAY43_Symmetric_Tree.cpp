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
    bool isSymmetric(TreeNode* root) {
        if (root == nullptr) {
            return true;  // An empty tree is symmetric.
        }

        return isMirror(root->left, root->right);
    }

    bool isMirror(TreeNode* left, TreeNode* right) {
        // If both nodes are null, they are symmetric.
        if (left == nullptr && right == nullptr) {
            return true;
        }

        // If one of the nodes is null (and the other is not), they are not symmetric.
        if (left == nullptr || right == nullptr) {
            return false;
        }

        // Nodes are symmetric if their values are equal, and the left subtree is a mirror of the right subtree
        return (left->val == right->val) &&
               isMirror(left->left, right->right) &&
               isMirror(left->right, right->left);
    }
};
