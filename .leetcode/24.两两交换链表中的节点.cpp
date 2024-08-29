/*
 * @lc app=leetcode.cn id=24 lang=cpp
 *
 * [24] 两两交换链表中的节点
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
    ListNode* swapPairs(ListNode* head) {
        if(!head or !head->next) {
            return head;
        }
        auto dummy = new ListNode(-1, head);
        auto a = dummy;
        auto b = a->next, c = a->next->next;
        while(c) {
            auto d = c->next;
            c->next = b;
            a->next = c;
            b->next = d;

            a = b;
            b = a->next;
            if(b) {
                c = b->next;
            } else {
                break;
            }
        }

        return dummy->next;
    }
};
// @lc code=end

