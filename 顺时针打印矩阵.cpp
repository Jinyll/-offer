/*输入一个矩阵，按照从外向里以顺时针的顺序依次打印出每一个数字，
例如，如果输入如下4 X 4矩阵： 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 则依次打印出数字1,2,3,4,8,12,16,15,14,13,9,5,6,7,11,10.*/
//注意while结束条件，判断行列数再确定是否打印
class Solution {
public:
    vector<int> printMatrix(vector<vector<int> > matrix) {
        vector<int> res;
        if(matrix.empty()) return res;
        int rows=matrix.size();
        int cols=matrix[0].size();
        int start=0;
        while(start*2<rows && start*2<cols)//注意结束条件
        {
            int endc=cols-1-start;
            int endr=rows-1-start;
            for(int i=start;i<=endc;i++)
                res.push_back(matrix[start][i]);
            if(start<endr)//至少两行
                for(int i=start+1;i<=endr;i++)
                    res.push_back(matrix[i][endc]);
            if(start<endr && start<endc)//至少两行，至少两列
                for(int i=endc-1;i>=start;i--)
                    res.push_back(matrix[endr][i]);
            if((endr-start)>1 && start<endc)//至少三行，至少两列
                for(int i=endr-1;i>start;i--)
                    res.push_back(matrix[i][start]);
            ++start;
        }
        for(int i=0;i<res.size();i++)
            cout<<res[i]<<" ";
        return res;
    }
};
