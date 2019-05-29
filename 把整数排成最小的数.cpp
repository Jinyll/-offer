/*输入一个正整数数组，把数组里所有数字拼接起来排成一个数，打印能拼接出的所有数字中最小的一个。
例如输入数组{3，32，321}，则打印出这三个数字能排成的最小数字为321323。*/

//对数组中所有数字，按照两两字符串拼接后字典序升序排序。注意sort的cmp函数（1）类的静态函数（2）全局函数（3）重载欲比较类的比较操作符（4）重载了()的函数对象，可以返回不是bool而是int
class Solution {
public:
    static int cmp(int a, int b)
    {
        string ab=to_string(a)+to_string(b);
        string ba=to_string(b)+to_string(a);
        return ab<ba;
    }
    string PrintMinNumber(vector<int> numbers) {
        string res("");
        if(numbers.empty()) return res;
        sort(numbers.begin(),numbers.end(),cmp);
        for(int i=0;i<numbers.size();i++) res+=to_string(numbers[i]);
        return res;
    }
};
