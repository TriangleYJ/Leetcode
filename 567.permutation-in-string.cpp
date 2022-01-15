/*
 * @lc app=leetcode id=567 lang=cpp
 *
 * [567] Permutation in String
 */

// @lc code=start
class Solution {
   public:
    bool checkInclusion(string s1, string s2) {
        const int aa = 'a';
        const int s1l = s1.length();
        const int s2l = s2.length();

        if(s2l < s1l) return false;

        int mmap[26] = {0};

        for (char c : s1) mmap[c - aa]++;
        int srt = 0;

        //initalize
        for (int i = 0; i < s1l; i++) {
            mmap[s2.at(i) - aa]--;
        }

        int n_zero = 0;
        for(int i: mmap) if(i == 0) n_zero++;

        while (1) {
            // fixed window size = s1.length()
            // ei - id - db - ba - ao - oo - oo
            if(n_zero == 26) return true;
            if(srt + s1l >= s2l) break;
            int i_srt = s2.at(srt)-aa;
            int i_end = s2.at(srt+s1l)-aa;

            mmap[i_srt]++;
            if(mmap[i_srt] == 0) n_zero++;
            else if(mmap[i_srt] == 1) n_zero--;

            mmap[i_end]--;
            if(mmap[i_end] == 0) n_zero++;
            else if(mmap[i_end] == -1) n_zero--;

            srt++;
        }
        return false;
    }
};
// @lc code=end
