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
class Converter {
private:
    // 外部使用一个额外的变量
    ListNode* tmp;
    // 使用中序遍历的递归方式去做
    void middleOrder(TreeNode* root){
        if(root == NULL)    return;
        middleOrder(root->left);
        tmp->next = new ListNode(root->val);
        tmp = tmp->next;
        middleOrder(root->right);
        return;
    }
public:
    // 和以前遇到的树转双链表不太一样，这道题用递归的方式去做即可
    // 每一次都新建一个链表的节点对象来存储结果
    ListNode* treeToList(TreeNode* root) {
        // write code here
        ListNode* dummy = new ListNode(-1);
        tmp = dummy;
        middleOrder(root);
        return dummy->next;
    }
};