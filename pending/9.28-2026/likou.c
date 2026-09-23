#define _CRT_SECURE_NO_WARNINGS 
//P138
struct Node* copyRandomList(struct Node* head) {
    if (head == NULL) return NULL;

    // 1. 每个原节点后插入拷贝节点
    for (struct Node* cur = head; cur; cur = cur->next->next) {
        struct Node* node = (struct Node*)malloc(sizeof(struct Node));
        node->val = cur->val;
        node->next = cur->next;
        cur->next = node;
    }

    // 2. 设置拷贝节点的 random 指针
    for (struct Node* cur = head; cur; cur = cur->next->next) {
        if (cur->random != NULL)
            cur->next->random = cur->random->next;
    }

    // 3. 拆分两个链表，恢复原链表
    struct Node* newHead = head->next;
    for (struct Node* cur = head; cur; cur = cur->next) {
        struct Node* copy = cur->next;
        cur->next = copy->next;
        if (copy->next != NULL)
            copy->next = copy->next->next;
    }

    return newHead;
}