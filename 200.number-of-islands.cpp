/*
 * @lc app=leetcode id=200 lang=cpp
 *
 * [200] Number of Islands
 */

// @lc code=start
class Solution {
   private:
    int h;
    int w;

   public:
    int numIslands(vector<vector<char>>& grid) {
        h = grid.size();
        w = grid.at(0).size();
        int ans = 0;

        for (int y = 0; y < h; y++) {
            for (int x = 0; x < w; x++) {
                if (grid.at(y).at(x) == '1') {
                    ans++;
                    spreadZero(x, y, grid);
                }
            }
        }
        return ans;
    }

    void spreadZero(int x, int y, vector<vector<char>>& grid) {
        grid.at(y).at(x) = '0';
        const bool edge[4] = {x == 0, x == w - 1, y == 0, y == h - 1};
        const int d[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        for (int i = 0; i < 4; i++) {
            int dx = x + d[i][0];
            int dy = y + d[i][1];
            if (!edge[i] && grid.at(dy).at(dx) == '1')
                spreadZero(dx, dy, grid);
        }
    }
};
// @lc code=end
