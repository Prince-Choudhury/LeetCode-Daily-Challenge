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
    unordered_map<string,int>mp;
    vector<TreeNode *>res;

    string solve(TreeNode *root){
        if(!root) return "";

        string left = solve(root->left);
        string right = solve(root->right);

        string curr = to_string(root->val) + " " + left + " " + right;

        if(mp[curr] == 1){
            res.push_back(root);
        }
        mp[curr]++;
        return curr;
    }
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        string dummy = solve(root);
        return res;
    }
};