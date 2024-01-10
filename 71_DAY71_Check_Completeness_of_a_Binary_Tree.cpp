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
    bool isCompleteTree(TreeNode* root) {
        if (root == nullptr) {
            return true;
        }

        queue<TreeNode*> q;
        q.push(root);

        bool hasNull = false;  // Flag to check for encountered null nodes

        while (!q.empty()) {
            TreeNode* current = q.front();
            q.pop();

            if (current == nullptr) {
                hasNull = true;
            } else {
                // If we have encountered null nodes before, and we encounter a non-null node,
                // the tree is not complete
                if (hasNull) {
                    return false;
                }

                // Enqueue left and right children
                q.push(current->left);
                q.push(current->right);
            }
        }

        // If the queue is empty, it is a complete binary tree
        return true;
    }
};

