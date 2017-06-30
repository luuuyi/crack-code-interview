/*
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
    }
};*/

class Balance {
private:
    // 递归的查找树的高度，然后判断是否是平衡的即可
    bool _res = true;
    int getHeightAndResult(TreeNode* root){
        if(root == NULL)    return 0;
        int left = getHeightAndResult(root->left);
        int right = getHeightAndResult(root->right);
        _res &= (abs(left-right) <= 1);
        return left>right?left+1:right+1;
    }
public:
    bool isBalance(TreeNode* root) {
        // write code here
        if(root == NULL)    return true;
        int h = getHeightAndResult(root);
        return _res;
    }
};