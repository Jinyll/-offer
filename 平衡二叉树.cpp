/*输入一棵二叉树，判断该二叉树是否是平衡二叉树。*/
//为空树，或高度差不超过1。基于二叉树深度，参数传递深度，如果左右子树单独满足，再看左右子树高度差，若还满足则以大值更新当前节点高度
class Solution {
public:
    bool core(TreeNode *pRoot,int &depth)
    {
        if(!pRoot)
        {
            depth=0;
            return true;
        }
        int leftdepth=0,rightdepth=0;
        if(core(pRoot->left,leftdepth) && core(pRoot->right,rightdepth))
        {
            if(leftdepth-rightdepth<=1 && leftdepth-rightdepth>=-1)
            {
                depth=(leftdepth>rightdepth)?leftdepth+1:rightdepth+1;
                return true;
            }
        }
        return false;
    }
    bool IsBalanced_Solution(TreeNode* pRoot) {
        if(!pRoot) return true;
        int depth=0;
        return core(pRoot,depth);
    }
};
