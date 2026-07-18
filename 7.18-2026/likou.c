#define _CRT_SECURE_NO_WARNINGS 
struct ListNode* reverseList(struct ListNode* head) {
    struct ListNode* prev = NULL, * cur = head;
    while (cur) {
        struct ListNode* next = cur->next;
        cur->next = prev;
        prev = cur;
        cur = next;
    }
    return prev;
}
//递归法
struct ListNode* reverseList(struct ListNode* head) {
    if (!head || !head->next) return head;
    struct ListNode* newHead = reverseList(head->next);
    head->next->next = head;
    head->next = NULL;
    return newHead;
}