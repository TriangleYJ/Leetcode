/*
 * @lc app=leetcode id=278 lang=cpp
 *
 * [278] First Bad Version
 */

// @lc code=start
// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        // | o | o | o | x | x |
        // 0   1   2   3   4   5
        return firstBadVersion(0, n);
    }
    
    int firstBadVersion(int st, int ed){
        int pivot = st + (ed - st) / 2;
        int v1 = isBadVersion(pivot);
        int v2 = isBadVersion(pivot+1);
        if((!v1 && v2) || (ed - st) <= 1) return pivot+1; // o x
        else if(v1 && v2) return firstBadVersion(st, pivot);// x x 
        else if(!v1 && !v2) return firstBadVersion(pivot+1, ed);// o o
        else return -1; // x o (No case)
    }
};
// @lc code=end

