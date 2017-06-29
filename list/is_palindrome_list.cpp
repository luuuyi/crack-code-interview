/*
struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};*/
class Palindrome {
public:
    bool isPalindrome(ListNode* pHead) {
        // write code here
        if(pHead == NULL || pHead->next == NULL)    return true;
        stack<ListNode*> que;
        ListNode* tmp = pHead;
        while(tmp){
            que.push(tmp);
            tmp = tmp->next;
        }
        tmp = pHead;
        while(!que.empty()){
            if(que.top()->val != tmp->val)    return false;
            que.pop(); tmp = tmp->next;
        }
        return true;
    }
};