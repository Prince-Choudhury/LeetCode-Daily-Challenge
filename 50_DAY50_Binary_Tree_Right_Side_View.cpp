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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        if(root ==  NULL)
            return ans;

        queue<pair<int,TreeNode*>> q;

        map<int,int> mp;

        q.push({0,root});

        while(!q.empty()) {
            auto it = q.front();
            q.pop();

            int hLevel = it.first;
            TreeNode* curr = it.second;

            mp[hLevel] = curr->val;

            if(curr->left) {
                q.push({hLevel+1,curr->left});
            }

            if(curr->right) {
                q.push({hLevel+1,curr->right});
            }
        }


        for(auto it : mp) {
            ans.push_back(it.second);
        }

        return ans;
    }
};