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
private:
    // Function to search for a number in the postorder array
    int search(vector<int>& postorder,int start,int end,int num)
    {
        for(int i=start;i<=end;i++)
        {
            if(postorder[i] == num)
            {
                return i;
            }
        }

        return -1;
    }
   
    int preindex = 0;
    TreeNode* solve(vector<int>&preorder,vector<int>&postorder,int start,int end)
    {
        if(start > end || preindex >= preorder.size())
            return nullptr;

        int num = preorder[preindex];
        preindex++;

        TreeNode*root = new TreeNode(num);

        if(preindex >= preorder.size() || start == end)
            return root;

        int postindex = search(postorder,start,end,preorder[preindex]);
        
        root->left = solve(preorder,postorder,start,postindex);

        root->right = solve(preorder,postorder,postindex + 1,end - 1);

        return root;
    }
public:
    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
        
        return solve(preorder,postorder,0,preorder.size()-1);
    }
};