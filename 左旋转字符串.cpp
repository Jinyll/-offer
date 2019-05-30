/*字符序列S=”abcXYZdef”,要求输出循环左移3位后的结果，即“XYZdefabc*/

class Solution {
public:
    string LeftRotateString(string str, int n) {
        string s("");
        if(str.empty() || n>str.size()) return s;
        s+=str.substr(n);
        s+=str.substr(0,n);
        return s;
    }
};
