/*请实现两个函数，分别用来序列化和反序列化二叉树*/
//序列化：char* Serialize(TreeNode *root)：前序遍历递归，先将根节点转为string（加个逗号），若为空则返回#，然后递归序列化左子char *left=Serialize(root->left);和右子，最后分配当前子树字符串大小char *currtree=new char[str.size()+strlen(left)+strlen(right)+1];将根strcpy，左右子树strcat，再返回根字符串指针。
//反序列化：TreeNode* Deserialize(char *str)：需要改变str指针向后遍历处理TreeNode* core(char *&str)，如果当前为#则后移str并返回空，否则while当其不为逗号时，将此字符串转为数字，str后移跨过逗号，然后构建new根节点，递归构建root->left=core(str)左右子树，返回根节点。
/*
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
    }
};
*/
class Solution {
public:
    char* Serialize(TreeNode *root) {
        if(!root) return "#";
        string str=to_string(root->val);
        str+=',';
        char *left=Serialize(root->left);
        char *right=Serialize(root->right);
        char *currtree=new char[str.size()+strlen(left)+strlen(right)+1];
        strcpy(currtree,str.c_str());
        strcat(currtree,left);
        strcat(currtree,right);
        return currtree;
    }
    
    TreeNode* core(char *&str) {//str指针需要往后移动
        if(*str == '#')
        {
            ++str;
            return nullptr;
        }
        int val=0;
        while(*str!=',')
        {
            val=val*10+(*str-'0');
            ++str;
        }
        ++str;
        TreeNode *root=new TreeNode(val);
        root->left=core(str);//递归返回到这里时，需要str已经后移到右子树处。若参数值复制，则这里str还是原值
        root->right=core(str);
        return root;
    }
    TreeNode* Deserialize(char *str) {
        if(!str) return nullptr;
        return core(str);
    }
};
