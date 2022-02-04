/*
 * @lc app=leetcode id=713 lang=cpp
 *
 * [713] Subarray Product Less Than K
 */

// @lc code=start
class Solution {
   public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int l = 0, r = 0, acc = 0, result = 0;
        int tmp = nums.at(0);  // size >= 1

        while (1) {
            if (tmp < k) {
                result += ++acc;
                if (r == nums.size() - 1) break;
                tmp *= nums.at(++r);
            } else {
                if (l == nums.size() - 1) break;
                if (acc == 0) {
                    tmp = nums.at(++l);
                    ++r;
                } else {
                    tmp /= nums.at(l++);
                    acc--;
                }
            }
        }

        return result;
    }
};
// @lc code=end
