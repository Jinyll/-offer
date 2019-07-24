/*在一个长度为n的数组里的所有数字都在0到n-1的范围内。 数组中某些数字是重复的，但不知道有几个数字是重复的。也不知道每个数字重复几次。
请找出数组中任意一个重复的数字。 例如，如果输入长度为7的数组{2,3,1,0,2,5,3}，那么对应的输出是第一个重复的数字2。*/
//哈希表 数组中数字为下标
class Solution {
public:
    // Parameters:
    //        numbers:     an array of integers
    //        length:      the length of array numbers
    //        duplication: (Output) the duplicated number in the array number
    // Return value:       true if the input is valid, and there are some duplications in the array number
    //                     otherwise false
    bool duplicate(int numbers[], int length, int* duplication) {
        if(!numbers || length<=0) return false;
        vector<bool> hashtable(length,false);
        for(int i=0;i<length;i++)
        {
            if(hashtable[numbers[i]]==false) hashtable[numbers[i]]=true;
            else 
            {
                *duplication=numbers[i];
                return true;
            }
        }
        return false;
    }
};


数字范围0-n-1，如果没有重复数字，则数组排序后，数字i将出现在下标为i的位置，如果有重复数字，则有些位置会存在多个数字。
扫描数组，当扫描到下标i时，比较下标i是否等于数字v[i]，（1）如果相等则扫描下一个数字，（2）如果不等于，则比较v[i]与下标v[i]处的数字，（2.1）如果相等，则找到一个重复数字v[i]，（2.2）如果不相等，则交换，将v[i]放到下标v[i]处。重复该过程，直到发现一个重复数字。
差方法：排序时间Onlogn，哈希表空间On
bool duplicate(int numbers[], int length, int* duplication)
{
	if (numbers == nullptr || length <= 0) return false;
	for (int i = 0; i < length; i++)
	{
		if (numbers[i]<0 || numbers[i]>length - 1) return false; //数字范围是0 - n-1
	}
	for (int i = 0; i < length; i++)
	{
		while (numbers[i] != i)
		{
			if (numbers[i] == numbers[numbers[i]])
			{
				*duplication = numbers[i];
				return true;
			}
			swap(numbers[i], numbers[numbers[i]]); //让numbers[i]位置的值是numbers[i]
		}
	}
	return false;
}
