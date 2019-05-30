/*输入一棵二叉树，求该树的深度。从根结点到叶结点依次经过的结点（含根、叶结点）形成树的一条路径，最长路径的长度为树的深度。*/
//非递归用层次遍历队列，递归代码简洁，不管是否为空都递归，return时才+1
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
    //方法1 非递归
    int TreeDepth(TreeNode* pRoot)
    {//层次遍历
        if(!pRoot) return 0;
        queue<TreeNode *> q;
        q.push(pRoot);
        int depth=0,currcount=0,currnums=1;//currcount该层已经弹出几个，currnums该层共有几个节点
        while(!q.empty())
        {
            TreeNode *tmp=q.front();
            q.pop();
            ++currcount;
            if(tmp->left) q.push(tmp->left);
            if(tmp->right) q.push(tmp->right);
            if(currcount==currnums)//该层全部弹出，深度加1，重置下一层已经弹出和下一层节点数量
            {
                ++depth;
                currcount=0;
                currnums=q.size();
            }
        }
        return depth;
    }
    
    //方法2 递归
    /*int TreeDepth(TreeNode* pRoot)
    {
        if(!pRoot) return 0;
        int left=TreeDepth(pRoot->left);
        int right=TreeDepth(pRoot->right);
        return (left>right)?left+1:right+1;
    }*/
};
