/*
 * @lc app=leetcode id=139 lang=cpp
 *
 * [139] Word Break
 */

// @lc code=start
class Solution {
   public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int sl = s.length(), wl = wordDict.size();
        int main_p = 0;
        int word_p = 0;

        bool wordCandidate[1001] = {true};
        for (int i = 0; i < 1001; i++)
            wordCandidate[i] = true;
        while (main_p < sl) {
            char cur_c = s.at(main_p);
            bool candExist = false;
            bool endCond = false;
            for (int i = 0; i < wl; i++) {
                if (wordCandidate[i]) {
                    if (wordDict.at(i).at(word_p) != cur_c)
                        wordCandidate[i] = false;
                    else {  
                        candExist = true;
                        // fully matched word exists
                         if (word_p == wordDict.at(i).length() - 1){
                            endCond = true;
                            break;
                        }
                    }
                }
            }

            if(endCond){
                cout << cur_c << endl;
                for (int i = 0; i < 1001; i++)
                    wordCandidate[i] = true;
                word_p = 0;
            } else {    
                if (!candExist) return false;
                word_p++;
            }
            main_p++;
        }
        if(word_p == 0) return true;
        return false;
    }
};
// @lc code=end
