/*
 * @lc app=leetcode id=91 lang=cpp
 *
 * [91] Decode Ways
 */

// @lc code=start
class Solution {
   public:
    int numDecodings(string s) {
        int l = s.length();
        vector<int> type1(l, 0);
        if (s.at(0) > '0') type1.at(0) = 1;  // one char
        vector<int> type2(l, 0);

        for (int i = 1; i < l; i++) {
            // type 1
            int v = s.at(i);
            int pv = s.at(i - 1);
            if (v > '0')
                type1.at(i) = type1.at(i - 1) + type2.at(i - 1);
            // type 2
            if (pv == '1' || (pv == '2' && v <= '6'))
                type2.at(i) = (i == 1 ? 1 : type1.at(i - 2) + type2.at(i - 2));
        }
        return type1.at(l - 1) + type2.at(l - 1);
    }
};
// @lc code=end
