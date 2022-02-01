/*
 * @lc app=leetcode id=231 lang=cpp
 *
 * [231] Power of Two
 */

// @lc code=start
class Solution {
public:
    bool isPowerOfTwo(int n) {
        int cnt = 0;
        for (int i = 0; i < 31; i++)
        {
            cnt += n & 1;
            n >>= 1;
        }
        if(n & 1 == 1) return false; // if n is negative
        if(cnt == 1) return true;
        return false;
    }
};
// @lc code=end

