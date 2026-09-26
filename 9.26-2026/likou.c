#define _CRT_SECURE_NO_WARNINGS 
//P19
struct ListNode* removeNthFromEnd(struct ListNode* head, int n) {
    struct ListNode dummy;
    dummy.next = head;

    struct ListNode* fast = &dummy;
    struct ListNode* slow = &dummy;

    // fast 先走 n+1 步，使 slow 停在待删节点的前驱
    for (int i = 0; i <= n; i++) fast = fast->next;

    while (fast != NULL) {
        fast = fast->next;
        slow = slow->next;
    }

    struct ListNode* del = slow->next;
    slow->next = del->next;
    free(del);

    return dummy.next;
}