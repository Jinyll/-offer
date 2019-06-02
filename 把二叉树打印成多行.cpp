/*从上到下按层打印二叉树，同一层结点从左至右输出。每一层输出一行。*/
//类似层次遍历求二叉树深度，队列，当前已经pop访问节点数量，正在访问的这一层有多少个节点。
//while队列不为空时，出队访问存储，并增加已访问节点数，若左右孩子不为空则左右顺序进队列
//如果当前已经pop访问的节点数量等于该层节点总数，则存储该层结果，清空暂存一层结果的数组，并重置当前已访问和下一层节点总数（即队列此时size）
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
        vector<vector<int> > Print(TreeNode* pRoot) {
            vector<vector<int> > res;
            if(!pRoot) return res;
            queue<TreeNode *> q;
            q.push(pRoot);
            vector<int> tmp;//一层结果
            int count=0;//已经pop访问节点数
            int allnums=1;//该层总节点数
            while(!q.empty())
            {
                TreeNode *front=q.front();
                q.pop();
                tmp.push_back(front->val);
                ++count;
                if(front->left) q.push(front->left);
                if(front->right) q.push(front->right);
                if(count==allnums)//该层访问结束，保存各层结果，重置已访问节点数和下一层节点总数
                {
                    res.push_back(tmp);
                    tmp.clear();
                    count=0;
                    allnums=q.size();
                }
            }
            return res;
        }
    
};
