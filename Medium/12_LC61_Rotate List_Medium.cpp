#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;

    ListNode(int x) {
        val = x;
        next = nullptr;
    }
};

class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {

        if (head == nullptr || head->next == nullptr || k == 0) {
            return head;
        }

        // Find the length
        int len = 1;
        ListNode* curr = head;

        while (curr->next != nullptr) {
            curr = curr->next;
            len++;
        }


        k = k % len;

        if (k == 0) {
            return head;
        }


        curr->next = head;


        int steps = len - k;
        ListNode* newLast = head;

        for (int i = 1; i < steps; i++) {
            newLast = newLast->next;
        }


        ListNode* newHead = newLast->next;


        newLast->next = nullptr;

        return newHead;
    }
}
