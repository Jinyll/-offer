/*输入两棵二叉树A，B，判断B是不是A的子结构。（ps：我们约定空树不是任意一个树的子结构）*/
//两个函数递归，一个找到第一个匹配节点，找到后进入第二个判断后续是否都匹配

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
    bool core(TreeNode* pRoot1, TreeNode* pRoot2)
    {
        if(pRoot2==nullptr) return true;
        if(pRoot1==nullptr) return false;
        if(pRoot1->val == pRoot2->val)
            return core(pRoot1->left,pRoot2->left) && core(pRoot1->right,pRoot2->right);
        else return false;
    }
    bool HasSubtree(TreeNode* pRoot1, TreeNode* pRoot2)
    {
        bool res=false;
        if(pRoot1!=nullptr && pRoot2!=nullptr)
        {
            if(pRoot1->val == pRoot2->val)
                res=core(pRoot1,pRoot2);
            if(res==false)
                res=HasSubtree(pRoot1->left,pRoot2);//不同/相同但后续不同
            if(res==false)
                res=HasSubtree(pRoot1->right,pRoot2);
        }
        return res;
    }
};
