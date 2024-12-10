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

    int levelOrder(TreeNode* root){
        int count = 0;
        queue<TreeNode*>q;
        q.push(root);
        q.push(NULL);
        count++;

        while(q.size()>1){
            TreeNode* front = q.front();
            q.pop();

            if(front == NULL){
                count++;
                q.push(NULL);
            }

            else{
                if(front->left!= NULL){
                    q.push(front->left);
                }

                if(front->right!= NULL){
                    q.push(front->right);
                }
            }
        }

        return count;
    }

    int maxDepth(TreeNode* root) {

        if(root == NULL){
            return 0;
        }
        
        int height = levelOrder(root);
        return height;
    }
};