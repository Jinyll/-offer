/*输入一个链表，反转链表后，输出新链表的表头。*/
//curr之前是已经反转好的，curr最后指向结束节点，pre最后指向最后一个节点
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
        if(!pHead) return nullptr;
        ListNode *pre=nullptr;
        ListNode *curr=pHead;
        while(curr)
        {
            ListNode *next=curr->next;
            curr->next=pre;
            pre=curr;
            curr=next;
        }
        return pre;
    }
};
