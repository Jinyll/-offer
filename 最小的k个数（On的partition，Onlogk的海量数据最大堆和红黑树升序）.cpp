/*输入n个整数，找出其中最小的K个数。例如输入4,5,1,6,2,7,3,8这8个数字，则最小的4个数字是1,2,3,4,。*/
//方法1 nlogk海量数据。先建立k个元素的最大堆，如果新值比堆顶小，则删除堆顶，加入新值，最后结果即为最小的k个数
class Solution {
public:
    vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
        vector<int> res;
        if(input.empty() || k>input.size() || k<=0) return res;
        for(int i=0;i<input.size();i++)
        {
            if(i<k) res.push_back(input[i]);
            else
            {
                if(i==k)
                    make_heap(res.begin(),res.end());
                if(input[i]<res.front())
                {
                    pop_heap(res.begin(),res.end());//删除堆顶，加入新值
                    res.pop_back();
                    res.push_back(input[i]);
                    push_heap(res.begin(),res.end());
                }
            }
        }
        return res;
    }
};

//方法2 nlogk用红黑树的multiset
class Solution {
public:
    vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
        vector<int> res;
        if(input.empty() || k>input.size() || k<=0) return res;
        multiset<int,greater<int> > mset; //降序，最大元素在begin位置
        for(int i=0;i<input.size();i++)
        {
            if(i<k) mset.insert(input[i]);
            else
            {
                if(input[i]<*mset.begin())
                {
                    mset.erase(mset.begin());
                    mset.insert(input[i]);
                }
            }
        }
        for(multiset<int,greater<int> >::iterator it=mset.begin();it!=mset.end();it++) res.push_back(*it);
        return res;
    }
};

//方法2 On用partition，修改原数组
class Solution {
public:
    int partition(vector<int> &input, int start, int end)
    {
        int small=start-1;
        for(int index=start;index<end;index++)
        {
            if(input[index]<input[end])
            {
                ++small;
                if(small!=index)
                    swap(input[index],input[small]);
            }
        }
        ++small;
        swap(input[end],input[small]);
        return small;
    }
    vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
        vector<int> res;
        if(input.empty() || k>input.size() || k<=0) return res;
        int start=0;
        int end=input.size()-1;
        int index=partition(input,start,end);
        while(index!=k-1)//不要设为k，若共4位，寻找最小4位，此处index不会为4，即k会错误
        {
            if(index>k-1)
            {
                end=index-1;
                index=partition(input,start,end);
            }
            else
            {
                start=index+1;
                index=partition(input,start,end);
            }
        }
        for(int i=0;i<=index;i++) res.push_back(input[i]);
        return res;
    }
};
