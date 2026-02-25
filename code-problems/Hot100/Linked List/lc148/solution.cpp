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
private:
	ListNode* merge(ListNode* l1, ListNode* l2) {
		ListNode dummy(0);
		ListNode* curr = &dummy;
		while (l1 != nullptr && l2 != nullptr) {
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
		if (l1 != nullptr) curr->next = l1;
		if (l2 != nullptr) curr->next = l2;
		return dummy.next;
	}
};