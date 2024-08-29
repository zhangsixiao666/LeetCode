/*
 * @lc app=leetcode.cn id=23 lang=cpp
 *
 * [23] 合并 K 个升序链表
 */

// @lc code=start
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
    // merget sort
    // elegant
    // O（nmlogn)
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        auto cmp = [](ListNode* l1, ListNode* l2) {
            return l1->val > l2->val;
        };
        priority_queue<ListNode*, vector<ListNode*>, decltype(cmp)> pq(cmp);


        for(const auto l : lists) {
            if(l)
                pq.push(l);
        }
        auto dummy = new ListNode(-1);
        auto cur = dummy;
        while(pq.size()) {
            auto t = pq.top();
            pq.pop();
            cur = cur->next = t;
            t = t->next;
            if(t) {
                pq.push(t);
            }
        }

        return dummy->next;
    }
};
// @lc code=end

