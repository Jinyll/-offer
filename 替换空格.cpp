/*请实现一个函数，将一个字符串中的每个空格替换成“%20”。例如，当字符串为We Are Happy.则经过替换之后的字符串为We%20Are%20Happy。*/
class Solution {
public:
    //用string的函数
    void replaceSpace(char *str, int length) {
	    if (!str || length <= 0) return;

	    string s(str);
	    int start = 0;
	    while (start < s.size())
	    {
		    int index = s.find(' ', start);
		    if (index != -1)
		    {
			    s.erase(index, 1);
			    s.insert(index, "%20");
			    start = index + 3;
		    }
		    else break;
	    }
	    strcpy(str, s.c_str());
    }
    
    //C语言 从后往前移动数据，遇到空格替换，On
	/*void replaceSpace(char *str,int length) {//length是str总大小 会多分配的
        if(str==nullptr || length<=0){
            return;
        }
        int i=0;
        int indexOfOri=0;
        int voidnum=0;
        while(str[i]!='\0'){//原字符串长度 空格数量
            ++indexOfOri;
            if(str[i]==' '){
                ++voidnum;
            }
            ++i;
        }
        int indexOfChange=indexOfOri+2*voidnum;
        if(indexOfChange>length){
            return;
        }
        while(indexOfOri>=0 && indexOfChange>indexOfOri){//indexOfOri指向原字符串结尾 indexOfChange新字符串结尾
            if(str[indexOfOri]==' '){
                str[indexOfChange--]='0';
                str[indexOfChange--]='2';
                str[indexOfChange--]='%';
            }
            else{
                str[indexOfChange--]=str[indexOfOri];
            }
            --indexOfOri;
        }
        return;
	}*/
};
