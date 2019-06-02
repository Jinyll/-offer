/*给定一个二叉树和其中的一个结点，请找出中序遍历顺序的下一个结点并且返回。注意，树中的结点不仅包含左右子结点，同时包含指向父结点的指针。*/
//实际是二叉查找树中序遍历的后继节点（前驱看左子）。1、有右子，右子为根的最左子为中序后继。2、无右子，(1)是左子，其父为中序后继;(2)是右子，找有左子的最低父节点
/*
struct TreeLinkNode {
    int val;
    struct TreeLinkNode *left;
    struct TreeLinkNode *right;
    struct TreeLinkNode *next;
    TreeLinkNode(int x) :val(x), left(NULL), right(NULL), next(NULL) {
        
    }
};
*/
class Solution {
public:
    TreeLinkNode* getminnode(TreeLinkNode* root)
    {
        while(root->left) root=root->left;
        return root;
    }
    TreeLinkNode* GetNext(TreeLinkNode* pNode)
    {
        if(!pNode) return nullptr;
        if(pNode->right) return getminnode(pNode->right);//1、有右子，右子为根的最左子为中序后继
        TreeLinkNode* parent=pNode->next;//2、无右子，(1)是左子，其父为中序后继;(2)是右子，找有左子的最低父节点
        while(parent && parent->right==pNode)
        {
            pNode=parent;
            parent=parent->next;
        }
        return parent;
    }
};
