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

    vector<int> result;
    vector<int> postorderTraversal(TreeNode* root) {
        // base case
        if (root == nullptr) {
            return result;
        }

        //LRN
        // L - Left part
        postorderTraversal(root->left);

        // R - Right part
        postorderTraversal(root->right);

        // N - Current Node
        result.push_back(root->val);

        return result;
    }
};