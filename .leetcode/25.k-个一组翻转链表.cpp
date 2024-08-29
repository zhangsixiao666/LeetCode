/*
 * @lc app=leetcode.cn id=25 lang=cpp
 *
 * [25] K 个一组翻转链表
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
  ListNode *reverseKGroup(ListNode *head, int k) {
    if(!head or !head->next or k==1){
        return head;
    }
    auto dummy = new ListNode(-1, head);

    auto cur = dummy;
    while(cur) {
        auto p = cur;
        for(int i = 0; i < k and p; ++i) {
             p = p->next;
        }
        if(!p){
            break;
        }
        auto a = cur->next;
        auto b = a->next;
        for(int i = 0; i < k - 1; ++i) {
            auto c = b->next;
            b->next = a;
            a = b;
            b = c;
        }
        
        auto t = cur->next;
        cur->next = a;
        t->next = b;
        cur = t;
    }

    return dummy->next;
  }
};
// @lc code=end
