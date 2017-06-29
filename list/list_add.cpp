/*
struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};*/
class Plus {
public:
    ListNode* plusAB(ListNode* a, ListNode* b) {
        // write code here
        if(b == NULL)   return a;
        // 很简单，直接按节点来相加，然后添加到新的链表里面去就行了
        ListNode* dummy = new ListNode(0);
        ListNode* a_tmp = a, *b_tmp = b, *tmp = dummy;
        int forward = 0;
        // 要注意的是进位也要放入考虑范围内
        while(a_tmp || b_tmp || forward){
            ListNode* cur = new ListNode(0);
            cur->val = (a_tmp==NULL?0:a_tmp->val) + (b_tmp==NULL?0:b_tmp->val) + forward;
            forward = cur->val / 10;
            cur->val %= 10;
            tmp->next = cur; tmp = tmp->next;
            if(a_tmp)   a_tmp = a_tmp->next;
            if(b_tmp)   b_tmp = b_tmp->next;
        }
        return dummy->next;
    }
};