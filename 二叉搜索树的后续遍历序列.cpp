/*输入一个整数数组，判断该数组是不是某二叉搜索树的后序遍历的结果。如果是则输出Yes,否则输出No。假设输入的数组的任意两个数字都互不相同*/
//递归。找到右子树的根节点，若右子树有小于当前根节点的，则false。否则对当前根节点左右都符合要求，若左右节点还有子树，则递归判断
class Solution {
public:
    bool core(const vector<int> &sequence, int start, int end)
    {
        int root=sequence[end];
        int i=start;
        for(;i<end;i++)
        {
            if(sequence[i]>root)
                break;
        }
        int rightbegin=i;
        for(int j=rightbegin;j<end;j++)
        {
            if(sequence[j]<sequence[end])
                return false;
        }
        //对当前root的左右子树已经判断结束，符合
        bool left=true;
        if(rightbegin>start+1) left=core(sequence,start,rightbegin-1);
        bool right=true;
        if(rightbegin<end-1) right=core(sequence,rightbegin,end-1);
        return (left && right);
    }
    bool VerifySquenceOfBST(vector<int> sequence) {
        if(sequence.empty()) return false;
        return core(sequence,0,sequence.size()-1);
    }
};
