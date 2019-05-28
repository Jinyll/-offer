/*输入两个整数序列，第一个序列表示栈的压入顺序，请判断第二个序列是否可能为该栈的弹出顺序。假设压入栈的所有数字均不相等。
例如序列1,2,3,4,5是某栈的压入顺序，序列4,5,3,2,1是该压栈序列对应的一个弹出序列，但4,3,5,1,2就不可能是该压栈序列的弹出序列。
（注意：这两个序列的长度是相等的）*/
//用辅助栈。辅助栈顶和弹出序列不同则压入，否则弹出且弹出序列指针后移。注意两个序列值可能不同
class Solution {
public:
    bool IsPopOrder(vector<int> pushV,vector<int> popV) {
        if(pushV.empty() || popV.empty()) return false;
        int pushp=0;
        int popp=0;
        int length=pushV.size();
        stack<int> s;
        while(popp<length)
        {
            while(s.empty() || s.top()!=popV[popp])//不相等，若还有元素可压入，则压入，若没有，表明序列不对
            {
                if(pushp==length) break;
                s.push(pushV[pushp]);
                ++pushp;
            }
            if(s.top()!=popV[popp]) break;
            s.pop();
            ++popp;
            if(s.empty() && popp==length) return true;
        }
        return false;
    }
};
