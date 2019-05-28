/*从上往下打印出二叉树的每个节点，同层节点从左至右打印。*/
//层次遍历，用队列
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
    vector<int> PrintFromTopToBottom(TreeNode* root) {
        vector<int> res;
        if(root==nullptr) return res;
        queue<TreeNode *> q;
        q.push(root);
        while(!q.empty())
        {
            TreeNode *front=q.front();
            res.push_back(front->val);
            q.pop();
            if(front->left) q.push(front->left);
            if(front->right) q.push(front->right);
        }
        for(int i=0;i<res.size();i++)
            cout<<res[i]<<" ";
        return res;
    }
};
