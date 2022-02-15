/*
 * @lc app=leetcode id=139 lang=cpp
 *
 * [139] Word Break
 */

// @lc code=start
class Solution {
   public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int sl = s.length();
        // aaaaaaaaaaaaaaaa ["a", "aa", "aaa", "aaaa"]
        queue<int> candidates;
        vector<bool> reached(sl + 1, false);
        candidates.push(0);
        reached.at(0) = true;
        while (!candidates.empty()) {
            int start = candidates.front();
            candidates.pop();
            for (string word : wordDict) {
                int p = 0;
                int ws = word.length();
                while (p < ws && p + start < sl && word.at(p) == s.at(p + start)) p++;
                if (p == ws) {
                    if (!reached.at(p + start)) {
                        reached.at(p + start) = true;
                        candidates.push(p + start);
                    }
                }
            }
        }

        return reached.at(sl);
    }
};
// @lc code=end
