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
    TreeNode* build(int &i, int min, int maxm, vector<int>& preorder){
        if(i >= preorder.size()){
            return NULL;
        }
        
        TreeNode* root = NULL;
        if(preorder[i] > min && preorder[i] < maxm){
            root = new TreeNode(preorder[i++]);
            root->left = build(i, min, root->val, preorder);
            root->right = build(i, root->val, maxm, preorder);
        }

        return root;
    }

    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int min = INT_MIN;
        int maxm = INT_MAX;
        int i = 0;
        return build(i, min, maxm, preorder);
    }
};

