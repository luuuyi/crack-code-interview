/*
struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};*/
class Remove {
public:
    bool removeNode(ListNode* pNode) {
        // write code here
        if(pNode == NULL || pNode->next == NULL)    return false;
        pNode->val = pNode->next->val;
        pNode->next = pNode->next->next;
        return true;
    }
};