struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    int s1[101], s2[101], t1 = 0, t2 = 0;
    while (l1) { s1[t1++] = l1->val; l1 = l1->next; }
    while (l2) { s2[t2++] = l2->val; l2 = l2->next; }

    struct ListNode* head = NULL;
    int carry = 0;
    while (t1 || t2 || carry) {
        int sum = carry;
        if (t1) sum += s1[--t1];
        if (t2) sum += s2[--t2];
        carry = sum / 10;
        struct ListNode* node = malloc(sizeof(struct ListNode));
        node->val = sum % 10;
        node->next = head;   /* 头插法，保证高位在前 */
        head = node;
    }
    return head;
}
#define _CRT_SECURE_NO_WARNINGS 