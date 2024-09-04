/*
 * @lc app=leetcode.cn id=92 lang=cpp
 *
 * [92] 反转链表 II
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
  ListNode *reverseBetween(ListNode *head, int left, int right) {
    auto dummy = new ListNode(-1, head);
    auto cur = dummy;

    for (int i = 1; i < left; ++i) {
      cur = cur->next;
    }

    auto a = cur->next;
    auto b = cur->next->next;

    for (int i = left; i < right; ++i) {
      auto c = b->next;
      b->next = a;
      a = b;
      b = c;
    }

    cur->next->next = b;
    cur->next = a;

    return dummy->next;
  }
};
// @lc code=end
