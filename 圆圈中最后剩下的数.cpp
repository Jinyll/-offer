/*随机指定一个数m,让编号为0的小朋友开始报数。每次喊到m-1的那个小朋友要出列,并且不再回到圈中,
从他的下一个小朋友开始,继续0...m-1报数....这样下去....直到剩下最后一个小朋友，返回最后一个的编号*/
//用list，注意遍历或删除时如果下一个是end则需要赋值begin，以形成循环
//优化解法 递推公式
class Solution {
public:
    //常规解法用list Omn时间 On空间
    int LastRemaining_Solution(int n, int m)
    {
        if(n<=0 || m<=0) return -1;
        list<int> l;
        for(int i=0;i<n;i++) l.push_back(i);
        list<int>::iterator it=l.begin();
        while(l.size()>1)
        {
            for(int i=1;i<m;i++)//it指向m-1
            {
                 ++it;
                if(it==l.end()) it=l.begin();//形成循环链表
            }
            it=l.erase(it);
            if(it==l.end()) it=l.begin();
        }
        return l.front();
    }
    
    //递归公式：f(n,m)=0(n=1)或[f(n-1,m)+m]%n (n>1)。 要得到n个数字中最后剩下的只需得到n-1中最后剩下的，类推到只有一个数字0
    //时间On，空间O1
    int LastRemaining_Solution(int n, int m)
    {
        if(n<=0 || m<=0) return -1;
        int last=0;
        for(int i=0;i<=n;i++) last=(last+m)%i;
        return last;
    }
};
