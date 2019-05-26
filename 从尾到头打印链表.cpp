/*输入一个链表，按链表值从尾到头的顺序返回一个ArrayList。*/
//从尾到头，用栈
class Solution {
public:
    vector<int> printListFromTailToHead(ListNode* head) {
        vector<int> res;
        if(head==nullptr) return res; 
        stack<int> s;
        ListNode* node=head;
        while(node!=nullptr)
        {
            s.push(node->val);
            node=node->next;
        }
        while(!s.empty())
        {
            res.push_back(s.top());
            s.pop();
        }
        return res;
    }
};
