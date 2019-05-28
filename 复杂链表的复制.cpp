/*输入一个复杂链表（每个节点中有节点值，以及两个指针，一个指向下一个节点，另一个特殊指针指向任意一个节点），
返回结果为复制后复杂链表的head。（注意，输出结果中请不要返回参数中的节点引用，否则判题程序会直接返回空）*/
//3步，先复制一份并顺序连入原链表，再调整random指针，最后断开两个链表关联
/*
struct RandomListNode {
    int label;
    struct RandomListNode *next, *random;
    RandomListNode(int x) :
            label(x), next(NULL), random(NULL) {
    }
};
*/
class Solution {
public:
    RandomListNode* Clone(RandomListNode* pHead)
    {
        if(!pHead) return nullptr;
        RandomListNode *node=pHead;
        RandomListNode *dupnode=nullptr;
        while(node)
        {
            dupnode=new RandomListNode(node->label);
            dupnode->next=node->next;
            node->next=dupnode;
            node=dupnode->next;
        }
        node=pHead;
        dupnode=node->next;
        while(node)
        {
            if(node->random) dupnode->random=node->random->next;
            if(!dupnode->next) break;
            node=dupnode->next;
            dupnode=node->next;
        }
        RandomListNode* duphead=pHead->next;
        node=pHead;
        dupnode=node->next;
        while(dupnode->next)
        {
            node->next=dupnode->next;
            node=node->next;
            dupnode->next=node->next;
            dupnode=dupnode->next;
        }
        node->next=nullptr;
        return duphead;
    }
};
