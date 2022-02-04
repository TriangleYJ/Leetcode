/*
 * @lc app=leetcode id=82 lang=cpp
 *
 * [82] Remove Duplicates from Sorted List II
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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* candidate = nullptr;
        ListNode* new_head = nullptr;
        ListNode* new_tail = nullptr;
        int dup_num = -1;
        ListNode* l = head; 

        while(1) {
            if(!candidate || !l || candidate->val != l->val){
                if(dup_num == 0){
                    if(!new_head){
                        new_head = new ListNode(candidate->val);
                        new_tail = new_head;
                    } else {
                        new_tail -> next = new ListNode(candidate->val);
                        new_tail = new_tail -> next;
                    }
                }
                if(!l) break;
                dup_num = 0;
                candidate = l;
            } else dup_num++;
            l = l->next;    
        }
        return new_head;
    }
};
// @lc code=end

