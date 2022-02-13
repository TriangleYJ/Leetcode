/*
 * @lc app=leetcode id=213 lang=cpp
 *
 * [213] House Robber II
 */

// @lc code=start
class Solution {
   public:
    int rob(vector<int>& nums) {
        int s = nums.size();

        if(s == 1) return nums.at(0);
        if(s == 2) return max(nums.at(0), nums.at(1));

        vector<vector<int>> dp(s, vector<int>(s, 0));
        for (int i = 0; i < s - 1; i++)
            dp.at(i).at(i + 1) = nums.at(i);
        for (int i = 0; i < s - 2; i++)
            dp.at(i).at(i + 2) = max(nums.at(i), nums.at(i + 1));
        for (int k = 3; k < s; k++) {
            for (int i = 0; i < s - k; i++) {
                dp.at(i).at(i + k) =
                    nums.at(i) +
                    max(dp.at(i + 2).at(i + k), dp.at(i + 3).at(i + k));
            }
        }

        int case1 = dp.at(1).at(s-1);
        int case2 = dp.at(0).at(s-1);
        int case3 = max(dp.at(1).at(s-2), dp.at(2).at(s-2)) + nums.at(s-1);
        return max(max(case1, case2), case3);

    }
};
// @lc code=end
