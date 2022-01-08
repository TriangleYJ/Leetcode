/*
 * @lc app=leetcode id=9 lang=cpp
 *
 * [9] Palindrome Number
 */

// @lc code=start
class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0) return false;
        if(x < 10) return true;
        int l = log10(x) + 1;
        for(int i = 1; i <= l / 2; i++){
            if(getNthNumber(x, i) != getNthNumber(x, l - i + 1)) return false;
        }
        return true;
    }

    int getNthNumber(int x, int pos){
        // gNN(1503, 3) = 5
        int ab = (x / pow(10, pos-1));
        return ab % 10;
    }
};
// @lc code=end

