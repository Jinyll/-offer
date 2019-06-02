/*将一个字符串转换成一个整数(实现Integer.valueOf(string)的功能，但是string不符合数字要求时返回0)，要求不能使用字符串转换整数的库函数。
数值为0或者字符串不是一个合法的数值则返回0。*/
//不需考虑1e2的情况，注意正负号，溢出，错误字符和数值0都返回0所以要设置全局变量标识是否成功转换
class Solution {
public:
    enum status{valid=0,invalid=1};//成功转换与否
    int gstatus=valid;
    
    int core(string str,int index,bool minus)
    {
        int res=0;
        while(str[index]!='\0')
        {
            if(str[index]>='0' && str[index]<='9')
            {
                int flag=minus?-1:1;//考虑正负
                res=res*10+flag*(str[index]-'0');
                if((minus && res<0x80000000) || (!minus && res>0x7fffffff))//溢出
                {
                    res=0;
                    break;
                }
            }
            else
            {//不合法字符串
                res=0;
                break;
            }
            ++index;
        }
        if(str[index]=='\0') gstatus=valid;//成功转换完毕
        return res;
    }
    
    int StrToInt(string str) {
        gstatus=invalid;
        if(str.empty()) return 0;//不合法返回0
        int index=0;
        bool minus=false;//负数
        if(str[index]=='+') ++index;
        else if(str[index]=='-')
        {
            minus=true;
            ++index;
        }
        int res=0;
        if(str[index]!='\0')
            res=core(str,index,minus);
        return res;
    }
};
