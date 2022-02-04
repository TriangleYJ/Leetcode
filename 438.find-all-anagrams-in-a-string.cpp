/*
 * @lc app=leetcode id=438 lang=cpp
 *
 * [438] Find All Anagrams in a String
 */

// @lc code=start
class Solution {
   public:
    vector<int> findAnagrams(string s, string p) {
        const int sl = s.length();
        const int pl = p.length();
        if (sl < pl) return {};
        int mmap[26] = {0};
        int zero_num = 26;
        vector<int> result;
        
        // initalize
        for (char c : p) {
            if (mmap[c - 'a']++ == 0) zero_num--;
        }
        for (int j = 0; j < p.length(); j++) {
            if (--mmap[s.at(j) - 'a'] == 0)
                zero_num++;
            else if (mmap[s.at(j) - 'a'] == -1)
                zero_num--;
        }

        // start windowing
        int j = 0;
        while (1) {
            if (zero_num == 26) result.push_back(j);
            if (j + pl >= sl) break;
            if (++mmap[s.at(j) - 'a'] == 0)
                zero_num++;
            else if (mmap[s.at(j) - 'a'] == 1)
                zero_num--;
            if (--mmap[s.at(j + pl) - 'a'] == 0)
                zero_num++;
            else if (mmap[s.at(j + pl) - 'a'] == -1)
                zero_num--;
            j++;
        }

        return result;
    }
};
// @lc code=end
