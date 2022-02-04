/*
 * @lc app=leetcode id=15 lang=cpp
 *
 * [15] 3Sum
 */

// @lc code=start
class Solution {
   public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;

        int s = nums.size();
        sort(nums.begin(), nums.end());

        const int N = 210000; // nums[i] <= 10^5
        int a = N, b = N;
        for(int i = 0; i < s; i++){
            if(a == nums.at(i)) continue;
            a = nums.at(i), b = N;
            for(int j = i+1; j < s; j++){
                if(b == nums.at(j)) continue;
                b = nums.at(j);
                int target = -(a+b);
                if(search(nums, target, j+1)) result.push_back({a, b, target});
            }
        }
        return result;
    }

    bool search(vector<int>& nums, int target, int start){
        int l = start;
        int r = nums.size() - 1;
        if(l > r) return false;
        while(l < r){
            int mid = (l + r) / 2;
            if(nums.at(mid) >= target) r = mid;
            else l = mid + 1;
        }
        return nums.at(l) == target;
    }
};
// @lc code=end
