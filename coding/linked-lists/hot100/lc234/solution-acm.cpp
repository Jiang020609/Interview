#include <iostream>
#include <vector>

using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
public:
	bool isPalindrome(ListNode* head) {
		ListNode* slow = head;
		ListNode* fast = head;
		while (fast->next && fast->next->next) {
			slow = slow->next;
			fast = fast->next->next;
		}
		ListNode* prev = nullptr;
		ListNode* cur = slow->next;
		while (cur) {
			ListNode* nxt = cur->next;
			cur->next = prev;
			prev = cur;
			cur = nxt;
		}
		ListNode* p1 = head;
		ListNode* p2 = prev;
		while (p2) {
			if (p1->val != p2->val) return false;
			p1 = p1->next;
			p2 = p2->next;
		}
		return true;


	}
};

ListNode* buildList(const vector<int>& nums) {
	if (nums.empty()) return nullptr;
	ListNode* head = new ListNode(nums[0]);
	ListNode* curr = head;
	for (size_t i = 1; i < nums.size(); ++i) {
		curr->next = new ListNode(nums[i]);
		curr = curr->next;
	}
	return head;
}

void freeList(ListNode* head) {
	while (head) {
		ListNode* temp = head;
		head = head->next;
		delete temp;
	}
}

int main() {
	int val;
	vector<int> nums;

	while (cin >> val) {
		nums.push_back(val);
		if (cin.get() == '\n') { 
			ListNode* head = buildList(nums);
			Solution sol;
			cout << (sol.isPalindrome(head) ? "true" : "false") << endl;

			freeList(head); 
			nums.clear();  
		}
	}

	
	if (!nums.empty()) {
		ListNode* head = buildList(nums);
		Solution sol;
		cout << (sol.isPalindrome(head) ? "true" : "false") << endl;
		freeList(head);
	}

	return 0;
}

//也可以如下处理非solution部分

int main() {
	// 假设输入格式为：每组数据先输入一个整数 n 表示链表长度，再输入 n 个整数
	// 如果题目是直接读取所有数字直到结束，可以去掉 n 的逻辑
	int n;
	while (cin >> n) {
		if (n == 0) {
			cout << "true" << endl;
			continue;
		}

		ListNode* dummy = new ListNode(0);
		ListNode* tail = dummy;
		for (int i = 0; i < n; ++i) {
			int val;
			cin >> val;
			tail->next = new ListNode(val);
			tail = tail->next;
		}

		ListNode* head = dummy->next;
		delete dummy; 
		Solution sol;
		if (sol.isPalindrome(head)) {
			cout << "true" << endl;
		}
		else {
			cout << "false" << endl;
		}

		while (head) {
			ListNode* temp = head;
			head = head->next;
			delete temp;
		}
	}

	return 0;
}