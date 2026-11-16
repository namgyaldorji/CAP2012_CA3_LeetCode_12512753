#include <iostream>
#include <vector>
#include <queue>
#include <functional>
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
    ListNode* mergeKLists(vector<ListNode*>& lists) {

        priority_queue<int, vector<int>, greater<int>> pq;

        for (int i = 0; i < lists.size(); i++) {
            ListNode* curr = lists[i];

            while (curr != nullptr) {
                pq.push(curr->val);
                curr = curr->next;
            }
        }


        ListNode* dummy = new ListNode(0);
        ListNode* tail = dummy;

        while (!pq.empty()) {
            tail->next = new ListNode(pq.top());
            pq.pop();

            tail = tail->next;
        }

        return dummy->next;
    }
}
