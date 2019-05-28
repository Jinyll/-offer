/*输入一棵二叉搜索树，将该二叉搜索树转换成一个排序的双向链表。要求不能创建任何新的结点，只能调整树中结点指针的指向。*/
//二叉搜索树中序遍历有序，当前不为空压栈指左，为空出栈指右并构造链表关系
/*
struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};*/
class Solution {
public:
    TreeNode* Convert(TreeNode* pRootOfTree)
    {
        if(!pRootOfTree) return nullptr;
        stack<TreeNode *> s;
        TreeNode *curr=pRootOfTree;
        TreeNode *head=nullptr;
        TreeNode *listtmp=nullptr;
        while(curr || !s.empty())
        {
            if(curr)
            {
                s.push(curr);
                curr=curr->left;
            }
            else
            {
                TreeNode *tmp=s.top();
                curr=tmp->right;
                s.pop();
                if(!head)
                {
                    head=tmp;
                    listtmp=tmp;
                }
                else
                {
                    listtmp->right=tmp;
                    tmp->left=listtmp;
                    listtmp=tmp;
                }
            }
        }
        return head;
    }
};
