/*
 * @lc app=leetcode id=139 lang=cpp
 *
 * [139] Word Break
 */

// @lc code=start
class Solution {
   public:
    bool wordBreak(string s, vector<string>& wordDict) {
        // "aaa aaa aaa" ["aaaaa", "aaa"]
        return wordBreakWithStart(s, 0, wordDict);
    }

    bool wordBreakWithStart(string s, int start, vector<string>& wordDict) {
        int sl = s.length();
        
        if (start == sl) return true;
        for (string word : wordDict) {
            int p = 0;
            int ws = word.length();
            while (p < ws && p + start < sl && word.at(p) == s.at(p + start)) p++;
            if (p == ws)
                if (wordBreakWithStart(s, start + ws, wordDict)) return true;
        }
        return false;
    }
};
// @lc code=end
