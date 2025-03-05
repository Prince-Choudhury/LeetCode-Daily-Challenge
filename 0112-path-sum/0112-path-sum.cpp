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

    bool solve(TreeNode* root, int target, int sum){
        if(root == NULL){
            return false;
        }

        sum = sum + root->val;
        

        if(root->left == NULL && root->right == NULL){
            if(sum == target){
                return true;
            }
        }

        bool lans = solve(root->left, target, sum);
        bool rans = solve(root->right, target, sum);

        return lans || rans;
    }
    bool hasPathSum(TreeNode* root, int target) {
        return solve(root, target, 0);
    }
};