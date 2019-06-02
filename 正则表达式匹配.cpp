/*请实现一个函数用来匹配包括'.'和'*'的正则表达式。模式中的字符'.'表示任意一个字符，而'*'表示它前面的字符可以出现任意次（包含0次）。 
在本题中，匹配是指字符串的所有字符匹配整个模式。例如，字符串"aaa"与模式"a.a"和"ab*ac*a"匹配，但是与"aa.a"和"ab*a"均不匹配*/

//递归。下一个是*，若当前匹配，则可以递归看*匹配0/1/n个，若当前不匹配，则*匹配0个。若下一个不是*且当前匹配，同步后移。若下一个不是*且当前不匹配则错误 
//      需注意若pattern先与str结束则错误
class Solution {
public:
    bool core(char *str, char *pattern)
    {
        if(*str=='\0' && *pattern=='\0') return true;//一起结束
        if(*str!='\0' && *pattern=='\0') return false;//当前没结束，但pattern结束
        if(*(pattern+1)=='*')//下一个是*
        {
            if(*str==*pattern || (*str!='\0' && *pattern=='.'))//当前匹配，*决定匹配0/1/n个
                return core(str,pattern+2) || core(str+1,pattern+2) || core(str+1,pattern);
            else
                return core(str,pattern+2);
        }
        if(*str==*pattern || (*str!='\0' && *pattern=='.'))//下一个不是*，当前匹配
            return core(str+1,pattern+1);
        return false;//下一个不是*，当前也不匹配
    }
    bool match(char* str, char* pattern)
    {
        if(!str || !pattern) return false;
        return core(str,pattern);
    }
};
