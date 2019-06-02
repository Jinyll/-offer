/*给一个链表，若其中包含环，请找出该链表的环的入口结点，否则，输出null。*/
//1、是否有环：两个指针，快指针位于慢指针的后一个，然后快指针每次走两步，慢指针每次走一步，若快指针为空则没有环，否则直到在环中相遇，得到相遇节点。
//2、环中节点数：从相遇节点开始，一个指针往后走并计数，直到再次到达相遇节点，得到环中节点数。
//3、找环入口：两个指针从头结点开始，快指针先走环中节点数量步，之后两个指针一起走，直到相遇，即为环入口。
/*
struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) :
        val(x), next(NULL) {
    }
};
*/
class Solution {
public:
    ListNode *getmeetnode(ListNode *pHead)
    {
        ListNode *slow=pHead;
        ListNode *fast=slow->next;
        while(fast!=nullptr)
        {
            if(slow==fast) return slow;//环中相遇节点
            fast=fast->next;
            if(fast==nullptr) return nullptr;
            fast=fast->next;
            slow=slow->next;
        }
        return nullptr;
    }
    ListNode* EntryNodeOfLoop(ListNode* pHead)
    {
        if(pHead==nullptr) return nullptr;
        ListNode *meetnode=getmeetnode(pHead);//1、初始快指针是慢指针的next，然后每次快走两步，慢走一步，期间判断快慢是否相遇，相遇则有环，否则快为空则无环
        if(meetnode==nullptr) return nullptr;
        //2、求环中节点数量n，从相遇节点开始，一个指针向后并计数，直到再次到达相遇节点
        int nums=1;
        ListNode *tmp=meetnode;
        while(tmp->next!=meetnode)
        {
            ++nums;
            tmp=tmp->next;
        }
        //3、从头结点开始，一个指针先走n步，然后两个指针同步走，直到相遇
        ListNode *ahead=pHead;
        ListNode *behide=pHead;
        for(int i=0;i<nums;i++) ahead=ahead->next;
        while(ahead!=behide)
        {
            ahead=ahead->next;
            behide=behide->next;
        }
        return ahead;
    }
};
