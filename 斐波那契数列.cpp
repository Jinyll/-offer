/*大家都知道斐波那契数列，现在要求输入一个整数n，请你输出斐波那契数列的第n项（从0开始，第0项为0）。n<=39*/

class Solution {
public:
    int Fibonacci(int n) {
        /*int temp[2]={0,1};
        if(n<2){
            return temp[n];
        }*/
        int f0=0;
        int f1=1;
        int res=n;
        for(int i=2;i<=n;i++)
        {
            res=f0+f1;
            f0=f1;
            f1=res;
        }
        return res;      
    }
};
