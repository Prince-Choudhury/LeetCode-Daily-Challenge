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
    unordered_map<int, int> indexMap; // Use unordered_map for faster lookup
    int postIndex; // Remove initialization

    TreeNode* buildTreeHelper(vector<int>& inorder, vector<int>& postorder, int inStart, int inEnd) {
        // Base Case
        if (postIndex < 0 || inStart > inEnd) {
            return nullptr;
        }

        // Ek case main solve krta hu
        int element = postorder[postIndex];
        postIndex--;

        TreeNode* root = new TreeNode(element);

        // element search krna padega inorder me
        int position = indexMap[element];

        // Baaki Recursion Sambhal lega
        root->right = buildTreeHelper(inorder, postorder, position + 1, inEnd);
        root->left = buildTreeHelper(inorder, postorder, inStart, position - 1);

        return root;
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int size = inorder.size();
        postIndex = size - 1; // Initialize postIndex here

        // Create an index map for fast lookup of inorder elements
        for (int i = 0; i < size; ++i) {
            indexMap[inorder[i]] = i;
        }

        return buildTreeHelper(inorder, postorder, 0, size - 1);
    }
};

