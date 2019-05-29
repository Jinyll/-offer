/*数组中有一个数字出现的次数超过数组长度的一半，请找出这个数字。
例如输入一个长度为9的数组{1,2,3,2,2,2,5,4,2}。由于数字2在数组中出现了5次，超过数组长度的一半，因此输出2。如果不存在则输出0。*/
//方法1 遍历数组保存两个值，一个是数组中数字，一个是次数，遍历到下一个数字时，如果相等，次数加1，如果不相等，次数-1，如果次数为0，保存下一个数字并重设次数为1
//      由于要找的数字出现次数比其他所有数字出现次数和还要多，所有【最后一次把次数设置为1的数字】即为要找的数字。
//      最后还需检查该值是否出现次数超过一半，应对123
class Solution {
public:
    int MoreThanHalfNum_Solution(vector<int> numbers) {
        if(numbers.empty()) return 0;
        int result=numbers[0];
        int times=1;
        for(int i=1;i<numbers.size();i++)
        {
            if(numbers[i]!=result)
            {
                --times;
                if(times==0)
                {
                    result=numbers[i];
                    times=1;
                }
            }
            else ++times;
        }
        int count=0;
        for(int i=0;i<numbers.size();i++)
        {
            if(numbers[i]==result) ++count;
        }
        if(count*2>numbers.size()) return result;
        else return 0;
    }
};

//方法2
class Solution {
public:
int partition(vector<int> &numbers, int start, int end)
{
	int mid = (start + end) / 2;
	int small = start - 1;
	for (int index = start; index < end; index++)
	{
		if (numbers[index] < numbers[end])
		{
			++small;
			if (small != index)
				swap(numbers[small], numbers[index]);
		}
	}
	++small;
	swap(numbers[small], numbers[end]);
	return small;
}

int MoreThanHalfNum_Solution(vector<int> numbers) {
	if (numbers.empty()) return 0;
	int start = 0;
	int end = numbers.size() - 1;
	int index = partition(numbers, start, end);
	int mid = (start + end) / 2;
	while (index != mid)//partition利用On时间得到第k大的数，此处得到中位数。
	{
		if (index > mid)
		{
			end = index - 1;
			index = partition(numbers, start, end);
		}
		else
		{
			start = index + 1;
			index = partition(numbers, start, end);
		}
	}
	int result = numbers[mid];//如果有出现次数超过一半的数字，则中位数即为该值。
	//验证该值是否出现次数超过一半
	int count = 0;
	for (int i = 0; i < numbers.size(); i++)
	{
		if (numbers[i] == result) ++count;
	}
	if (count * 2 > numbers.size()) return result;
	else return 0;
}
};
