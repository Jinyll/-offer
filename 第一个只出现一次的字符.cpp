/*在一个字符串(0<=字符串长度<=10000，全部由字母组成)中找到第一个只出现一次的字符,并返回它的位置, 如果没有则返回 -1（需要区分大小写）.*/
//哈希表 以字符的ascii码为下标，值为出现次数。最后遍历string判断对应字符出现次数是1，则返回该值下标
class Solution {
public:
    int FirstNotRepeatingChar(string str) {
        if(str.empty()) return -1;
        vector<int> hashtable(128,0);
        for(int i=0;i<str.size();i++) hashtable[str[i]]++;
        for(int i=0;i<str.size();i++)
            if(hashtable[str[i]]==1) return i;
        return -1;
    }
};
