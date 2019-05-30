/*例如，“student. a am I”。后来才意识到，这家伙原来把句子单词的顺序翻转了，正确的句子应该是“I am a student.”。*/
//先翻转整个句子，再翻转每个单词。也可先翻转每个单词，再翻转整个句子
class Solution {
public:
    void reverseMain(string& str,int begin,int end)
    {
        if(end-begin==0) return;
        while(begin<end)
        {
            if (str[begin] != str[end])
		swap(str[begin], str[end]);
	    ++begin;
	    --end;
        }
    }
    string ReverseSentence(string str) {
    //先翻转整个句子，再对每个单词进行翻转，都可用一个函数
        string result;
        if(str.empty())
            return result;
        reverseMain(str,0,str.size()-1);//翻转整个句子
        int begin=0;
        for(int i=0;i<str.size()+1;i++)
        {
            if(str[i]==' ' || str[i]=='\0')
            {
                reverseMain(str,begin,i-1);//翻转这个单词
                begin=i+1;
            }
        }
        return str;
    }
};
