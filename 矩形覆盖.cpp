/*我们可以用2*1的小矩形横着或者竖着去覆盖更大的矩形。请问用n个2*1的小矩形无重叠地覆盖一个2*n的大矩形，总共有多少种方法？*/
//纯然斐波那契
class Solution {
public:
    int rectCover(int number) {//f(n)种方法。若第一步竖放，则f(n-1);若第一步横放，则下面也必须横放，右边有f(n-2)种。f(n)=f(n-1)+f(n-2)
        if(number<0) return -1;
        if(number==0) return 0;
        int f1=1;
        int f2=2;
        int res=number;
        for(int i=3;i<=number;i++)
        {
            res=f1+f2;
            f1=f2;
            f2=res;
        }
        return res;
    }
};
