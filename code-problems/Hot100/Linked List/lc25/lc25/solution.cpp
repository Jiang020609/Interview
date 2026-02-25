class Solution {
	pair<ListNode*, ListNode*> myReverse(ListNode* head, ListNode* tail) {
		ListNode* prev = tail->next;
		ListNode* curr = head;
		while (prev != tail) {
			ListNode* nxt = curr->next;
			curr -> next = prev;
			prev = curr;
			curr = nxt;
		}
		return { tail,head };
	}
public:
	ListNode* reverseKGroup(ListNode* head, int k) {
		ListNode* dummy = new ListNode(0);
		//dummy永远指向原始链表的头
		dummy->next = head;
		//pre总是指向待翻转小组的前一个节点
		ListNode* pre = dummy;
		while (head) {
			//tail初始化为pre，向后寻找当前待翻转小组的末尾
			ListNode* tail = pre;
			for (int i = 0; i < k; i++) {
				tail = tail->next;
				if (!tail) {
					return dummy->next;
				}
			}
			//记录下一组的起点
			ListNode* nxt = tail->next;
			pair<ListNode*, ListNode*> result = myReverse(head, tail);
			head = result.first;
			tail = result.second;
			//拼接，前一组的末尾连接到当前翻转后的head
			pre->next = head;//确保dummy->next始终指向的是链表头
			//重新连接到下一组的起点
			tail->next = nxt;
			//迭代pre，当前组的末尾，下一组的前驱
			pre = tail;
			//更新head，指向下一组的第一个
			head = tail->next;
		}
		return dummy->next;
	}
};