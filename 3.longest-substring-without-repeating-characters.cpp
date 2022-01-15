/*
 * @lc app=leetcode id=3 lang=cpp
 *
 * [3] Longest Substring Without Repeating Characters
 */

// @lc code=start
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int srt = 0;
        int mmap[128] = {0};
        int end = 0;
        int mmax = 0;
        int cur_len = 0;
        while(end < s.length()){
            while(end < s.length() && mmap[s.at(end)] == 0){
                mmap[s.at(end)]++;
                end++;
                cur_len++;
            }
            if(cur_len > mmax) mmax = cur_len;

            // move window to left
            mmap[s.at(srt)]--;
            cur_len--;
            srt++;
        }

        return mmax;
    }
};
// @lc code=end

