/*一只青蛙一次可以跳上1级台阶，也可以跳上2级……它也可以跳上n级。求该青蛙跳上一个n级的台阶总共有多少种跳法。*/
//1 2 4 8 16 是2^(n-1)
//或者当前值是之前所有方法和+1，用斐波那契，一个变量记录前面所有方法和
class Solution {
public:
    int jumpFloorII(int number) {//f(n)=2^(n-1)  f(n)=2*f(n-1)
        if (number <= 0) return -1;
	      int f1 = 1;
	      int f2 = 2;
	      int res = number;
	      int tmp = f1;
	      for (int i = 3; i <= number; i++)
	      {
		
		      tmp = tmp + f2;
		      res = tmp + 1;
		      f1 = f2;
		      f2 = res;
	      }
	      return res;
        
        /*if(number<=0){
            return -1;
        }
        int result=1;
        for(int i=1;i<number;i++){//从n为2开始，执行number-1次乘2
            result *= 2;
        }
        return result;*/
    }
};
