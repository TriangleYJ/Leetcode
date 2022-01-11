/*
 * @lc app=leetcode id=557 lang=cpp
 *
 * [557] Reverse Words in a String III
 */

// @lc code=start
class Solution {
public:
    string reverseWords(string s) {
        int srt = 0;
        for(int i = 0; i < s.size(); i++){
            char cur_c = s.at(i);
            if(cur_c == ' ' || i == s.size() - 1){
                if(i == s.size() - 1) i++;
                int end = i-1;
                while(srt < end){
                    char tmp = s.at(srt);
                    s.at(srt) = s.at(end);
                    s.at(end) = tmp;
                    srt++;
                    end--;
                }
                srt = i+1;
            }
        }

        return s;
    }
};
// @lc code=end

