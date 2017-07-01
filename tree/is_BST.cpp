/*
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
    }
};*/

class Checker {
private:
    vector<int> _vec;
    // 先用dfs中序遍历得到二叉树的中序遍历序列
    void dfs(TreeNode* root){
        if(root == NULL)    return;
        dfs(root->left);
        _vec.push_back(root->val);
        dfs(root->right);
    }
public:
    bool checkBST(TreeNode* root) {
        // write code here
        if(root == NULL)    return true;
        dfs(root);
        // 判断得到的序列是不是一个递增序列
        for(int i=0;i<(int)_vec.size()-1;i++)   if(_vec[i]>_vec[i+1])   return false;
        return true;
    }
};