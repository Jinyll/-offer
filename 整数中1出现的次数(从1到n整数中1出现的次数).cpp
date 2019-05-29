/*求出1~13的整数中1出现的次数,并算出100~1300的整数中1出现的次数？
为此他特别数了一下1~13中包含1的数字有1、10、11、12、13因此共出现6次,但是对于后面问题他就没辙了。
ACMer希望你们帮帮他,并把问题更加普遍化,可以很快的求出任意非负整数区间中1出现的次数（从1 到 n 中1出现的次数）。*/

//21345划分为（1）1-1345去递归，（2）1346-21345，其中首位为1的数有10000-19999共10^4，如果给定n的首位为1，则首位为1的数10000-12345共2346
//          （3）首位固定，其余位中某位为1，剩下0-9任选，2*4*10^3
class Solution {
public:
    int NumberOf1Between1AndN_Solution(int n)
    {
        if(n<=0) return 0;
        char str[50];
        sprintf(str,"%d",n);
        int length=strlen(str);
        if(str[0]=='0') return 0;//递归到只有一位，而该位是0，则0个
        if(length==1) return 1;//否则1-n间只有1一个
        int part1=NumberOf1Between1AndN_Solution(atoi(str+1));//1、1-1345
        int part2=0;//2、n的首位为1，则10000-11345部分首位为1的个数有1346个；若n首位不为1，则10000-19999共10^4个
        if(str[0]=='1') part2=atoi(str+1)+1;
        else part2=pow(10,length-1);
        int part3=pow(10,length-2)*(length-1)*(str[0]-'0');//3、首位固定，其余位中某一位为1,剩余从0-9种选择1346-11345和11346-21345
        return part1+part2+part3;
    }
};
