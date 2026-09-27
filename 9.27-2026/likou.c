#define _CRT_SECURE_NO_WARNINGS 
//P24
struct ListNode* swapPairs(struct ListNode* head) {
    struct ListNode dummy;
    dummy.next = head;
    struct ListNode* cur = &dummy;

    while (cur->next && cur->next->next) {
        struct ListNode* p = cur->next;
        struct ListNode* q = p->next;

        p->next = q->next;
        q->next = p;
        cur->next = q;

        cur = p;
    }

    return dummy.next;
}