/*找出所有和为S的连续正数序列*/
//最大可包含的数字是（1+sum）/2，用vector暂存现有数据，求和如果等于sum则一个结果并删掉第一个数字，如果大于则删掉第一个数字，如果小于则加上下一个数字

class Solution {
public:
    vector<vector<int> > FindContinuousSequence(int sum) {
        vector<vector<int> > res;
        if(sum<3) return res;//序列至少两个数
        vector<int> v;
        int index=2;
        int mid=(1+sum)/2;//最大可包含的数字，如3时最大2
        v.push_back(1);
        v.push_back(2);
        while(index<=mid)
        {
            int sumseq=accumulate(v.begin(),v.end(),0);
            if(sumseq==sum)
            {
                res.push_back(v);
                v.erase(v.begin());
            }
            else if(sumseq>sum)
                v.erase(v.begin());
            else
            {
                ++index;
                v.push_back(index);
            }
        }
        return res;
    }
};
