/*
 * @lc app=leetcode id=876 lang=cpp
 *
 * [876] Middle of the Linked List
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
    ListNode* middleNode(ListNode* head) {
        ListNode* tortoise = head;
        int len = 0;
        // 1 2 2 3 3 ..
        for(ListNode* hare = head; hare != nullptr; hare = hare->next){
            if(len % 2 == 1) tortoise = tortoise->next;
            len++;
        }
        return tortoise;
    }
};
// @lc code=end

