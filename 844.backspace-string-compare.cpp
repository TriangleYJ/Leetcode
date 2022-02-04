/*
 * @lc app=leetcode id=844 lang=cpp
 *
 * [844] Backspace String Compare
 */

// @lc code=start
class Solution {
public:
    bool backspaceCompare(string s, string t) {
        int s_skip = 0;
        int t_skip = 0;
        int s_len = s.length();
        int t_len = t.length();
        int s_p = s_len - 1;
        int t_p = t_len - 1;

        while(1){
            while(1){
                while(s_p >= 0 && s.at(s_p) == '#'){
                    s_p--;
                    s_skip++;
                }
                if(s_skip == 0) break;
                s_p--;
                s_skip--;
            }

            while(1){    
                while(t_p >= 0 && t.at(t_p) == '#'){
                    t_p--;
                    t_skip++;
                }
                if(t_skip == 0) break;
                t_p--;
                t_skip--;
            }
            
            if(s_p < 0 && t_p < 0) return true;
            if(s_p < 0 || t_p < 0) return false;

            
            if(s.at(s_p--) != t.at(t_p--)) return false;
        }

        
    }
};
// @lc code=end

