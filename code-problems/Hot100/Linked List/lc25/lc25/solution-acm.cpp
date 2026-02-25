#include <iostream>
#include <vector>
#include <sstream>
using namespace std;
struct ListNode {
	int val;
	ListNode* next;
	ListNode() : val(0),next(nullptr){}
	ListNode(int x):val(x),next(nullptr){}
	ListNode(int x, ListNode* next) :val(x), next(next) {}

};
class Solution {
	pair<ListNode*,ListNode*> myReverse(ListNode* head, ListNode* tail) {
		ListNode* prev = tail->next;
		ListNode* curr = head;
		while (prev != tail) {
			ListNode* nxt = curr->next;//提前追踪下一个要处理的结点
			curr->next = prev;//处理当前节点
			prev = curr;//下一个节点的next指向当前节点
			curr = nxt;//递归处理下一个节点
		}
		return{ tail,head };
	}
public:
	ListNode* reverseKGroup(ListNode* head, int k) {
		ListNode* dummy = new ListNode(0);
		dummy->next = head;
		ListNode* pre = dummy;
		while (head) {
			ListNode* tail = pre;
			for (int i = 0; i < k; i++) {
				tail = tail->next;
				if (!tail) {
					return dummy->next;
				}
			}
			ListNode* nxt = tail->next;
			pair<ListNode*, ListNode*> result = myReverse(head, tail);
			head = result.first;
			tail = result.second;
			pre->next = head;
			tail->next = nxt;
			pre = tail;
			head = tail->next;
		}
		return dummy->next;
	}
};
//ListNode* buildList(const vector<int>& nums) {
	//if (nums.empty()) return nullptr;
	//ListNode* head = new ListNode(nums[0]);
	//ListNode* cur = head;
	//for (size_t i = 1; i < nums.size(); i++) {
		//cur->next = new ListNode(nums[i]);
		//cur = cur->next;
	//}
	//return head;
//}
ListNode* buildListFromInput() {
	string line;
	if (!getline(cin, line) || line.empty()) return nullptr;
	stringstream ss(line);
	int val;
	ListNode* dummy = new ListNode(0);
	ListNode* cur = dummy;
	while (ss >> val) {
		cur->next = new ListNode(val);
		cur = cur->next;
	}
	return dummy->next;
}
void printList(ListNode* head) {
	while (head) {
		cout << head->val << (head->next ? " " : "");
		head = head->next;
	}
	cout << endl;
}
int main() {
	ListNode* head = buildListFromInput();
	int k;
	cin >> k;
	Solution sol;
	ListNode* result  = sol.reverseKGroup(head, k);
	printList(result);
	return 0;
	
}