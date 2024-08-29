/*
 * @lc app=leetcode.cn id=19 lang=cpp
 *
 * [19] 删除链表的倒数第 N 个结点
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
    // 删除链表倒数第n的节点
    // 1. 快慢指针
    // 2. 链表删除 定位到要删除的前一个点
    // 3. 由于操作可能发生在head上，所以先声明一个dummy方便操作
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        auto dummy = new ListNode(-1, head);
        // 倒数第n个 需要定位到倒数第n+1个节点
        // 两次遍历或者快慢指针

        auto fast = dummy, slow = dummy;
        for(int i = 0; i <= n; ++i) {
            fast = fast->next;
        }
        while(fast) {
            fast = fast->next;
            slow = slow->next;
        }
        slow->next = slow->next->next;
        // 鴬圩有点内存泄漏 delete slow->next
        return dummy->next;
    }
};
// @lc code=end

