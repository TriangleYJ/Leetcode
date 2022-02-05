/*
 * @lc app=leetcode id=547 lang=cpp
 *
 * [547] Number of Provinces
 */

// @lc code=start
class Solution {
   private:
    int s;

   public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        s = isConnected.size();
        int ans = 0;
        for (int y = 0; y < s; y++) {
            if (isConnected.at(y).at(y) != -1) {
                ans++;
                excludeConnected(y, isConnected);
            }
        }
        return ans;
    }

    void excludeConnected(int p, vector<vector<int>>& isConnected) {
        if (isConnected.at(p).at(p) != -1) {
            isConnected.at(p).at(p) = -1;
            for (int i = 0; i < s; i++) {
                if (isConnected.at(p).at(i) == 1) excludeConnected(i, isConnected);
            }
        }
    }
};
// @lc code=end
