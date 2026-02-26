class Solution {
public:
	ListNode* reverseList(ListNode* head){
		ListNode* prev = nullptr;
		ListNode* curr = head;
		while (curr != nullptr) {
			ListNode& nxt = curr->next;
			curr->next = prev;
			prev = curr;
			curr = nxt;
		}
		return prev;

		}
};
//µü´ú

class Solution {
public:
	ListNode* reverseList(ListNode* head) {
		if (head == nullptr || head->next == nullptr) {
			return head;
		}
		ListNode* newHead = reverseList(head->next);
		head->next->next = head;
		head->next = nullptr;
		return newHead;

	}
};
//µÝ¹é