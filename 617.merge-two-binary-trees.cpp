/*
 * @lc app=leetcode id=617 lang=cpp
 *
 * [617] Merge Two Binary Trees
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
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        return mergeTreesStep(root1, root2);
    }

    TreeNode* mergeTreesStep(TreeNode* n1, TreeNode* n2) {
        //  n1     n2     nn
        //l1  rl l2  r2 ln  rn
        if (n1 == 0 && n2 == 0) return 0;
        int new_v = 0;
        if (n1 != 0) new_v += n1->val;
        if (n2 != 0) new_v += n2->val;
        return new TreeNode(
            new_v,
            mergeTreesStep(n1 != 0 ? n1->left : 0, n2 != 0 ? n2->left : 0),
            mergeTreesStep(n1 != 0 ? n1->right : 0, n2 != 0 ? n2->right : 0));
    }
};
// @lc code=end
