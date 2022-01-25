/*
 * @lc app=leetcode id=70 lang=cpp
 *
 * [70] Climbing Stairs
 */

// @lc code=start
class Solution {
   private:
    int answers[46] = {0};

   public:
    int climbStairs(int n) {
        answers[1] = 1;
        answers[2] = 2;
        for (int i = 3; i <= n; i++) answers[i] = answers[i - 1] + answers[i - 2];
        return answers[n];
    }
};
// @lc code=end
