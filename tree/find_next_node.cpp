/*
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
    }
};*/

class Successor {
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
    int findSucc(TreeNode* root, int p) {
        // write code here
        if(root == NULL)    return -1;
        dfs(root);
        int i = 0;
        // 老套路，找下一个即可
        for(;i<(int)_vec.size();i++) if(_vec[i] == p)    break;
        i++;
        return i>=(int)_vec.size()?-1:_vec[i];
    }
};