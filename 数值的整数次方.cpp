/*给定一个double类型的浮点数base和int类型的整数exponent。求base的exponent次方。*/
//递归，公式a^n=a^(n/2) * a^(n/2)如果n是偶数；a^n=a^((n-1)/2) * a^((n-1)/2) * a如果n是奇数。
class Solution {
public:
    double core(double base, unsigned int ex)
    {
        if(ex==0) return 1;
        if(ex==1) return base;
        double res=core(base,ex>>1);
        res=res*res;
        if(ex&0x1) res=res*base;//指数是奇数
        return res;
    }
    double Power(double base, int exponent) {
        if(abs(base-0)<1e-6 && exponent<=0) return -1;//底数是0
        unsigned int unex=(unsigned int)abs(exponent);
        double res=core(base,unex);
        if(exponent<0) res=1.0/res;
        return res;
    }
};
