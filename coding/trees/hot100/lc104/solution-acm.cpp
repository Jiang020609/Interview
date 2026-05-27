#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x) : val(x),left(nullptr),right(nullptr){}
};
int getMaxDepth(TreeNode* root) {
	if (root == nullptr) return 0;
	return max(getMaxDepth(root->left), getMaxDepth(root->right)) + 1;
}
int main() {
	cout << getMaxDepth(root) << endl;
	return 0;
}