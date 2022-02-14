/*
 * @lc app=leetcode id=413 lang=cpp
 *
 * [413] Arithmetic Slices
 */

// @lc code=start
class Solution {
   public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int s = nums.size();
        if (s < 3) return 0;
        vector<int> dp(s - 2, 0);
        int cnt = 0;
        for (int i = 0; i < s - 2; i++) {
            int a = nums.at(i);
            int b = nums.at(i + 1);
            int c = nums.at(i + 2);
            if (a + c == 2 * b) {
                dp.at(i) = 1;  // dp.at(i).at(i + 2) = 1;
                cnt++;
            }
        }

        for (int k = 3; k < s; k++) {
            for (int i = 0; i < s - k; i++) {
                int d1 = dp.at(i);      // dp.at(i).at(i + k - 1);
                int d2 = dp.at(i + 1);  // dp.at(i + 1).at(i + k);
                if (d1 && d2) {
                    dp.at(i) = 1;  // dp.at(i).at(i + k) = 1;
                    cnt++;
                } else
                    dp.at(i) = 0;
            }
        }

        return cnt;
    }
};
// @lc code=end
