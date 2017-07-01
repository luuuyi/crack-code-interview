/*
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
    }
};*/

/*
struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};*/
class TreeLevel {
private:
    ListNode* dummy, *tmp;
    // dfs方法遍历树中的每一个节点，找到合适的放入链表
    void dfs(TreeNode* root, int dep, int cur){
        if(root == NULL)    return;
        if(cur == dep){
            ListNode *p = new ListNode(root->val);
            tmp->next = p; tmp = tmp->next;
        }
        dfs(root->left, dep, cur+1);
        dfs(root->right, dep, cur+1);
        return;
    }
public:
    ListNode* getTreeLevel(TreeNode* root, int dep) {
        // write code here
        if(root == NULL || dep == 0)    return NULL;
        dummy = new ListNode(0);
        // 第一层为根节点
        tmp = dummy; int cur = 1;
        dfs(root, dep, cur);
        return dummy->next;
    }
};