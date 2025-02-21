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
class FindElements
{
public:
    TreeNode *root;
    FindElements(TreeNode *root2)
    {
        root = root2;
    }

    bool find(int tar)
    {
        stack<int> st;
        while (tar > 0)
        {
            int x = 0;
            if ((tar & 1) == 1)
            {
                x = 1;
            }
            tar--;
            tar >>= 1;
            st.push(x);
        }
        TreeNode *temp = root;
        while (!st.empty())
        {

            if (st.top() == 1)
            {
                if (temp->left)
                {
                    temp = temp->left;
                }
                else
                {
                    return false;
                }
            }
            else
            {
                if (temp->right)
                {
                    temp = temp->right;
                }
                else
                {
                    return false;
                }
            }
            st.pop();
        }
        return true;
    }
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */