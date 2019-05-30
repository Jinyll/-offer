/*一个整型数组里除了两个数字之外，其他的数字都出现了两次。请写程序找出这两个只出现一次的数字。*/
//将数组全部异或得到两个不同数的异或结果，找到异或结果二进制中从后往前第一个1的下标，即不同的两个数在该位不同，以此划分两组，两组再分别异或

class Solution {
public:
    int getindex(int allxor) //寻找二进制表示中最后一个1的下标
    {
        int index=0;
        while((allxor&1)==0) //注意==优先级高于&
        {
            allxor=allxor>>1;
            ++index;
        }
        return index;
    }
    bool is1(int data,int index) //判断data的index位是否为1
    {
        data=data>>index;
        return (data&1);
    }
    void FindNumsAppearOnce(vector<int> data,int* num1,int *num2) {
        if(data.empty()) return;
        int allxor=0;//数组元素全部异或，相同数抵消，得到不同那两个数的异或结果
        for(int i=0;i<data.size();i++)
            allxor^=data[i];
        int indexoflast1=getindex(allxor);//找到异或结果二进制表示中最后一个1的下标，即不同的两个数在该位上不同，可以该值将两个不同数划分到两组
        *num1=0;
        *num2=0;
        for(int i=0;i<data.size();i++)
        {
            if(is1(data[i],indexoflast1)) *num1^=data[i]; //一组是该位为1
            else *num2^=data[i];
        }
    }
};
