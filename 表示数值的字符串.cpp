/*请实现一个函数用来判断字符串是否表示数值（包括整数和小数）。例如，字符串"+100","5e2","-123","3.1416"和"-1E-16"都表示数值。 但是"12e","1a3.14","1.2.3","+-5"和"12e+4.3"都不是。*/
//+-A.B[e|E]+-C  若有小数点，则A和B必须有一个，其中A前可有正负，B前不可有。若有e|E，则前后必须有值，其后C可有正负号。过程中调整string指针
class Solution {
public:
    bool isunsignedint(char *&string)//判断是否是无符号整数
    {
        char *before=string;
        while((*string)!='\0' && (*string)>='0' && (*string)<='9') ++string;
        return string>before;
    }
    bool isinteger(char *&string)//判断是否为整数，有无符号都行
    {
        if((*string)=='+' || (*string)=='-') ++string;
        return isunsignedint(string);
    }
    bool isNumeric(char* string)//+-A.B[e|E]+-C
    {
        if(!string) return false;
        bool numeric=isinteger(string);//修改了string，指向不是整数的地方
        if((*string)=='.')
        {
            ++string;
            numeric=isunsignedint(string) || numeric;//注意判断B部分必须放前面，才可修改了string。小数点前后至少有一个整数，前A可有正负，后B不可
        }
        if((*string)=='e' || (*string)=='E')
        {
            ++string;
            numeric=numeric && isinteger(string);//e前后必须有值，e后C不可有正负
        }
        return numeric && ((*string)=='\0');//必须到结束
    }

};
