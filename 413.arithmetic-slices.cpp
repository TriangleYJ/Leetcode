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
        int cnt = 0;
        if (s < 3) return 0;
        int srt = 0;
        int end = 2;
        int d = 0;
        while (end < s) {
            if (end - srt == 2) {
                int a = nums.at(srt);
                int b = nums.at(srt + 1);
                int c = nums.at(end);
                if (a + c == 2 * b) {
                    d = (b - a);
                    cnt++;
                    end++;
                } else {
                    srt++;
                    end++;
                }
            } else if (end - srt > 2) {
                int prev = nums.at(end - 1);
                int cur = nums.at(end);
                if (cur - prev == d) {
                    cnt += (end - srt - 1);
                    end++;
                } else
                    srt = end - 2;
            }
        }
        return cnt;
    }
};
// @lc code=end
