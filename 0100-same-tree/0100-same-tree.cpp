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
    bool isSameTree(TreeNode* p, TreeNode* q){
        if(p == NULL && q == NULL){
            return true;
        }

        if(p!=NULL && q!=NULL){
            return (p->val == q->val)
            && isSameTree(p->left, q->left)
            && isSameTree(p->right, q->right);
        }

        // if p is NULL or q is NULL 
        return false;
    }
};

 /*
class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(p == NULL && q == NULL){
            return true;
        }

        else if(p == NULL || q == NULL){
            return false;
        }

        else if (p -> val != q -> val){
            return false;
        }

        else{
            bool lpart = isSameTree(p->left, q->left);
            bool rpart = isSameTree(p->right, q->right);

            return (lpart && rpart);

        } 
    }
};
*/