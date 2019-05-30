/*输入两个链表，找出它们的第一个公共结点。*/
//先统计两个链表长度，然后长的那个链表指针先向前走长度差值步，最后两个链表指针同步走，当节点相同时即为第一个公共节点，走到末尾都不相同，则表明没有相同节点
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
    int getlength(ListNode* head)
    {
        ListNode* tmp=head;
        int length=0;
        while(tmp)
        {
            ++length;
            tmp=tmp->next;
        }
        return length;
    }
    ListNode* FindFirstCommonNode( ListNode* pHead1, ListNode* pHead2) {
        if(!pHead1 || !pHead2) return nullptr;
        int length1=getlength(pHead1);
        int length2=getlength(pHead2);
        ListNode* node1=pHead1;
        ListNode* node2=pHead2;
        if(length1>length2)
        {
            int move=length1-length2;
            while(move--) node1=node1->next;
        }
        else if(length1<length2)
        {
            int move=length2-length1;
            while(move--) node2=node2->next;
        }
        while(node1 && node2 && node1!=node2)
        {
            node1=node1->next;
            node2=node2->next;
        }
        return node1;
    }
};
