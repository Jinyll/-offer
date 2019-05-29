/*输入一个字符串,按字典序打印出该字符串中字符的所有排列。例如输入字符串abc,则打印出由字符a,b,c所能排列出来的所有字符串abc,acb,bac,bca,cab和cba。*/
//递归分两步。第一步，求所有可能出现在第一个位置的字符，第二步固定第一个字符，求后面字符的全排列
class Solution {
public:
    void core(string str, int begin)
    {
        if(begin==str.size())
        {
            res.push_back(str);
            return;
        }
        for(int i=begin;i<str.size();i++)
        {
            if(i!=begin && str[i]==str[begin]) continue;
            swap(str[i],str[begin]);//第一步：求所有可能出现在第一个位置的字符，即将第一个字符与后面所有字符交换
            core(str,begin+1);//第二步：固定第一个字符，求后面所有字符的全排列
            swap(str[i],str[begin]);
        }
    }
    vector<string> Permutation(string str) {
        if(str.empty()) return res;
        core(str,0);
        sort(res.begin(),res.end());
        return res;
    }
private:
    vector<string> res;
};
