/*
 * @lc app=leetcode id=55 lang=cpp
 *
 * [55] Jump Game
 */

// @lc code=start
class Solution {
   public:
    bool canJump(vector<int>& nums) {
        int s = nums.size();
        nums.at(s - 1) = -1;
        for (int i = s - 2; i >= 0; i--) {
            int v = nums.at(i);
            for (int j = 1; j <= v; j++) {
                if (nums.at(i + j) == -1) {
                    nums.at(i) = -1;
                    break;
                }
            }
        }
        return (nums.at(0) == -1);
    }
};
// @lc code=end
