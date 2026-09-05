#define _CRT_SECURE_NO_WARNINGS 
struct ListNode* getIntersectionNode(struct ListNode* headA, struct ListNode* headB) {
    if (headA == NULL || headB == NULL) return NULL;
    struct ListNode* pa = headA, * pb = headB;
    while (pa != pb) {
        pa = (pa == NULL) ? headB : pa->next;
        pb = (pb == NULL) ? headA : pb->next;
    }
    return pa;
}