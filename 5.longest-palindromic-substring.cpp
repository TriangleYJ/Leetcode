/*
 * @lc app=leetcode id=5 lang=cpp
 *
 * [5] Longest Palindromic Substring
 */

// @lc code=start
class Solution {
   public:
    string longestPalindrome(string s) {
        int l = s.length();
        int mmax = 1;
        int mmax_srt = 0;

        vector<vector<int>> dp(2, vector<int>(l, 0));

        for (int i = 0; i < l; i++) {
            dp.at(0).at(i) = 1;  // dp.at(i).at(i)
        }

        for (int i = 0; i < l - 1; i++) {
            if (s.at(i) == s.at(i + 1)) {
                dp.at(1).at(i) = 2;  // dp.at(i).at(i+1)
                mmax = 2;
                mmax_srt = i;
            }
        }

        for (int k = 2; k < l; k++) {
            for (int i = 0; i < l - k; i++) {
                int prev_val = dp.at(k % 2).at(i + 1);  // dp.at(i + 1).at(i + k - 1);
                if (prev_val != 0 && s.at(i) == s.at(i + k)) {
                    dp.at(k % 2).at(i) = prev_val + 2;  // dp.at(i).at(i + k) = prev_val + 2;
                    if (mmax < prev_val + 2) {
                        mmax = prev_val + 2;
                        mmax_srt = i;
                    }
                } else
                    dp.at(k % 2).at(i) = 0;
            }
        }

        return s.substr(mmax_srt, mmax);
    }
};
// @lc code=end
