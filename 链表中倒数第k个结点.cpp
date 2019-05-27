/*输入一个链表，输出该链表中倒数第k个结点。*/
//第一个指针先走k-1步，然后指向头的第二个指针一起走，直到第一个指针走到最后一个节点
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
    ListNode* FindKthToTail(ListNode* pListHead, unsigned int k) {
        if(pListHead==nullptr || k<=0) return nullptr;
        ListNode *node=pListHead;
        for(int i=0;i<k-1;i++)
        {
            if(node->next!=nullptr) node=node->next;
            else
            {
                if(k==1) return node;
                else return nullptr;
            }
        }
        ListNode *res=pListHead;
        while(node->next!=nullptr)
        {
            node=node->next;
            res=res->next;
        }
        return res;
    }
};
