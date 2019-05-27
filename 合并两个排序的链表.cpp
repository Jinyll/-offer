/*输入两个单调递增的链表，输出两个链表合成后的链表，当然我们需要合成后的链表满足单调不减规则。*/
//递归
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
    ListNode* Merge(ListNode* pHead1, ListNode* pHead2)
    {
        if(pHead1==nullptr) return pHead2;
        else if(pHead2==nullptr) return pHead1;
        ListNode *node=nullptr;
        if(pHead1->val < pHead2->val)
        {
            node=pHead1;
            node->next=Merge(pHead1->next,pHead2);
        }
        else
        {
            node=pHead2;
            node->next=Merge(pHead1,pHead2->next);
        }
        return node;
    }
    
    /*ListNode* Merge(ListNode* pHead1, ListNode* pHead2)
    {
        if(pHead1==nullptr && pHead2==nullptr) return nullptr;
        if(pHead1==nullptr && pHead2!=nullptr) return pHead2;
        if(pHead1!=nullptr && pHead2==nullptr) return pHead1;
        ListNode *n1=pHead1;
        ListNode *n2=pHead2;
        ListNode *newList=new ListNode(0);
        ListNode *newCurr=new ListNode(0);
        newList->next = newCurr;
        while(n1 && n2)
        {
            if(n1->val > n2->val)
            {
                ListNode *newNode=new ListNode(n2->val);
                newCurr->next=newNode;
                newCurr=newCurr->next;
                n2=n2->next;
            }
            else
            {
                ListNode *newNode=new ListNode(n1->val);
                newCurr->next=newNode;
                newCurr=newCurr->next;
                n1=n1->next;
            }
        }
        if(n1==nullptr && n2!=nullptr)
        {
            newCurr->next=n2;
        }
        if(n1!=nullptr && n2==nullptr)
        {
            newCurr->next=n1;
        }
        return newList->next->next;
    }*/
};
