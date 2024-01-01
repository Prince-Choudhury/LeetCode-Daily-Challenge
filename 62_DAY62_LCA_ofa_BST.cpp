/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        //base case
        if(root == NULL){
            return NULL;
        }

        //Case 1 : p and q both comes in the left subtree of root node - Recursion
        if(p->val<root->val && q->val<root->val){
            TreeNode* leftAns = lowestCommonAncestor(root->left, p, q);
            return leftAns;
        }

        //Case 2 : p and q both comes in the right subtree of root node - Recursion
        if(p->val>root->val && q->val>root->val){
            TreeNode* rightAns = lowestCommonAncestor(root->right, p, q);
            return rightAns;
        }

        //Case 3 : p is in the left subtree of root node && q is in the right subtree of root node
        if(p->val<root->val && q->val>root->val){
            return root;
        }

        //Case 4 : q is in the left subtree of root node && p is in the right subtree of root node
        if(p->val>root->val && q->val<root->val){
            return root;
        }

        return root;
    }
};