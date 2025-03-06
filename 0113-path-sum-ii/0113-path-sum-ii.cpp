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
    void solve(TreeNode* root, int target, int sum, vector<int>&output, vector<vector<int>>&ans){
        if(root == NULL){
            return;
        }

        sum = sum + root->val;
        output.push_back(root->val);

        if(root->left == NULL && root->right == NULL){
            if(sum == target){
                ans.push_back(output);
            }
        }

        solve(root->left, target, sum, output, ans);
        solve(root->right, target, sum, output, ans);
        output.pop_back();
    }
    vector<vector<int>> pathSum(TreeNode* root, int target) {
        vector<vector<int>>ans;
        vector<int>output;
        solve(root, target, 0, output, ans);

        return ans;
    }
};