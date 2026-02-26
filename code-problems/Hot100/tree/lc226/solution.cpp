class Solution {
public:
	TreeNode* invertTree(treeNode* root) {
		if (root == nullptr) {
			return nullptr;
		}
		TreeNode* temp = root->left;
		root->left = root->right;
		root->right = temp;
		invertTree(root->left);
		invertTree(root->right);
	}
};