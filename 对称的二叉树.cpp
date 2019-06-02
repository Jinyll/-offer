/*请实现一个函数，用来判断一颗二叉树是不是对称的。注意，如果一个二叉树同此二叉树的镜像是同样的，定义其为对称的。*/
//递归传入指向该树的两个指针，递归结束条件是两个都为空则true，一个为空另一个不为空则false，两个都不为空，则若当前值相等则两树左和右对比，否则不对称。
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
    bool core(TreeNode *p1,TreeNode *p2)
    {
        if(!p1 && !p2) return true;
        if(!p1 && p2) return false;
        if(p1 && !p2) return false;
        if(p1->val==p2->val)
            return core(p1->left,p2->right) && core(p1->right,p2->left);
        return false;
    }
    bool isSymmetrical(TreeNode* pRoot)
    {
        if(!pRoot) return true;
        return core(pRoot,pRoot);
    }

};
