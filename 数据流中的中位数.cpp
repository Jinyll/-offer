/*如何得到一个数据流中的中位数？如果从数据流中读出奇数个数值，那么中位数就是所有数值排序之后位于中间的数值。
如果从数据流中读出偶数个数值，那么中位数就是所有数值排序之后中间两个数的平均值。
我们使用Insert()方法读取数据流，使用GetMedian()方法获取当前读取数据的中位数。*/

//一个最大堆，一个最小堆，各存储一半数据，最大堆的数据都小于最小堆的数据
//当前共有偶数个数字时，往最小堆插，若最大堆有值且当前数字小于最大堆头，则需要将当前数字插入最大堆，并将最大堆头删除并插入最小堆。保证最小堆都大于最大堆
//当前共有奇数个数字，往最大堆插，若最小堆有值且当前数字大于最小堆头，则需要将当前数字插入最小堆，并将最小堆头删除并插入最大堆
//当前偶数个数字，从最小堆头读取；奇数个，则取两个堆头平均
class Solution {
public:
    void Insert(int num)
    {
        if(((max.size()+min.size()) & 0x1) == 0)
        {
            if(max.size()>0 && num<max[0])
            {
                max.push_back(num);
                push_heap(max.begin(),max.end());
                num=max[0];
                pop_heap(max.begin(),max.end());
                max.pop_back();
            }
            min.push_back(num);
            push_heap(min.begin(),min.end(),greater<>());
        }
        else
        {
            if(min.size()>0 && num>min[0])
            {
                min.push_back(num);
                push_heap(min.begin(),min.end(),greater<>());
                num=min[0];
                pop_heap(min.begin(),min.end(),greater<>());
                min.pop_back();
            }
            max.push_back(num);
            push_heap(max.begin(),max.end());
        }
    }

    double GetMedian()
    { 
        if(max.size()+min.size()==0) return -1;
        if(((max.size()+min.size()) & 0x1) == 1) return min[0];
        else return double(min[0]+max[0])/2;
    }
private:
    vector<int> max;
    vector<int> min;//偶数个，先插入最小堆
};
