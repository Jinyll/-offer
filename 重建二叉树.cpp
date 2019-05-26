/*输入某二叉树的前序遍历和中序遍历的结果，请重建出该二叉树。假设输入的前序遍历和中序遍历的结果中都不含重复的数字。
例如输入前序遍历序列{1,2,4,7,3,5,6,8}和中序遍历序列{4,7,2,1,5,3,8,6}，则重建二叉树并返回。*/
//在前序中得到根节点，在中序中找到该节点，则左边是左子树，右边是右子树，递归建立左右子树。注意结束条件
/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* core(const vector<int> &pre, const vector<int> &vin, int prestart, int preend, int vinstart, int vinend)
	{
		int rootval = pre[prestart];
		TreeNode* rootnode = new TreeNode(rootval);//根节点
		if (prestart == preend) return rootnode;//结束条件，没有左右子树
		int vindex = vinstart;//前序中根节点在中序中下标
		while (vindex <= vinend)
		{
			if (vin[vindex] != pre[prestart])
				++vindex;
			else break;
        }
        if(vindex>vinend) return nullptr;//在in中没找到，输入序列有误
		int leftrange = vindex - vinstart;
		int rightrange = vinend - vindex;        
		if(leftrange!=0)
			rootnode->left = core(pre, vin, prestart + 1, prestart + leftrange, vinstart, vindex - 1);
		if(rightrange!=0)
			rootnode->right = core(pre, vin, prestart + leftrange + 1,  preend, vindex + 1, vinend);
		return rootnode;
	}
	TreeNode* reConstructBinaryTree(vector<int> pre, vector<int> vin) {
		if (pre.empty() || vin.empty()) return nullptr;
		return core(pre, vin, 0, pre.size() - 1, 0, vin.size() - 1);
	}
};
