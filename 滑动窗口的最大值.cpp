/*给定一个数组和滑动窗口的大小，找出所有滑动窗口里数值的最大值。例如，如果输入数组{2,3,4,2,6,2,5,1}及滑动窗口的大小3，那么一共存在6个滑动窗口，
他们的最大值分别为{4,4,6,6,6,5}； 针对数组{2,3,4,2,6,2,5,1}的滑动窗口有以下6个： {[2,3,4],2,6,2,5,1}， {2,[3,4,2],6,2,5,1}， {2,3,[4,2,6],2,5,1}， {2,3,4,[2,6,2],5,1}， {2,3,4,2,[6,2,5],1}， {2,3,4,2,6,[2,5,1]}。*/
//双端队列deque保存滑动窗口内有可能成为最大值的数组下标.
//对整个数组，（1）while当队列不为空且当前数字大于队列尾部元素时，队列尾部出队pop_back（因为它们不可能成为最大值），再将当前下标入队尾，
//（2）if如果当前下标和队列头差值等于滑动窗口大小，表明队列头对应的元素已经不在滑动窗口内，则将队列头出队pop_front，
//（3）每次队列头对应的元素即为滑动窗口内最大值。注意单独处理第一个滑窗即只有1步骤，跳出while后保存队头对应元素。
class Solution {
public:
    vector<int> maxInWindows(const vector<int>& num, unsigned int size)
    {
        vector<int> res;
        if(num.empty() || size<=0 || size>num.size()) return res;
        deque<int> dq;//双端队列存储滑动窗口内有可能成为最大值的数字下标
        for(int i=0;i<size;i++)
        {//第一个滑窗
            while(!dq.empty() && num[i]>num[dq.back()]) dq.pop_back();
            dq.push_back(i);
        }
        res.push_back(num[dq.front()]);
        for(int i=size;i<num.size();i++)
        {
            while(!dq.empty() && num[i]>num[dq.back()]) dq.pop_back();
            if(!dq.empty() && ((i-dq.front())==size)) dq.pop_front();//队头下标元素已不在滑动窗口内
            dq.push_back(i);
            res.push_back(num[dq.front()]);
        }
        return res;
    }
};
