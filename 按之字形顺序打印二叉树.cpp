/*请实现一个函数按照之字形打印二叉树，即第一行按照从左到右的顺序打印，第二层按照从右至左的顺序打印，第三行按照从左到右的顺序打印，其他行以此类推。*/
//两个栈，other一个孩子节点是左右顺序入栈，curr一个是右左顺序入栈。
//当有一个栈不为空时，出当前栈并访问存储，根据当前栈编号将当前节点的孩子节点按照顺序压入另一个栈，
//如果当前栈为空，表明该层已经访问结束，将该层结果存入结果集，重置当前栈编号。
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
    //解法1 两个栈，一个栈是左右入栈，另一个是右左入栈，当前栈出栈并访问时，将孩子压入另一个栈
    //如果当前栈为空，则一层访问结束，存储该层结果，并重置访问栈编号
    vector<vector<int> > Print(TreeNode* pRoot) {
        vector<vector<int> > res;
        if(!pRoot) return res;
        stack<TreeNode *> s[2];
        int curr=0;//右左入栈
        int other=1;//左右入栈
        s[0].push(pRoot);
        vector<int> tmp;//一层结果
        while(!s[curr].empty() || !s[other].empty())
        {
            TreeNode *topnode=s[curr].top();
            s[curr].pop();
            tmp.push_back(topnode->val);
            if(curr==0)
            {//另一个栈是左右入栈
                if(topnode->left) s[other].push(topnode->left);
                if(topnode->right) s[other].push(topnode->right);
            }
            else
            {
                if(topnode->right) s[other].push(topnode->right);
                if(topnode->left) s[other].push(topnode->left);
            }
            if(s[curr].empty())//访问完一层，存储结果，重置当前栈编号
            {
                res.push_back(tmp);
                tmp.clear();
                curr=1-curr;
                other=1-other;
            }
        }
        return res;
    }
    
    //解法2 类似层次遍历求二叉树深度（队列，当层已pop多少，当层有多少节点），一层结束后，根据是奇数还是偶数层看是否逆序该层结果
    /*vector<vector<int> > Print(TreeNode* pRoot) {
        vector<vector<int> > res;
        if(!pRoot) return res;
        queue<TreeNode *> q;
        q.push(pRoot);
        int depth=1;
        int count=0;
        int allnums=1;
        vector<int> tmp;
        while(!q.empty())
        {
            TreeNode *front=q.front();
            q.pop();
            tmp.push_back(front->val);
            ++count;
            if(front->left) q.push(front->left);
            if(front->right) q.push(front->right);
            if(count==allnums)//一层都pop出去
            {
                if((depth&0x1)==0)//偶数层，逆序
                {
                    int start=0;
                    int end=tmp.size()-1;
                    while(start<end)
                    {
                        swap(tmp[start],tmp[end]);
                        ++start;
                        --end;
                    }
                }
                res.push_back(tmp);
                tmp.clear();
                count=0;
                allnums=q.size();
                ++depth;
            }
        }
        return res;
    }*/
};
