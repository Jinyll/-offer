/*把只包含质因子2、3和5的数称作丑数（Ugly Number）。例如6、8都是丑数，但14不是，因为它包含质因子7。 
习惯上我们把1当做是第一个丑数。求按从小到大的顺序的第N个丑数。*/

//丑数是已有丑数乘以2或3或5的结果，使用index大小的辅助数组保存所有已排序丑数，使用3个指针指向分别乘以2或3或5能成为下一个最大丑数的值，
//取3个指针指向值乘以2或3或5的结果中最小值，并更新3个指针
class Solution {
public:
    int min(int a,int b,int c)
    {
        int tmp=a>b?b:a;
        return c>tmp?tmp:c;
    }
    int GetUglyNumber_Solution(int index) {
        if(index<=0) return 0;
        if(index==1) return 1;
        vector<int> v;
        v.push_back(1);
        int count=1;
        int t2=0;//t2指向的数字乘以2才有可能成为下一个丑数
        int t3=0;
        int t5=0;
        while(count<index)
        {
            int next=min(v[t2]*2,v[t3]*3,v[t5]*5);
            v.push_back(next);
            if(v[t2]*2==v.back()) ++t2;//符合条件就要更新，比如t2指向3，t3指向2，新加入是6，则两个都要更新
            if(v[t3]*3==v.back()) ++t3;
            if(v[t5]*5==v.back()) ++t5;
            ++count;
        }
        return v.back();
    }
};
