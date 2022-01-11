/*
 * @lc app=leetcode id=344 lang=cpp
 *
 * [344] Reverse String
 */

// @lc code=start
class Solution {
public:
    void reverseString(vector<char>& s) {
        int p = 0;
        int len = s.size();
        while(p <= len - p - 1){
            char tmp = s.at(p);
            s.at(p) = s.at(len - p - 1);
            s.at(len - p - 1) = tmp;
            p++;
        }
    }
};
// @lc code=end

