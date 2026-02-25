class Solution {
public:
	ListNode* sortList(ListNode* head) {
		if (head == nullptr || head->next == nullptr) {
			return head;
		}
		//找链表中点用快慢指针法
		ListNode* prev = nullptr;
		ListNode* slow = head;
		ListNode* fast = head;
		while (fast != nullptr && fast->next != nullptr) {
			prev = slow;
			slow = slow->next;
			fast = fast->next->next;
		}
		//prev指向slow的前一个
		prev->next = nullptr;
		ListNode* left = sortList(head);
		ListNode* right = sortList(slow);
		return merge(left, right);
	}
};