struct ListNode* reverseList(struct ListNode* head) {
    struct ListNode* prev = NULL, * curr = head;
    while (curr != NULL) {
        struct ListNode* next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}
#define _CRT_SECURE_NO_WARNINGS 