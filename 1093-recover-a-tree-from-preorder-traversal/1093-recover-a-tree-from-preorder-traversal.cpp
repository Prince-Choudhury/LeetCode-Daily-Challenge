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
    int n=0;
    TreeNode* construct(string& s,int depth,int& i){
        if(i>=n){
            return NULL;
        }
        int d=0;
        
        while(i<n and s[i]=='-'){
            d++;
            i++;
        }
        
        if(d!=depth){
            i-=d;
            return NULL;
        }
        string temp="";
        while(i<n and s[i]!='-'){
            temp+=s[i];
            i++;
        }
        int value=stoi(temp);
        TreeNode* n= new TreeNode(value);
        n->left=construct(s,d+1,i);
        n->right=construct(s,d+1,i);
        cout << n->val << " ";
        return n;
    }   
    TreeNode* recoverFromPreorder(string s) {
        n=s.length();
        int i=0;
        TreeNode* root=construct(s,0,i);
        return root;
    }
};