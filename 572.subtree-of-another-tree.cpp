/*
 * @lc app=leetcode id=572 lang=cpp
 *
 * [572] Subtree of Another Tree
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(isEqualtree(root, subRoot)) return true;
        if(root && isSubtree(root->left, subRoot)) return true;
        if(root && isSubtree(root->right, subRoot)) return true;
        return false;
    }

    bool isEqualtree(TreeNode* root, TreeNode* subRoot){
        if(!root && !subRoot) return true;
        if(!root || !subRoot) return false;
        if(root->val != subRoot -> val) return false;
        if(!isEqualtree(root->left, subRoot->left)) return false;
        if(!isEqualtree(root->right, subRoot->right)) return false;
        return true;
    }
};
// @lc code=end

