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
    TreeNode* maxValue(TreeNode* root) {
	if(root == NULL) {
		return NULL;
	}

	//if tree has nodes > 0 count
	TreeNode* temp = root;
	while(temp->right != NULL) {
		temp = temp->right;
	}
	return temp;
    }

    TreeNode* deleteNode(TreeNode* root, int key) {
	///target ko dhundo
	//target ko delete karo

	if(root == NULL) {
		return NULL;
	}

	if(root->val == key) {
		//ab delete karenge
		//4 cases

		
		if(root->left == NULL && root->right == NULL) {
			//1 case -> leaf node
			delete root;
			return NULL;
		}
		else if(root->left != NULL && root->right == NULL) {
			//2 case -> left non null and right null
			TreeNode* childSubtree = root->left;
			delete root;
			return childSubtree;
		}
		else if(root->left == NULL && root->right != NULL) {
			///3 case -> left me NULL and right NON NULL
			TreeNode* childSubtree = root->right;
			delete root;
			return childSubtree;
		}
		//4 case -> left NON NULL && right NON NULL
		else {
			//a -> left subtree ki max value lao
			TreeNode* maxi = maxValue(root->left);
			//replacement
			root->val = maxi->val;

			//delete actual maxi wali node
			root->left = deleteNode(root->left, maxi->val);
			return root;
		}
	}
	else if(root->val > key) {
		//left me chalo
		root->left =  deleteNode(root->left,  key);
	}
	else {
		//right me jao
		root->right =  deleteNode(root->right, key);
	}
	
	return root;
    }

};