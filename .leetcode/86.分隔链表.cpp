/*
 * @lc app=leetcode.cn id=86 lang=cpp
 *
 * [86] 分隔链表
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
    ListNode* partition(ListNode* head, int x) {
        auto less = new ListNode(-1);
        auto more = new ListNode(-1);
        auto p = less, q = more;
        while(head) {
            if(head->val < x) {
                p = p->next = new ListNode(head->val);
            } else {
                q = q->next = new ListNode(head->val);
            }
            head = head->next;
        }
        p->next = more->next;

        return less->next;     
    }
};
// @lc code=end

