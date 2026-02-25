#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>
using namespace std;
struct ListNode {
	int val;
	ListNode* next;
	ListNode() :val(0), next(nullptr) {}
	ListNode(int x) : val(x),next(nullptr){}
	ListNode(int x, ListNode* next) : val(x), next(next) {}
};
class Solution {
public:
	ListNode* sortList(ListNode* head) {
		if (!head || !head->next)  return head;
		ListNode* prev = nullptr;
		ListNode* slow = head;
		ListNode* fast = head;
		while (fast && fast->next) {
			prev = slow;
			slow = slow->next;
			fast = fast->next->next;
		}
		prev->next = nullptr;
		return merge(sortList(head), sortList(slow));
	}
private:
	ListNode* merge(ListNode* l1, ListNode* l2) {
		ListNode dummy(0);
		ListNode* curr = &dummy;
		while (l1 && l2) {
			if (l1->val < l2->val) {
				curr->next = l1;
				l1 = l1->next;
			}
			else {
				curr->next = l2;
				l2 = l2->next;
			}
			curr = curr->next;
		}
		curr->next = l1 ? l1 : l2;
		return dummy.next;
	}
};
ListNode* buildList(const vector<int>& nums) {
	if (nums.empty()) return nullptr;
	ListNode* head = new ListNode(nums[0]);
	ListNode* curr = head;
	for (size_t i = 1; i < nums.size(); i++) {
		curr->next = new ListNode(nums[i]);
		curr = curr->next;
	}
	return head;
}
void printList(ListNode* head) {
	while (head) {
		cout << head->val << (head->next ? " " : "");
		head = head->next;
	}
	cout << endl;
}
int main() {
	int num;
	vector<int> nums;
	string line;
	if (getline(cin, line)) {
		stringstream ss(line);
		while (ss >> num) {
			nums.push_back(num);
		}
	}
	ListNode* head = buildList(nums);
	Solution sol;
	ListNode* sortedHead = sol.sortList(head);
	printList(sortedHead);
	return 0;
}