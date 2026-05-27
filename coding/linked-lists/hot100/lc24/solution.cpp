class Solution {
public:
	ListNode* swapPairs(ListNode* head) {
		ListNode* dummy = new ListNode(0);
		dummy->next = head;
		ListNode* curr = dummy;
		while (curr->next != nullptr && curr->next->next != nullptr) {
			ListNode* node1 = curr->next;
			ListNode* node2 = curr->next->next;
			curr->next = node2;
			node1->next = node2->next;
			node2->next = node1;
			curr = node1;
		}
		ListNode* result = dummy->next;
		delete dummy;
		return result;
	}
};