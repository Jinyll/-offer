/*用两个栈来实现一个队列，完成队列的Push和Pop操作。 队列中的元素为int类型。*/
//一个栈压入，一个弹出
class Solution
{
public:
    void push(int val)
    {
        stack1.push(val);
    }
    int pop()
    {
        if(stack1.empty() && stack2.empty()) return -1;//都为空 错误
        if(stack2.empty())
        {
            while(!stack1.empty())
            {
                stack2.push(stack1.top());
                stack1.pop();
            }
        }
        int res=stack2.top();
        stack2.pop();
        return res;
    }    

private:
    stack<int> stack1;//压入push
    stack<int> stack2;//删除pop
};
