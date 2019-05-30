/*在数组中的两个数字，如果前面一个数字大于后面的数字，则这两个数字组成一个逆序对。
输入一个数组,求出这个数组中的逆序对的总数P。并将P对1000000007取模的结果输出。 即输出P%1000000007*/
//二路归并。归并指针从两个序列尾部开始往前，如果第一个序列值大于第二个序列值，表明有逆序对，数量为第二个指针指向位置到第二序列头
class Solution {
public:
    long long merge(vector<int> &data,vector<int> &copy,int start,int end)
    {
        if(start==end) return 0;
        int mid=(start+end)/2;
        long long left=merge(data,copy,start,mid);
        long long right=merge(data,copy,mid+1,end);
        
        long long count=0;
        int index1=mid,index2=end,current=end;
        while(index1>=start && index2>=mid+1)
        {
            if(data[index1]>data[index2])
            {
                count+=index2-(mid+1)+1;
                copy[current--]=data[index1--];
            }
            else
                copy[current--]=data[index2--];
        }
        while(index1>=start) copy[current--]=data[index1--];
        while(index2>=mid+1) copy[current--]=data[index2--];
        for(int i=start;i<=end;i++) data[i]=copy[i];//始终以data来比较两段，copy暂存比较结果
        return left+right+count;
    }
    int InversePairs(vector<int> data) {
        if(data.empty()) return 0;
        vector<int> copy(data);
        long long count=merge(data,copy,0,data.size()-1);//注意要使用long long来存储逆序对数量，否则ac50
        return count%1000000007;
    }
};
