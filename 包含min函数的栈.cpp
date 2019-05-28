/*定义栈的数据结构，请在该类型中实现一个能够得到栈中所含最小元素的min函数（时间复杂度应为O（1））。*/
//用一个栈保存当前栈最小元素，如果入栈元素比栈顶小，则压入最小元素栈，否则压入最小元素栈的栈顶，同步pop
class Solution {
public:
    void push(int value) {
        dataStack.push(value);
        if(minStack.empty() || value<minStack.top())
            minStack.push(value);
        else
            minStack.push(minStack.top());
    }
    void pop() {
        if(!dataStack.empty())
            dataStack.pop();
        if(!minStack.empty())
            minStack.pop();
    }
    int top() {
        if(!dataStack.empty())
            return dataStack.top();
        return -1;
    }
    int min() {
        if(!minStack.empty())
            return minStack.top();
        return -1;
    }
private:
    stack<int> dataStack;
    stack<int> minStack;
};
