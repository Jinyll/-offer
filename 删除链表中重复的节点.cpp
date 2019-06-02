/*在一个排序的链表中，存在重复的结点，请删除该链表中重复的结点，重复的结点不保留，返回链表头指针。 例如，链表1->2->3->3->4->4->5 处理后为 1->2->5*/
//多个指针的处理，注意设置新的链表头节点
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
    ListNode* deleteDuplication(ListNode* pHead)
    {
        if(!pHead) return nullptr;
        ListNode *pre=nullptr;
        ListNode *curr=pHead;
        while(curr)
        {
            bool del=false;
            ListNode *next=curr->next;
            if(next && curr->val==next->val) del=true;
            if(del)//从curr开始删除
            {
                int delval=curr->val;
                ListNode *tobedel=curr;
                while(tobedel && tobedel->val==delval)//删除重复，让curr指向后面的不重复节点
                {
                    curr=tobedel->next;
                    delete tobedel;
                    tobedel=curr;
                }
                if(pre==nullptr) pHead=curr;//说明从头结点开始删除
                else pre->next=curr;//否则新的头结点已经就位，此处只需保证不断链
            }
            else
            {//没有要删除的，设置前指针和当前指针后移一位
                pre=curr;
                curr=next;
            }
        }
        return pHead;
    }
};
