/*请设计一个函数，用来判断在一个矩阵中是否存在一条包含某字符串所有字符的路径。
路径可以从矩阵中的任意一个格子开始，每一步可以在矩阵中向左，向右，向上，向下移动一个格子
。如果一条路径经过了矩阵中的某一个格子，则之后不能再次进入这个格子。 
例如 a b c e s f c s a d e e 这样的3 X 4 矩阵中包含一条字符串"bcced"的路径，但是矩阵中不包含"abcb"路径，
因为字符串的第一个字符b占据了矩阵中的第一行第二个格子之后，路径不能再次进入该格子。*/

//递归遍历每一个元素，设置一个是否访问过的数组标识visited，对每个匹配当前路径的元素往四个方向递归。一个int标识已经访问到路径的下标
//（1）如果已经到达目标路径结束处，则返回正确
//（2）当前元素的坐标未出界且和当前str相同且没访问过，则访问当前元素，通过pathlength后移目标路径下标，并递归尝试四个方向
//（2.1）如果都不对，则通过当前元素不会匹配路径，设置未访问当前元素，目标路径下标前移，返回错误；
//（2.2）否则返回正确（3）否则如果当前元素不匹配或出界返回错误
class Solution {
public:
    bool PathCore(char* matrix, int row, int rows, int col, int cols, int& pathLength, char* str, bool* visited){
        if(str[pathLength]=='\0')
            return true;
        bool hasPath=false;
        if(row<rows && row>=0 && col<cols && col>=0 && str[pathLength]==matrix[row*cols+col] && !visited[row*cols+col]){
            visited[row*cols+col]=true;
            ++pathLength;
            hasPath=PathCore(matrix, row+1, rows, col, cols, pathLength, str, visited)
                || PathCore(matrix, row-1, rows, col, cols, pathLength, str, visited)
                || PathCore(matrix, row, rows, col+1, cols, pathLength, str, visited)
                || PathCore(matrix, row, rows, col-1, cols, pathLength, str, visited);//过程中会更新length和visited
            if(!hasPath){
                visited[row*cols+col]=false;//此路不通回溯时候需要把访问过不通的地方置回
                --pathLength;
            }
        }
        return hasPath;
    }
     
    bool hasPath(char* matrix, int rows, int cols, char* str)
    {
        if(matrix==nullptr || rows<=0 || cols<=0 || str==nullptr)
            return false;
        bool* visited=new bool[rows*cols];
        memset(visited, 0, rows*cols);//存储已经访问过的格子
        int pathLength=0;
        for(int row=0; row<rows; row++){
            for(int col=0; col<cols; col++){
                if(PathCore(matrix, row, rows, col, cols, pathLength, str, visited))
                    return true;
            }
        }
        return false;
    }
};
