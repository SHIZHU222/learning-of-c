#define _CRT_SECURE_NO_WARNINGS 
class Solution {
public:
    ListNode* reverse(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* curr = head;
        while (curr) {
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }

    bool isPalindrome(ListNode* head) {
        if (!head || !head->next) return true;

        ListNode* slow = head, * fast = head;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode* second = reverse(slow);

        ListNode* p1 = head, * p2 = second;
        bool ok = true;
        while (p2) {
            if (p1->val != p2->val) { ok = false; break; }
            p1 = p1->next;
            p2 = p2->next;
        }

        return ok;
    }
}