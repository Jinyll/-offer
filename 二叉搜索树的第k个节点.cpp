/*给定一棵二叉搜索树，请找出其中的第k小的结点。例如， （5，3，7，2，4，6，8）    中，按结点数值大小顺序第三小结点的值为4。*/
//中序遍历，栈，当前不为空则入栈指向左，为空则出栈指向右，当前节点数加1，如果当前节点数是第k个则返回当前节点，while结束后则表示没有k个节点，返回空。
/*
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
    }
};
*/
class Solution {
public:
    TreeNode* KthNode(TreeNode* pRoot, int k)
    {
        if(!pRoot || k<=0) return nullptr;
        stack<TreeNode *> s;
        TreeNode *curr=pRoot;
        int index=0;
        while(curr || !s.empty())
        {
            if(curr)
            {
                s.push(curr);
                curr=curr->left;
            }
            else
            {
                TreeNode *topnode=s.top();
                s.pop();
                curr=topnode->right;
                ++index;
                if(index==k)
                {
                    return topnode;
                }
            }
        }
        return nullptr;
    }

    
};
