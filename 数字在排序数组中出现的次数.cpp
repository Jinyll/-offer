/*统计一个数字在排序数组中出现的次数。*/
//二分查找 找到后需判断左右是否相等，若相等，则表明不止一个，需while继续二分查找第一次出现和最后一次出现的下标
class Solution {
public:
    int search(const vector<int> &data,int k,int i,int j)
    {
        int start=i;
        int end=j;
        while(start<=end)
        {
            int mid=(start+end)/2;
            if(data[mid]==k) return mid;
            else if(data[mid]>k) end=mid-1;
            else start=mid+1;
        }
        return -1;
    }
    int GetNumberOfK(vector<int> data ,int k) {
        if(data.empty()) return 0;
        int index=search(data,k,0,data.size()-1);
        if(index==-1) return 0;
        else
        {
            if((index-1<0 || data[index-1]!=k) && (index+1>data.size()-1 || data[index+1]!=k)) return 1;
            int left=index;
            while(left-1>=0 && data[left-1]==k)
            {
                left=search(data,k,0,left-1);
            }
            int right=index;
            while(right+1<=data.size()-1 && data[right+1]==k)
            {
                right=search(data,k,right+1,data.size()-1);
            }
            return right-left+1;
        }
    }
};
