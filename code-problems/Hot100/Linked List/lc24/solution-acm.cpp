#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

struct ListNode {
	int val;
	ListNode* next;
	ListNode() :val(0),next(nullptr){}
	ListNode(int x) :val(x), next(nullptr) {}
	ListNode(int x,ListNode* next):val(x),next(next){}
};
class Solution {
public:
	ListNode* swapPairs(ListNode* head) {
		if (!head || !head->next) return head;
		ListNode* dummy = new ListNode(0);
		dummy->next = head;
		ListNode* curr = dummy;
		while (curr->next != nullptr && curr->next->next != nullptr) {
			ListNode* node1 = curr->next;
			ListNode* node2 = curr->next->next;
			node1->next = node2->next;
			node2->next = node1;
			curr->next = node2;
			curr = node1;
		}
		ListNode* ans = dummy->next;
		delete dummy;
		return ans;
	}
};
ListNode* creatList(const vector<int>& nums) {
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
	ListNode* curr = head;
	while (curr) {
		cout << curr->val << (curr->next ? " " : "");
		curr = curr->next;
	}
	cout << endl;
}
int main() {
	string line;
	while (getline(cin, line)) {
		if (line.empty()) break;
		stringstream ss(line);
		int num;
		vector<int> nums;
		while (ss >> num) {
			nums.push_back(num);
		}
		ListNode* head = createList(nums);
		Solution sol;
		head = sol.swapPairs(head);
		printList(head);

	}
	return 0;
}