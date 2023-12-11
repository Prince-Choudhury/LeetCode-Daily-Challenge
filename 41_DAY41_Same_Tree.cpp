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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if (p == nullptr && q == nullptr){
            return true;
        }
        else if (p == nullptr || q == nullptr){
            return false;
        }
        else if (p -> val != q -> val){
            return false;
        }
        
        else {
            bool res_right = isSameTree(p -> right, q -> right);

            bool res_left = isSameTree(p -> left, q -> left);
            
            return (res_right && res_left);
        }
    }
};