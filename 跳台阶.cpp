/*一只青蛙一次可以跳上1级台阶，也可以跳上2级。求该青蛙跳上一个n级的台阶总共有多少种跳法（先后次序不同算不同的结果）。*/
//斐波那契
class Solution {
public:
    int jumpFloor(int number) 
    {
        if(number<=0) return -1;
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
