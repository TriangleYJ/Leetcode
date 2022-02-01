/*
 * @lc app=leetcode id=190 lang=cpp
 *
 * [190] Reverse Bits
 */

// @lc code=start
class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        unsigned int ret = 0;
        for (int i = 0; i < 16; i++)
        {
            int front = (n & (1 << i)) >> i << (31-i);
            int back = (n & (1 << (31 - i))) >> (31 - i) << i;
            ret |= front;
            ret |= back;
        }
        return ret;
    }
};
// @lc code=end

