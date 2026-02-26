#include <iostream>
#include<vector>
#include<queue>
#include <string>
#include <sstream>
#include <algorithm>

using namespace std;

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode():val(0),left(nullptr),right(nullptr){}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr){}
	TreeNode(int x,TreeNode* left,TreeNode* right):val(x),left(left),right(right){}
};

TreeNode* invertTree(TreeNode* root) {
	if (root == nullptr) return nullptr;
	TreeNode* temp = root->left;
	root->left = root->right;
	root->right = temp;
	invertTree(root->left);
	invertTree(root->right);
	return root;
}

TreeNode* buildTree(string s) {
	vector<string> nodes;
	string temp = "";
	for (int i = 0; i < s.length(); i++) {
		if (s[i] == '[' || s[i] == ']' || s[i] == ',' || s[i] == ' ') {
			if (!temp.empty()) {
				nodes.push_back(temp);
				temp = "";
			}
			continue;
		}
		temp += s[i];
	}
	if (!temp.empty()) nodes.push_back(temp);
	if (nodes.empty() || nodes[0] == "null") return nullptr;
	TreeNode* root = new TreeNode(stoi(nodes[0]));
	queue<TreeNode*> q;
	q.push(root);

	int idx = 1;
	while (!q.empty() && idx < nodes.size()) {
		TreeNode* curr = q.front();
		q.pop();

		// ×óº¢×Ó
		if (idx < nodes.size() && nodes[idx] != "null") {
			curr->left = new TreeNode(stoi(nodes[idx]));
			q.push(curr->left);
		}
		idx++;

		// ÓÒº¢×Ó
		if (idx < nodes.size() && nodes[idx] != "null") {
			curr->right = new TreeNode(stoi(nodes[idx]));
			q.push(curr->right);
		}
		idx++;
	}
	return root;
}

TreeNode* invertTree(TreeNode* root) {
	if (!root) return nullptr;
	swap(root->left, root->right);
	invertTree(root->left);
	invertTree(root->right);
	return root;
}

void printTree(TreeNode* root) {
	if (!root) {
		cout << "[]" << endl;
		return;
	}
	vector<string> res;
	queue<TreeNode*> q;
	q.push(root);

	while (!q.empty()) {
		TreeNode* curr = q.front();
		q.pop();
		if (curr) {
			res.push_back(to_string(curr->val));
			q.push(curr->left);
			q.push(curr->right);
		}
		else {
			res.push_back("null");
		}
	}

	// È¥µôÄ©Î²¶àÓàµÄ null£¬·ûºÏ LeetCode Ï°¹ß
	while (!res.empty() && res.back() == "null") res.pop_back();

	cout << "[";
	for (int i = 0; i < res.size(); ++i) {
		cout << res[i] << (i == res.size() - 1 ? "" : ",");
	}
	cout << "]" << endl;
}

int main() {
	string line;
	while (getline(cin, line)) {
		TreeNode* root = buildTreeFromRawString(line);
		root = invertTree(root);
		printTree(root);
	}
	return 0;
}