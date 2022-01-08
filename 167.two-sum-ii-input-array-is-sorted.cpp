/*
 * @lc app=leetcode id=167 lang=cpp
 *
 * [167] Two Sum II - Input Array Is Sorted
 */

// @lc code=start
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        // idea: find (target - i) in lg(n) time => O(nlogn)
        int l = numbers.size();
        for(int i = 0; i < l; i++){
            int obj = target - numbers.at(i);
            int st = i+1;
            int ed = l-1;
            while(st <= ed){
                int a = (st + ed) / 2;
                int va = numbers.at(a);
                if(va == obj) return {i+1, a+1};
                else if(va > obj) ed = a-1;
                else st = a+1;
            }
        }
        return {};
    }
};
// @lc code=end

