/*地上有一个m行和n列的方格。一个机器人从坐标0,0的格子开始移动，每一次只能向左，右，上，下四个方向移动一格，
但是不能进入行坐标和列坐标的数位之和大于k的格子。 例如，当k为18时，机器人能够进入方格（35,37），因为3+5+3+7 = 18。
但是，它不能进入方格（35,38），因为3+5+3+8 = 19。请问该机器人能够达到多少个格子？*/
//递归处理四个方向，visited存储是否判断过是否可进入。如果坐标未过界，且坐标和不大于限制，且未访问过，则能到到达该坐标，count=1+四个方向递归求和
class Solution {
public:
    int getsum(int row, int col)
    {
        int sum=0;
        while(row)
        {
            sum+=row%10;
            row/=10;
        }
        while(col)
        {
            sum+=col%10;
            col/=10;
        }
        return sum;
    }
    int core(int threshold, int rows, int cols, int row, int col, bool *visited)
    {
        int count=0;
        if(row>=0 && row<rows && col>=0 && col<=cols && !visited[row*cols+col] && getsum(row,col)<=threshold)
        {
            visited[row*cols+col]=true;
            count=1+core(threshold,rows,cols,row+1,col,visited)
            +core(threshold,rows,cols,row-1,col,visited)
            +core(threshold,rows,cols,row,col+1,visited)
            +core(threshold,rows,cols,row,col-1,visited);
        }
        return count;
    }
    int movingCount(int threshold, int rows, int cols)
    {
        if(threshold<0 || rows<=0 || cols<=0) return 0;
        bool *visited=new bool[rows*cols];
        for(int i=0;i<rows*cols;i++) visited[i]=false;
        int count = core(threshold,rows,cols,0,0,visited);
        delete[] visited;
        visited=nullptr;
        return count;
    }
};
