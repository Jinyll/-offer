/*输入一个整数，输出该数二进制表示中1的个数。其中负数用补码表示。*/
//n&(n-1) 是将n的二进制表示中，最后一个1变为0
class Solution {
public:
     int  NumberOf1(int n) {
         int count = 0;
	     while (n)
	    {
		    n = n & (n - 1);
		    ++count;
	    }		
	    return count;
     }
};
