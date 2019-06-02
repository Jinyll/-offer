/*请实现一个函数用来找出字符流中第一个只出现一次的字符。例如，当从字符流中只读出前两个字符"go"时，第一个只出现一次的字符是"g"。
当从该字符流中读出前六个字符“google"时，第一个只出现一次的字符是"l"。如果当前字符流没有存在出现一次的字符，返回#字符。*/
//插入和输出函数 字符做下标的哈希表，存储出现下标，如果没出现过-1，如果出现第二次则-2.输出时for哈希表得到只出现一次的最小下标，其对应的哈希表下标即为结果字符
class Solution
{
public:
    Solution()
    {
        index=0;
        for(int i=0;i<128;i++) hashtable.push_back(-1);
    }
  //Insert one char from stringstream
    void Insert(char ch)
    {
        if(hashtable[ch]==-1) hashtable[ch]=index;//出现第一次，存放下标
        else if(hashtable[ch]>=0) hashtable[ch]=-2;//出现第二次
        ++index;
    }
  //return the first appearence once char in current stringstream
    char FirstAppearingOnce()
    {
        int minindex=0x7fffffff;
        char res='#';
        for(int i=0;i<128;i++)
        {
            if(hashtable[i]>=0 && hashtable[i]<minindex)//只出现过一次，出现下标最小
            {
                minindex=hashtable[i];
                res=i;
            }
        }
        return res;
    }
private:
    int index;
    vector<int> hashtable;
};
