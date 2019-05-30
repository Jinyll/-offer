/*大小王为0，可代替任意数*/
//统计0的数量，间隙数量，最后比较。需注意如果链各个数相等（扑克牌中每个值有4个），则不是顺子
class Solution {
public:
    bool IsContinuous( vector<int> numbers ) {
        if(numbers.empty())
            return false;
        sort(numbers.begin(),numbers.end());
        int numsof0=0;
        for(int i=0;i<numbers.size();i++)//统计0的数量
        {
            if(numbers[i]==0)
                numsof0++;
        }
        int numsofgap=0;
        int small=numsof0;//第一个非0的下标
        int big=small+1;
        while(big<numbers.size())
        {//两个指针移动，统计两数间的间隙数量
            if(numbers[small]==numbers[big])//判断是否有相同元素，有则不是顺子
                return false;
            numsofgap+=numbers[big]-numbers[small]-1;
            small++;
            big++;
        }
        return numsofgap>numsof0?false:true;
    }
};
