/*输入一个递增排序的数组和一个数字S，在数组中查找两个数，使得他们的和正好是S，如果有多对数字的和等于S，输出两个数的乘积最小的。*/
//两个指针分别指向最开始和最后，求和若大于则最后指针前移，小于则最前指针后移，等于则返回。while条件是前指针小于后指针。
class Solution {
public:
    vector<int> FindNumbersWithSum(vector<int> array,int sum) {
        vector<int> res;
        if(array.empty()) return res;
        int first=0;
        int second=array.size()-1;
        while(first<second)
        {
            if(array[first]+array[second]==sum)
            {
                res.push_back(array[first]);
                res.push_back(array[second]);
                break;
            }
            else if(array[first]+array[second]>sum) --second;
            else ++first;
        }
        return res;
    }
    
    /*//另解：for数组，然后二分查找
    vector<int> FindNumbersWithSum(vector<int> array,int sum) {
        vector<int> res;
        if(array.empty()) return res;
        for(int i=0;i<array.size();i++)
        {
            int differ=sum-array[i];
            int start=i+1;
            int end=array.size()-1;
            int mid=-1;
            while(start<=end)
            {
                mid=(start+end)/2;
                if(array[mid]==differ) break;
                else if(array[mid]>differ) end=mid-1;
                else start=mid+1;
            }
            if(start<=end)
            {
                res.push_back(array[i]);
                res.push_back(array[mid]);
                break;
            }
        }
        return res;
    }
    */
    
};
