#define _CRT_SECURE_NO_WARNINGS 
struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2) {
    struct ListNode dummy = { 0, NULL }, * tail = &dummy;
    while (l1 && l2) {
        if (l1->val < l2->val)
            tail = tail->next = l1, l1 = l1->next;
        else
            tail = tail->next = l2, l2 = l2->next;
    }
    tail->next = l1 ? l1 : l2;
    return dummy.next;
}
//第二版
struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2) {
    if (!l1) return l2;
    if (!l2) return l1;
    if (l1->val < l2->val) {
        l1->next = mergeTwoLists(l1->next, l2);
        return l1;
    }
    else {
        l2->next = mergeTwoLists(l1, l2->next);
        return l2;
    }
}