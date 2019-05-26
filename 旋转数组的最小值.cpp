/*把一个数组最开始的若干个元素搬到数组的末尾，我们称之为数组的旋转。 
输入一个非减排序的数组的一个旋转，输出旋转数组的最小元素。
例如数组{3,4,5,1,2}为{1,2,3,4,5}的一个旋转，该数组的最小值为1。 NOTE：给出的所有元素都大于0，若数组大小为0，请返回0。*/
//二分查找思路，注意10111需要顺序查找，注意123需要直接返回1。
//二分查找思路，三个指针，如果中间元素大于等于第一个指针，则最小元素在其后，修第一个指针为中间指针；
//如果中间元素小于等于第二个指针，则最小元素在其前，修第二个指针为中间指针;
//最终第一个指针将指向前面子数组的最后，第二个指针将指向后面子数组的第一个，即指向相邻元素，而第二个指针即为最小值。
class Solution {
public:
    int sequenceSearch(const vector<int> &rotateArray, int start, int end)
    {
        int res=rotateArray[start];
        for(int i=start+1;i<=end;i++)
        {
            if(rotateArray[i]<res)
                res=rotateArray[i];
        }
        return res;
    }
    int minNumberInRotateArray(vector<int> rotateArray) {
        if(rotateArray.empty()) return 0;
        int res=0;
        int start=0;
        int end=rotateArray.size()-1;
        int mid=start;//初始化为开始，如果是12345，则应返回1
        while(rotateArray[start]>=rotateArray[end])
        {
            mid=(start+end)/2;
            if(end-start==1)
            {
                mid=end;//联合while条件
                break;
            }
            if(rotateArray[start]==rotateArray[end] && rotateArray[start]==rotateArray[mid])//处理10111
                return sequenceSearch(rotateArray,start,mid);
            if(rotateArray[mid]>=rotateArray[start])//处在前面。联合前面while条件
                start=mid;
            else if(rotateArray[mid]<=rotateArray[end])
                end=mid;
        }
        return rotateArray[mid];
    }
};
