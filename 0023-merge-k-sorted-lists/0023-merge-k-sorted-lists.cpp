/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
    priority_queue<pair<int,ListNode*>,vector<pair<int,ListNode*>>,greater<pair<int,ListNode*>>> pq;

    for (ListNode* i : lists) {
        if (i) pq.push({i->val, i});
    }

    ListNode *head = NULL, *tail = NULL;

    while (!pq.empty()) {
        auto curr = pq.top();
        pq.pop();

        ListNode* nd = new ListNode(curr.first);

        if (curr.second->next)
            pq.push({curr.second->next->val, curr.second->next});

        if (!head) head = tail = nd;
        else tail->next = nd, tail = nd;
    }
    return head;
    }
};