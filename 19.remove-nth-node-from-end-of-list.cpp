/*
 * @lc app=leetcode id=19 lang=cpp
 *
 * [19] Remove Nth Node From End of List
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* tortoise = head;
        int idx = 0;
        for(ListNode* hair = head; hair != nullptr; hair = hair -> next){
            // start traversing lately until tortoise become prev node of target
            if(idx > n) tortoise = tortoise -> next;
            idx++;
        }
        // exception case: remove first node
        if(idx == n) return head -> next;
        else{
            ListNode* target = tortoise -> next;
            tortoise -> next = target -> next;
            return head;
        }
    }
};
// @lc code=end

