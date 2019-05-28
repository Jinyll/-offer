/*操作给定的二叉树，将其变换为源二叉树的镜像。*/
//递归调整左右。
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
    void Mirror(TreeNode *pRoot) {
        if(pRoot==nullptr) return;
        if(pRoot->left==nullptr && pRoot->right==nullptr) return;//左右都为空，不需要交换
        TreeNode *tmp=pRoot->left;
        pRoot->left=pRoot->right;
        pRoot->right=tmp;
        if(pRoot->left)
            Mirror(pRoot->left);//左不为空则递归调整
        if(pRoot->right)
            Mirror(pRoot->right);
        return;
    }
};
