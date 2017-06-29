/*
struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};*/
class Partition {
public:
    ListNode* partition(ListNode* pHead, int x) {
        // write code here
        if(pHead == NULL || pHead->next == NULL)    return pHead;
        // 使用两个dummy节点来表示大于等于x的链表和小于x的链表
        ListNode* dummy = new ListNode(0), *lower_dummy = new ListNode(0);
        ListNode* tmp = pHead, *upper = dummy, *lower = lower_dummy;
        while(tmp){
            ListNode* nxt = tmp->next;
            if(tmp->val < x){
                lower->next = tmp;
                lower = lower->next;
            }
            else{
                upper->next = tmp;
                upper = upper->next;
            }
            tmp = nxt;
        }
        // 千万一定要注意最后要把upper末尾指向NULL，不然内存超限
        lower->next = dummy->next;
        upper->next = NULL;
        return lower_dummy->next;
    }
};