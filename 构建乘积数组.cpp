/*给定一个数组A[0,1,...,n-1],请构建一个数组B[0,1,...,n-1],其中B中的元素B[i]=A[0]*A[1]*...*A[i-1]*A[i+1]*...*A[n-1]。不能使用除法。*/
//两个辅助数组，一个结果数组。一个辅助数组表示从A0-A(i-1)部分乘积【第一位是1，从第二位起用前一位乘以A(i-1)】，
//一个表示A(i+1)-A(n-1)部分乘积【最后一位为1，从倒数第二位起用后一位乘以A(i+1)】。最后两个数组相应位置相乘得到结果数组。
class Solution {
public:
    vector<int> multiply(const vector<int>& A) {
        int size=A.size();
        vector<int> C(size,1);//n个数，初始化为1
        vector<int> D(size,1);
        for(int i=1;i<size;i++)
        {
            C[i]=C[i-1]*A[i-1];
        }
        for(int i=size-2;i>=0;i--)
        {
            D[i]=D[i+1]*A[i+1];
        }
        vector<int> result(size,1);
        for(int i=0;i<size;i++)
        {
            result[i]=C[i]*D[i];
        }
        return result;
    }
};
