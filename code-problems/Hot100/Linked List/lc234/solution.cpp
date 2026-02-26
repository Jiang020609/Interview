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