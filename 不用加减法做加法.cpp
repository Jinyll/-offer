/*写一个函数，求两个整数之和，要求在函数体内不得使用+、-、*、/四则运算符号。*/
//异或得到忽略进位的结果，与并左移一位得到进位结果，把前两步相加，其实就是重复前两步，直到不产生进位
class Solution {
public:
    int Add(int num1, int num2)
    {
        if(num1==0) return num2;
        else if(num2==0) return num1;
        while(num2)
        {
            int ignorecarry=num1^num2;
            int carry=(num1&num2)<<1;
            num1=ignorecarry;
            num2=carry;
        }
        return num1;
    }
};
