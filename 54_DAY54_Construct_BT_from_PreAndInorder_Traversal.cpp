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
    map<int, int> valueToIndexMap; 
    int preIndex = 0; // Initialize preIndex

    void createMapping(int inorder[], int size) {
        for (int i = 0; i < size; i++) {
            int element = inorder[i];
            int index = i;
            valueToIndexMap[element] = index;
        }
    }

    TreeNode* TreeFromPreAndInorderTraversal(vector<int>& preorder, vector<int>& inorder, int inOrderStart, int inOrderEnd, int size) {
        
        // Base Case
        if (preIndex >= size || inOrderStart > inOrderEnd) {
            return NULL;
        }

        // Ek case main solve krta hu
        int element = preorder[preIndex];
        preIndex++;

        TreeNode* root = new TreeNode(element);

        // element search krna padega inorder me
        int position = valueToIndexMap[element];

        // Baaki Recursion Sambhal lega
        root->left = TreeFromPreAndInorderTraversal(preorder, inorder, inOrderStart, position - 1, size);

        root->right = TreeFromPreAndInorderTraversal(preorder, inorder, position + 1, inOrderEnd, size);

        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int size = inorder.size();
        createMapping(inorder.data(), size); // Convert vector to array
        return TreeFromPreAndInorderTraversal(preorder, inorder, 0, size - 1, size);
    }
};
