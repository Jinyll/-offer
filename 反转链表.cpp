/*输入一个链表，反转链表后，输出新链表的表头。*/
//pre之前是已经反转好的，node是当前待反转
/*
struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
			val(x), next(NULL) {
	}
};*/
class Solution {
public:
    ListNode* ReverseList(ListNode* pHead) {
        if(pHead==nullptr) return nullptr;
        ListNode* node=pHead;
        ListNode* pre=nullptr;
        while(node->next!=nullptr)
        {
            ListNode* next=node->next;
            node->next=pre;
            pre=node;
            node=next;
        }
        node->next=pre;
        return node;
    }
};
